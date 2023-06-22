#include "sandpiles.h"
/**
 * stable - checks if a grid is greater than 3
 * @grid: Left 3x3 grid
 * Return: 1 on success 0 in !success
 */
int stable(int grid[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}
/**
 * sandpiles_sum - sandpiles sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	if (stable(grid1) == 0 || stable(grid2) == 0)
		return;
	add_function(grid1, grid2);

	while (stable(grid1) != 1)
	{
		printf("=\n");
		print_grid(grid1);
		permutation(grid1);
	}
}
/**
 * add_function - grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * Return: void
 */

void add_function(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}
/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * permutation - permutation
 * @grid1: Left 3x3 grid
*/
void permutation(int grid1[3][3])
{
	int i = 0;
	int j = 0;
	int externe[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1) >= 0 && (i - 1) < 3)
					externe[i - 1][j] += 1;
				if ((j - 1) >= 0 && (j - 1) < 3)
					externe[i][j - 1] += 1;
				if ((i + 1) >= 0 && (i + 1) < 3)
					externe[i + 1][j] += 1;
				if ((j + 1) >= 0 && (j + 1) < 3)
					externe[i][j + 1] += 1;
			}
		}
	}
	add_function(grid1, externe);
}
