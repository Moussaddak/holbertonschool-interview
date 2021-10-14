#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


void merge_sort(int *array, size_t size);
void split_merge(int *array, int *arr, int first, int last);
void merge(int *array, int *arr, int first, int mid, int last);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
