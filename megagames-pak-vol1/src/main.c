#include "main.h"

Label list_Game[NUM_GAMES] = {
		{"ANIMANIACS", &animaniacs, &animaniacs_dark, NULL, NULL, 0, 0, 0x10},
		{"GOOFY'S HYSTERICAL HISTORY TOUR", &goofys, &goofys_dark, NULL, NULL, 0, 0, 0x18},
		{"M.U.S.H.A", &musha, &musha_dark, NULL, NULL, 0, 0, 0x08},
		{"QUACKSHOT STARRING DONALD DUCK", &quack_shot, &quack_shot_dark, NULL, NULL, 0, 0, 0x0C},
		{"RAMBO III", &rambo_3, &rambo_3_dark, NULL, NULL, 0, 0, 0x02},
		{"THE FLINTSTONES", &flintstones, &flintstones_dark, NULL, NULL, 0, 0, 0x04},
};

int main() {

	segaLogo();

	XGM_setLoopNumber(-1);
	XGM_setPCM(SFX_MOVE_SOUND, sfx_move, sizeof(sfx_move));

	SYS_setVBlankCallback(&flashBSCallback);
	VDP_setHorizontalScroll(BG_A, -96);
	VDP_loadFont(&font_menu, DMA);

	PAL_setPalette(PAL0, background.palette->data, DMA);
	list_Game[currentIndex].num_palette = PAL1;
	list_Game[frontIndex].num_palette = PAL2;
	list_Game[rearIndex].num_palette = PAL3;

	ind[0] = TILE_USER_INDEX;
	VDP_loadTileSet(background.tileset, ind[0], DMA);
	ind[1] = ind[0] + background.tileset->numTile;
	VDP_loadTileSet(game_select.tileset, ind[1], DMA);
	ind[2] = ind[1] + game_select.tileset->numTile;
	VDP_loadTileSet(button_select.tileset, ind[2], DMA);

	list_Game[0].tile_index = ind[2] + button_select.tileset->numTile;
	VDP_loadTileSet(list_Game[0].image->tileset, list_Game[0].tile_index, DMA);
	for (u8 i = 1; i < NUM_GAMES; ++i) {
		list_Game[i].tile_index = list_Game[i - 1].tile_index + list_Game[i - 1].image->tileset->numTile;
		VDP_loadTileSet(list_Game[i].image->tileset, list_Game[i].tile_index, DMA);
	}

	VDP_setTileMapEx(BG_B, background.tilemap, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, ind[0]), 0, 0, 0, 0, 40, 28, DMA);
	VDP_setTileMapEx(BG_A, game_select.tilemap, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, ind[1]), 27, 2, 0, 0, 11, 2, DMA);

	VDP_drawText("SELECT CURSOR - LEFT or RIGHT BUTTON", 14, 24);
	VDP_drawText("SELECT GAME   - START BUTTON", 14, 26);

	drawLabel(POSX_CURRENT_CELL, POSY_ALL_CELL, currentIndex);
	drawLabel(POSX_LEFT_CELL, POSY_ALL_CELL, rearIndex);
	drawLabel(POSX_RIGHT_CELL, POSY_ALL_CELL, frontIndex);
	drawTitleLabel(currentIndex);

	XGM_startPlay(xgm_chippin);

	while (TRUE) {
		handleInput();
		SYS_doVBlankProcess();
	}
}

void handleInput() {
	u16 player1 = JOY_readJoypad(JOY_1);
	u16 player2 = JOY_readJoypad(JOY_2);
	if (player1 == BUTTON_LEFT || player2 == BUTTON_LEFT) {
		XGM_startPlayPCM(SFX_MOVE_SOUND, 15, SOUND_PCM_CH4);
		moveLeft();
	} else if (player1 == BUTTON_RIGHT || player2 == BUTTON_RIGHT) {
		XGM_startPlayPCM(SFX_MOVE_SOUND, 15, SOUND_PCM_CH4);
		moveRight();
	} else if (player1 == BUTTON_START || player2 == BUTTON_START) {
		selectGame(currentIndex);
	}
}

void moveLeft() {
	directionOfLabel = MOVE_TO_LEFT;
	moveLabels();
	(currentIndex < NUM_GAMES - 1) ? currentIndex++ : (currentIndex = 0);
	u8 tempNumPalette = list_Game[rearIndex].num_palette;
	setIndex();
	list_Game[frontIndex].num_palette = tempNumPalette;
	list_Game[frontIndex].posX = POSX_BACK_RIGHT;
	list_Game[frontIndex].posY = POSY_ALL_CELL;
	moveOnLabel(frontIndex);
	drawTitleLabel(currentIndex);
}

void moveRight() {
	directionOfLabel = MOVE_TO_RIGHT;
	moveLabels();
	(currentIndex > 0) ? currentIndex-- : (currentIndex = NUM_GAMES - 1);
	u8 tempNumPalette = list_Game[frontIndex].num_palette;
	setIndex();
	list_Game[rearIndex].num_palette = tempNumPalette;
	list_Game[rearIndex].posX = POSX_BACK_LEFT;
	list_Game[rearIndex].posY = POSY_ALL_CELL;
	moveOnLabel(rearIndex);
	drawTitleLabel(currentIndex);
}

void selectGame(u8 index) {
	XGM_stopPlay();
	waitMs(100); waitMs(1);
	trampoLine(addrPort, list_Game[index].callAddress);
}

void flashBSCallback() {
	frame_count++;
	if (frame_count == 15) {
		VDP_setTileMapEx(BG_A, button_select.tilemap, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, ind[2]), 23, 21, 0, 0, 18, 2, DMA);
	} else if (frame_count == 30) {
		VDP_clearTileMapRect(BG_A, 23, 21, 18, 2);
		frame_count = 0;
	}
}

void drawLabel(u16 posX, u16 posY, u8 index){
	VDP_clearTileMapRect(BG_A, list_Game[index].posX, list_Game[index].posY, 10, 10);
	if (posX == POSX_CURRENT_CELL) {
		PAL_setPalette(list_Game[index].num_palette, list_Game[index].image->palette->data, DMA);
	} else {
		PAL_setPalette(list_Game[index].num_palette, list_Game[index].palette_dark->data, DMA);
	}
	VDP_setTileMapEx(BG_A, list_Game[index].image->tilemap, TILE_ATTR_FULL(list_Game[index].num_palette, 0 , FALSE, FALSE, list_Game[index].tile_index), posX, posY, 0, 0, 10, 10, DMA);
	list_Game[index].posX = posX;
	list_Game[index].posY = posY;
}

void moveOnLabel(u8 index){
	u8 i = 0;
	do {
		drawLabel(list_Game[index].posX + 1 * directionOfLabel, list_Game[index].posY, index);
		i++;
		SYS_doVBlankProcess();
	} while (i != MOVE_LENGHT);
}

void moveLabels(){
	(directionOfLabel == MOVE_TO_LEFT) ? moveOnLabel(rearIndex) : moveOnLabel(frontIndex);
	moveOnLabel(currentIndex);
	(directionOfLabel == MOVE_TO_LEFT) ? moveOnLabel(frontIndex) : moveOnLabel(rearIndex);
}

void setIndex(){
	if (currentIndex == 0) {
		rearIndex = NUM_GAMES - 1; frontIndex = currentIndex + 1;
	} else if (currentIndex == NUM_GAMES - 1) {
		rearIndex = currentIndex - 1; frontIndex = 0;
	} else {
		rearIndex = currentIndex - 1;
		frontIndex = currentIndex + 1;
	}
}

void drawTitleLabel(u8 index){
	VDP_clearTextLine(6);
	u16 lenText = strlen(list_Game[index].namelabel) / 2;
	VDP_drawText(list_Game[index].namelabel, 32 - lenText, 6);
}

void trampoLine(u32 address, u8 data) {
	__asm__ volatile(
// this function copies itself into RAM at $FFFF8000 and then jumps to it
// the passed in parameter is which game to run (0, 1, ... n) which is used to
// set the correct bank - note: never returns

			"move.l #.1%=, %%d0	          \n\t "// start address
			"movea.l %%d0, %%a0           \n\t "
			"move.l #.2%=-.1%=, %%d1	  \n\t "// number of bytes
			"lsr.l #0x2, %%d1	          \n\t "// divide by 4 for words
			"addq #0x1, %%d1		      \n\t "// and account for potential partial words (probably unneeded but wont hurt)
			"movea.l #0xFFFF8000, %%a1    \n\t "// target RAM address 0xFFFF8000
			"movea.l %%a1, %%a2	          \n\t "// save the address

		".3%=:                            \n\t "
			"move.l (%%a0)+, (%%a1)+      \n\t "// copy 32-bits
			"dbf %%d1, .3%=		          \n\t "// loop until done
			"jmp (%%a2)			          \n\t "// execute the code from RAM

// the following code runs from RAM, [DATA] has the program number
		".1%=:	                          \n\t "
			"move.w %[DATA], %%d2         \n\t "
			"moveq #0, %%d1 	          \n\t "// prepare to zero
			"move.w %%d2, %%d1		      \n\t "// now we know its saf
			"movea.l %[ADDR], %%a0	      \n\t "// this is the address we will poke
			"move.b %%d1, (%%a0)	      \n\t "// do the poke (value irrelevant, byte by tradition)

			"clr.l 0xA10008		          \n\t "// at least, uses these registers to decide whether to do a full init!
			"clr.w 0xA1000C		          \n\t "// zeroing them should force a proper initialization

		".4%=:                            \n\t "
			"moveq #0, %%d0               \n\t "// cart should be active, so prepare to jump
			"movea.l %%d0, %%a0           \n\t "// read from reset vector
			"movea.l (%%a0)+, %%sp        \n\t "// set stack pointer
			"movea.l (%%a0)+, %%a0        \n\t "// get boot address
			"move.w #0x2700, %%sr	      \n\t "// disable interrupts
			"jmp (%%a0)                   \n\t "// and go do it
			"nop                          \n\t "

		".2%=:	                          \n\t "
			"nop                          \n\t "

			:: [ADDR] "r" (address), [DATA] "r" (data)
			: "%a0", "%a1", "%a2", "%d0", "%d1", "%d2"
	);
}
