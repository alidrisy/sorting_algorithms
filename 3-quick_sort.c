#include "sort.h"

/**
* quicksort -  sorts an array of integers in ascending order
* using the Quick sort algorithm.
* @array: an array of element to be sort
* @lo: low number of value
* @hi: hight number of value
* Return: the index of the hight value
*/

int quick_partition(int *array, int lo, int hi)
{
int pi = array [hi];
int i = lo - 1;
int s, j;

s = 0;
for (j = lo; j < hi; j++)
{
if (array[j] <= pi)
{
i += 1;
s = array[i];
array[i] = array[j];
array[j] = s;
}
}
i += 1;
s = array[i];
array[i] = array[hi];
array[hi] = s;
return (i);
}

/**
* quicksort -  sorts an array of integers in ascending order
* using the Quick sort algorithm.
* @array: an array of element to be sort
* @size: size of array
* @lo: low number of value
* @hi: hight number of value
*/

void quicksort(int *array, int lo, int hi, int size)
{
int j, l, h;

l = lo;
h = hi;

if (lo >= hi || lo < 0)
return;
j = quick_partition(array, l, h);
print_array(array, size);
quicksort(array, l, j-1, size);
quicksort(array, j+1, h, size);
}

/**
* quick_sort -  sorts an array of integers in ascending order
* using the Quick sort algorithm.
* @array: an array of element to be sort
* @size: size of array
*/

void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quicksort(array, 0, size - 1, size);
}
