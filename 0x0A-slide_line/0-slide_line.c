#include "slide_line.h"
void swap_left(int *line, size_t size);
void swap_right(int *line, size_t size);
/**
 * slide_line - slides and merges an array of integers
 * @line: Pointer to the array of integer
 * @size: Number of elements in line
 * @direction: can be SLIDE_LEFT or SLIDE_RIGHT
 * Return: 0 or 1
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	switch (direction)
	{

		case SLIDE_LEFT:
			swap_left(line, size);
			for (i = 0; i < size; i++)
				if (line[i] == line[i + 1])
				{
					line[i] += line[i + 1];
					line[i + 1] = 0;
				}

			swap_left(line, size);
			return (1);
		case SLIDE_RIGHT:
			swap_right(line, size);
			for (i = size - 1; i != 0; i--)
				if (line[i] == line[i - 1])
				{
					line[i] += line[i - 1];
					line[i - 1] = 0;
				}
			swap_right(line, size);
			return (1);
	}
	return (0);
}

/**
 * swap_right - slides a line to the right
 * @line: points to an array of integers
 * @size: size of array
 */
void swap_right(int *line, size_t size)
{
	size_t i;

	for (i = size - 1; i != 0; i--)
	{
		if (!line[i] && line[i - 1])
		{
			line[i] = line[i - 1];
			line[i - 1] = 0;
			for (i = size - 1; i != 0; i--)
				if (line[i] == 0)
					break;
			i++;
		}
	}
}

/**
 * swap_left - slides a line to the left
 * @line: points to an array of integers
 * @size: size of array
 */
void swap_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (!line[i]  && line[i + 1])
		{
			line[i] = line[i + 1];
			line[i + 1] = 0;
			for (i = 0; i < size; i++)
				if (!line[i])
					break;
			i--;
		}
	}
}
