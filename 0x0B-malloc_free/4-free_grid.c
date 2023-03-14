#include <stdlib.h>
#include "main.h"
/**
 * free_grid - frees 2D array
 * @grid: grid from the 2D array
 * @height: height of grid
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
