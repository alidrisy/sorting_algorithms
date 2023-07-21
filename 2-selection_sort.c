#include "sort.h"

/**
* selection_sort -  sorts an array of integers in ascending order
* using the Selection sort algorithm.
* @array: an array of element to be sort
* @size: size of array
*/

void selection_sort(int *array, size_t size)
{
	size_t x, i, n, j;

	for (i = 0; i < size; i++)
	{
		n = i;
		for (x = i + 1; x < size; x++)
		{
			if (array[x] < array[n])
				n = x;
		}
		if (n != i)
		{
			j = array[i];
			array[i] = array[n];
			array[n] = j;
			print_array(array, size);
		}
	}
}
