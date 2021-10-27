/*
	* CODE MAIN
	* Author : Jonas S.
	* Date   : 27/10/2021
	! Game of life
	! Source 
*/



#include <stdio.h>
#include "raylib.h"
#include <time.h>
#include "../include/life.h"


int main()
{	
	srand(time(NULL));

	InitWindow(WORLD_WIDTH, WORLD_HEIGHT, "Game of life");	
	SetTargetFPS(15);

	// ! INIT WOLRD
	World w1 = {.w = WORLD_WIDTH / CELL_SIZE, .h=WORLD_HEIGHT / CELL_SIZE};
	
	// INIT CELLS as randomly active or not
	for (uint64_t x = 0; x < w1.w; x++)
	{
		for (uint64_t y = 0; y < w1.h; y++)
		{
			w1.cells[x][y] = (Cell){	.x = x,
										.y = y,
										.active= rand() % 2,
									};
		}
	}

	w1.cells[0][0].active = true;

	while (!WindowShouldClose())
	{
		BeginDrawing(); // ! DRAWING
		DrawFPS(10, 10); 
		ClearBackground(COLOR_INACTIVE);

		showWorld(w1);
		processWorld(&w1, w1);

		EndDrawing(); // ! END DRAWING
	}
	CloseWindow();

}
