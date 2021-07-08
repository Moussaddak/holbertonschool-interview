#include "menger.h"

/**
 * insertChar - Special function
 * @i: row
 * @j: column
 *
 * Return: "#" or " "
 */
char insertChar(int i, int j)
{
	while (i || j)
	{
		if (j % 3 == 1 && i % 3 == 1)
			return (' ');
		i = i / 3;
		j = j / 3;
	}
	return ('#');
}

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 *
 * Return: Nothing.
 */
void menger(int level)
{
	int i, j, num;

	if (level < 0)
		return;
	num = pow(3, level);
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
			printf("%c", insertChar(i, j));
		printf("%c", '\n');
	}
}
