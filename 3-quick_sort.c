#include "sort.h"
#include <math.h>

/**
* quick_partition -  sorts an array of integers in ascending order
* using the Quick sort algorithm.
* @array: an array of element to be sort
* @lo: low number of value
* @hi: hight number of value
* Return: the index of the hight value
*/

int quick_partition(int *array, int lo, int hi)
{
int a = truncf(((hi - lo) / 2) + lo);
int piv = array [a];
int i = lo - 1;
int s, j;

j = hi + 1;
s = 0;
while(1)
{
do
{
i += 1;
}
while (array[i] < piv);
do
{
j -= 1;
}
while (array[j] > piv);
if (i >= j)
return j;

s = array[i];
array[i] = array[j];
array[j] = s;
}
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

if (lo >= 0 && hi >= 0 && lo < hi)
{
j = quick_partition(array, lo, hi, size);
print_array(array, size);
quicksort(array, lo, j, size);
quicksort(array, j + 1, hi, size);
}
}

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
