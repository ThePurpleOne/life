/*
	* HEADER CELL
	* Author : Jonas S.
	* Date   : 27/10/2021
	! DESCRIPTION
*/

#ifndef _LIFE_H_
#define _LIFE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "raymath.h"

// DEFINES
#define CELL_SIZE 25
#define WORLD_WIDTH 1000
#define WORLD_HEIGHT 1000
#define COLOR_ACTIVE (Color){108, 92, 231, 255}
#define COLOR_INACTIVE (Color){223, 230, 233, 50}

// STRUCT
typedef struct
{
	uint64_t x, y;
	bool active;
}Cell;

typedef struct
{
	uint64_t w, h;
	Cell cells[WORLD_WIDTH / CELL_SIZE][WORLD_HEIGHT / CELL_SIZE];
}World;

// PROTOTYPE FUNCTIONS
void showCell(Cell c);
void showWorld(World w);
uint8_t countNeighbors(World w, Cell c);
void processWorld(World  * w, World wCopied);

#endif