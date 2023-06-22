#include "slide_line.h"
/**
 * slide_line - a function that slides and merges an array of integers
 * @line: a line
 * @size: size of array
 * @direction: direction
 * Return: 1 or 0
*/
int slide_line(int *line, size_t size, int direction){

	int a = size, i = 0, j = 0, x;
	int new_line[32];


	for (i = 0; i < 32; i++)
		new_line[i] = 0;
	if (direction == SLIDE_LEFT){
		x = line[0];
		j = 0;
		new_line[j] = x;
		for (i = 1; i < a; i++){
			if (line[i] == x && line[i] != 0){
				new_line[j] = x * 2;
				x = 0;
				j++;
			}
			else if (line[i] != 0 && 0 != new_line[j]){
				j++;
				x = line[i];
				new_line[j] = x;
			}
			else if (line[i] != 0){
				x = line[i];
				new_line[j] = x;
			}
		}
	}
	else if (direction == SLIDE_RIGHT){
		x = line[size - 1];
		j = size - 1;
		new_line[j] = x;
		for (i = size - 2; i >= 0; i--){
			if (line[i] == x && line[i] != 0){
				newline[j] = x * 2;
				x = 0;
				j--;
			}
			else if (line[i] != 0 && 0 != new_line[j]){
				j--;
				x = line[i];
				new_line[j] = x;
			}
			else if (line[i] != 0){
				x = line[i];
				new_line[j] = x;
			}
		}
	}
	else
		return (0);
	for (i = 0; i < a; i++){
		line[i] = new_line[i];
	}
	return (1);
}
