#include "sega_logo.h"

u16 curentPalette[16];
u16 bufferPalette[8];

void rightRotatebyOne(){
	u16 temPalette = curentPalette[10];
	for (u8 i = 10; i > 2; i--) {
		curentPalette[i] = curentPalette[i - 1];
	}
	SYS_doVBlankProcess();
	curentPalette[2] = bufferPalette[7];
	for (u8 i = 7; i > 1; i--) {
		bufferPalette[i] = bufferPalette[i - 1];
	}
	bufferPalette[1] = temPalette;
	SYS_doVBlankProcess();
}

void rightRotateby(u8 n){
	for (u8 i = 0; i < n; ++i) {
		rightRotatebyOne();
		PAL_setPalette(PAL1, curentPalette, DMA);
	}
}

void segaLogo() {

	u16 ind = TILE_USER_INDEX;

	XGM_setPCM(64, sega_sfx, sizeof(sega_sfx));
	PAL_setPalette(PAL1, logo_sega.palette->data, DMA);

	memcpy(&curentPalette, logo_sega.palette->data, 16 * 2);
	memcpy(&bufferPalette, buffer_palette.data, 8 * 2);
	waitMs(500);
	VDP_drawImageEx(BG_A, &logo_sega, TILE_ATTR_FULL(PAL1, 0, 0, 0, ind), 0, 0, 0, DMA);
	waitMs(500);

	rightRotateby(16);

	XGM_startPlayPCM(64, 15, SOUND_PCM_CH2);
	waitMs(1500);
	PAL_fadeOutPalette(PAL1, 25, FALSE);
	VDP_clearPlane(BG_A, 1);
}
