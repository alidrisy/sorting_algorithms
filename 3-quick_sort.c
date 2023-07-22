#include "sort.h"

void quicksort(int *array, int lo, int hi, int size);

/**
* quick_sort -  sorts an array of integers in ascending order
* using the Quick sort algorithm.
* @array: an array of element to be sort
* @size: size of array
*/

void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

quicksort(array, 0, size - 1, size);
}

/**
* quick_partition -  sorts an array of integers in ascending order
* using the Quick sort algorithm.
* @array: an array of element to be sort
* @size: size of array
* @lo: low number of value
* @hi: hight number of value
* Return: the index of the hight value
*/

int quick_partition(int *array, int lo, int hi, int size)
{
int piv = array[hi];
int i = lo;
int s, j;

s = 0;

for (j = lo; j < hi; j++)
{
if (array[j] <= piv)
{
s = array[i];
array[i] = array[j];
array[j] = s;
if (s != array[i])
print_array(array, size);
i++;
}
}
s = array[i];
array[i] = array[hi];
array[hi] = s;
if (s != array[i])
print_array(array, size);

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
int j;

if (lo < hi)
{
j = quick_partition(array, lo, hi, size);
quicksort(array, lo, j - 1, size);
quicksort(array, j + 1, hi, size);
}
}

