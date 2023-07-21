#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order
* @array: an array of element to be sort
* @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	int x, i, y, n;

	x = 0;
	y = 1;
	n = size;
	while (n > 1)
	{
		y = 0;
		for (x = 0; x < n; x++)
		{
			if (array[x - 1] > array[x])
			{
				i = array[x];
				array[x] = array[x - 1];
				array[x - 1] = i;
				y = x;
				print_array(array, size);
			}
		}
		n = y;
	}
}
