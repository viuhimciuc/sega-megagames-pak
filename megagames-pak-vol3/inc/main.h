/*
 * main.h
 *
 *  Created on: Oct 13, 2024
 *      Author: viuhi
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_

#include "genesis.h"
#include "resources.h"
#include "sega_logo.h"

#define NUM_GAMES 6
#define POSX_CURRENT_CELL 27
#define POSY_ALL_CELL 9
#define MOVE_LENGHT 13

#define POSX_LEFT_CELL (POSX_CURRENT_CELL - MOVE_LENGHT)
#define POSX_RIGHT_CELL (POSX_CURRENT_CELL + MOVE_LENGHT)
#define POSX_BACK_LEFT (POSX_LEFT_CELL - MOVE_LENGHT)
#define POSX_BACK_RIGHT (POSX_RIGHT_CELL + MOVE_LENGHT)

#define MOVE_TO_LEFT -1
#define MOVE_TO_RIGHT 1
#define SFX_MOVE_SOUND 64

void handleInput();
void flashBSCallback();
void drawLabel(u16 posX, u16 posY, u8 index);
void drawTitleLabel(u8 index);
void moveOnLabel(u8 index);
void moveLabels();
void moveLeft();
void moveRight();
void setIndex();
void selectGame(u8 index);
void trampoLine(u32 address, u8 data);

typedef struct {
	char namelabel[40];
	const Image *image;
	const Palette *palette_dark;
	u8 num_palette;
	u16 tile_index;
	u16 posX;
	u16 posY;
	u16 callAddress;
} Label;

u8 currentIndex = 0;
u8 rearIndex = NUM_GAMES - 1;
u8 frontIndex = 1;
u16 ind[3] = {0, 0, 0};
u16 frame_count = 0;
s8 directionOfLabel = 0;
u32 addrPort = 0xA13005;

#endif /* INC_MAIN_H_ */
