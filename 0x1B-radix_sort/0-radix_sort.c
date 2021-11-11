#include "sort.h"
/**
 * len - checks max element and count it's digits
 * @array: pointer to first element of array
 * @size: size of array
 * Return: integer maximum number of digits
 */
int len(int *array, size_t size)
{
	int i, j, n = 0;

	for (i = 0; i < (int)size; ++i)
		if (array[i] > n)
			n = array[i];
	for (j = 0; n >= 1; ++j)
		n = n / 10;

	return (j);
}
/**
 * radix_sort - sorts an array using Radix sort algorithm
 * @array: pointer integer, first element of array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int BB[100][100], B[100];
	int i, j, k, r, c, max, div = 1;

	if (!array || size < 2)
		return;

	max = len(array, size);
	for (c = 0; c < max; c++)
	{
		for (i = 0; i < 100; i++)
			B[i] = 0;

		for (i = 0; i < (int)size; i++)
		{
			r = (array[i] / div) % 10;
			BB[r][B[r]] = array[i];
			B[r] += 1;
		}
		i = 0;
		for (k = 0; k < 100; k++)
		{
			for (j = 0; j < B[k]; j++)
			{
				array[i] = BB[k][j];
				i++;
			}
		}
		div *= 10;
		print_array(array, size);
	}
}
