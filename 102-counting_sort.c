#include "sort.h"

/**
* counting_sort - sorts an array of integers in ascending order
* @array: an array of element to be sort
* @size: size of array
*/

void counting_sort(int *array, size_t size)
{
int i, x, v, s;
int *output, *count;

s = size;
v = 1;
output = malloc(sizeof(size));
for (i = 0; i < s; i++)
{
if (array[i] > v)
v = array[i];
}

count = malloc(sizeof(v + 1));
for (i = 0; i <= v; i++)
count[i] = 0;

for (i = 0; i < s; i++)
{
x = array[i];
count[x] = count[x] + 1;
}

for (i = 1; i <= v; i++)
count[i] += count[i - 1];

print_array(count, v + 1);

for (i = s - 1; i >= 0; i--)
{
x = array[i];
count[x] = count[x] - 1;
output[count[x]] = array[i];
}

for(i = 0; i < s; i++)
array[i] = output[i];

free(output);
free(count);
}
