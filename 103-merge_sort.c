#include "sort.h"

void merge(int *arcopy, int Begin, int Middle, int End, int *array);
void split_merge(int *B, int lo, int hi, int *A);
void display(int A[], int lo, int hi);

/**
* merge_sort -  sorts an array of integers in ascending order
* using the Quick sort algorithm.
* @array: an array of element to be sort
* @size: size of array
*/

void merge_sort(int *array, size_t size)
{
int *arcopy;
int i;

arcopy = malloc(sizeof(int) * size);
for (i = 0; i < (int) size; i++)
arcopy[i] = array[i];

split_merge(array, 0, size, arcopy);
free(arcopy);
}

/**
* split_merge -  spilt the arrays
* @A: an array of element to be sort
* @B: a copy of the array of element to be sort
* @lo: low number of value
* @hi: hight number of value
*/

void split_merge(int *B, int lo, int hi, int *A)
{
int Middle;

if (hi - lo <= 1)
return;

Middle = (hi + lo) / 2;
split_merge(A, lo,  Middle, B);
split_merge(A, Middle, hi, B);
printf("Merging...\n");
printf("[left]: ");
display(A, lo, Middle);
printf("[right]: ");
display(A, Middle, hi);
merge(B, lo, Middle, hi, A);
printf("[Done]: ");
display(B, lo, hi);
}

/**
* display -  print the element of the array
* @A: an array of element to be printed
* @lo: low number of value
* @hi: hight number of value
*/

void display(int *A, int lo, int hi)
{
int k;

for (k = lo; k < hi; k++)
{
printf("%d", A[k]);
if (k != hi - 1)
printf(", ");
}
printf("\n");
}

/**
* merge -  merge subarrays
* @array: an array of element to be sort
* @arcopy: a copy of the array of element to be sort
* @Begin: low number of value
* @End: hight number of value
* @Middle: Middle number of value
*/

void merge(int *arcopy, int Begin, int Middle, int End, int *array)
{
int i = Begin, j = Middle;
int k;
for (k = Begin; k < End; k++)
{
if (i < Middle && (j >= End || array[i] <= array[j]))
{
arcopy[k] = array[i];
i = i + 1;
}
else
{
arcopy[k] = array[j];
j = j + 1;
}
}
}
