/*
	* CODE LIFE
	* Author : Jonas S.
	* Date   : 27/10/2021
	! DESCRIPTION
*/

#include "../include/life.h"

#include <string.h>

/**
 * @brief Show a given cell
 *
 * @param c
 */
void showCell(Cell c)
{
	Color color_;
	if (c.active)
	{
		color_ = COLOR_ACTIVE;
		DrawRectangleRec(
		  (Rectangle){
			.x		= c.x * CELL_SIZE,
			.y		= c.y * CELL_SIZE,
			.width	= CELL_SIZE,
			.height = CELL_SIZE,
		  },
		  color_);
	}
	// else{color_ = COLOR_INACTIVE;}

	// DrawRectangleRec((Rectangle){	.x=c.x *  CELL_SIZE,
	// 								.y=c.y *  CELL_SIZE,
	// 								.width  = CELL_SIZE,
	// 								.height = CELL_SIZE,
	// 							}, color_);
}

/**
 * @brief Show the whole world
 *
 * @param w
 */
void showWorld(World w)
{
	for (uint64_t x = 0; x < w.w; x++)
	{
		for (uint64_t y = 0; y < w.h; y++)
		{
			showCell(w.cells[x][y]);
		}
	}
}

/**
 * @brief Count the active neighbors
 *
 * @param w World struct
 * @param c Cell Struct
 */
uint8_t countNeighbors(World w, Cell c)
{
	uint8_t neighborsCount = 0;
	int64_t row, col;
	uint8_t res = WORLD_WIDTH / CELL_SIZE;
	// Loop a subsection Square of 3x3 from -1 0 1
	// Cells coordinates need to be relative to c coordinates
	// Want it to wrap around - Shift everything by WIDTH and modulo
	// c.x > 0 .. WORLD_WIDTH
	// c.y > 0 .. WORLD_HEIGHT
	// x = y > -1 .. 1

	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			col = (c.x + x + res) % res;
			row = (c.y + y + res) % res;
			neighborsCount += w.cells[col][row].active;
		}
	}

	// Remove itself cause it's counted
	neighborsCount -= w.cells[c.x][c.y].active;
	return neighborsCount;
}

/**
 * @brief Process every cell with Rules
 *
 * @param w Pointer to World struct
 * @param wCopied Copy of 2d tab
 */
void processWorld(World* w, World wCopied)
{
	// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
	// Any live cell with two or three live neighbours lives on to the next generation.
	// Any live cell with more than three live neighbours dies, as if by overpopulation.
	// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

	uint8_t	 n;
	Cell*	 pc;
	uint32_t killed	 = 0;
	uint32_t spawned = 0;
	uint32_t kept	 = 0;

	for (uint64_t x = 0; x < w->w; x++)
	{
		for (uint64_t y = 0; y < w->h; y++)
		{
			pc = &w->cells[x][y];			   // pointer Cell
			n  = countNeighbors(wCopied, *pc); // Read from copied world

			// Change States
			if (pc->active && (n < 2))
			{
				pc->active = false;
				killed++;
			} // Underpopulation
			else if (pc->active && (n > 3))
			{
				pc->active = false;
				killed++;
			} // Overpopulation
			else if (pc->active && ((n == 2) || (n == 3)))
			{
				pc->active = true;
				kept++;
			} // Normal
			else if ((pc->active == false) && (n == 3))
			{
				pc->active = true;
				spawned++;
			} // Reproduction
		}
	}
	// printf("Killed %d cells \n", killed );
	// printf("Spawn  %d cells \n", spawned );
	// printf("Kept   %d cells \n", kept );
	// printf("\n\n");
}
