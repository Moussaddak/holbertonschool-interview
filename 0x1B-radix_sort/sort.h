#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int len(int *array, size_t size);

#endif /* SORT_H */
