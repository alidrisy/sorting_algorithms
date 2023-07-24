#include "sort.h"

/**
* shell_sort - sorts an array of integers in ascending order
* @array: an array of element to be sort
* @size: size of array
*/

void shell_sort(int *array, size_t size)
{
int k, s, i, x, gap;

i = size;
gap = 1;

while (gap < (int) size/3)
gap = gap * 3 + 1;

while (gap > 0)
{
for (s = gap; s < i; s++)
{
for (x = s - gap; x >= 0; x -= gap)
{
if (array[x + gap] >= array[x])
break;
else
{
k = array[x];
array[x] = array[x + gap];
array[x + gap] = k;
}
}
}
gap = (gap - 1) / 3;
print_array(array, size);
}
}
