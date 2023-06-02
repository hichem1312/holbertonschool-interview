#include "slide_line.h"
#define LINE_SIZE   32
/**
*left_direction -  a function that slides and merges an array of integers
*@line: pointer
*@size: size of array
**/
void left_direction(int *line, size_t size)
{
size_t a = 0, b, i;
int j, k = 0;
int T[LINE_SIZE], T1[LINE_SIZE];
for (i = 0; i < size; i++)
{
	if (line[i] != 0)
	{
		T[k] = line[i];
		k++;
	}
}
for (j = 0; j < k; j += 1)
{
	if (T[j] == T[j + 1])
	{
		T1[a] = T[j] * 2;
		j++;
		a++;
	}
	else
	{
		T1[a] = T[j];
		a++;
	}
}
for (b = 0; b < size; b++)
{
	if (b < a)
		line[b] = T1[b];
	else
		line[b] = 0;
}
}
/**
*right_direction -  a function that slides and merges an array of integers
*@line: a pointer
*@size: size of array
**/
void right_direction(int *line, size_t size)
{
size_t  a = 0, v = 0;
int k = 0, j, b, i;
int T[LINE_SIZE], T1[LINE_SIZE];
for (i = size - 1; i > -1; i--)
{
	if (line[i] != 0)
	{
		T[k] = line[i];
		k++;
	}
}
for (j = 0; j < k; j += 1)
{
	if (T[j] == T[j + 1])
	{
		T1[a] = T[j] * 2;
		j++;
		i++;
	}
	else
	{
		T1[i] = T[j];
		i++;
	}
}
for (b = size - 1; b > -1; b--)
{
	if (v < a)
	{
		line[b] = T1[v];
		v++;
	}
	else
		line[b] = 0;
}
}
/**
*slide_line -  a function that slides and merges an array of integers
*@line: pointer
*@size: size of array
*@direction: the direction
*Return: 1
**/
int slide_line(int *line, size_t size, int direction)
{
if (direction == SLIDE_LEFT)
{
	left_direction(line, size);
	return (1);
}
else if (direction == SLIDE_RIGHT)
{
	right_direction(line, size);
	return (1);
}
return (0);
}