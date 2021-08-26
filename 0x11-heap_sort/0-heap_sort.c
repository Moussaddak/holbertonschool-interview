#include "sort.h"

/**
 * swap - swithces two elements in array
 * @a: integer
 * @b: integer
 * Return: none
 */

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * doHeap - create binary heap
 * @table: array
 * @n: int
 * @i: int
 * @size: size_t
 * 
 */

void doHeap(int table[], int n, int i, size_t size)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (right < n && table[right] > table[max])
		max = right;

	if (left < n && table[left] > table[max])
		max = left;

	if (max != i)
	{
		swap(&table[i], &table[max]);
		print_array(table, size);
		heapify(table, n, max, size);
	}
}


/**
 * heap_sort - heap sort
 * @array: array to be sorted
 * @size: size of array
 *
 */

void heap_sort(int *array, size_t size)
{
	int i, n = size;

	for (i = n / 2 - 1; i >= 0; i--)
		doHeap(array, n, i, size);

	for (i = n - 1; i >= 0; i--)
	{
		if (i != 0)
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
			doHeap(array, i, 0, size);
		}
	}
}