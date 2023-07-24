#include "sort.h"

/**
 * get_maxex - get a maximum In array of integ, find the highe value.
 * @array: An array a collection of integers.
 * @size: The size a collection of integers.
 * Return: The array's biggest integer is.
 */
int get_maxex(int *array,
int size)
{
int mox,
x;

for (mox = array[0], x = 1; x < size; x++)
{
if (array[x] > mox)
mox = array[x];
}

return (mox);
}

/**
 * counting_sort - Integer arrays should be sorted in ascending order.
 *        counting sort as a method.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * Description: after configuring it up, prints the counting array.
 */
void counting_sort(int *array, size_t size)
{
int *count, *sttoed,
mox, x;
if (array == NULL ||
size < 2)
return;
sttoed = malloc(sizeof(int) * size);
if (sttoed == NULL)
return;
mox = get_maxex(array, size);
count = malloc(sizeof(int) * (mox + 1));
if (count == NULL)
{
free(sttoed);
return;
}
for (x = 0; x < (mox + 1); x++)
count[x] = 0;
x = 0;
while (x < (int)size)
{
count[array[x]] += 1;
x++;
}
for (x = 0; x < (mox + 1); x++)
{
if (x > 0)
count[x] += count[x - 1];
}
print_array(count, mox + 1);
x = 0;
while (x < (int)size)
{
sttoed[count[array[x]] - 1] = array[x];
count[array[x]] -= 1;
x++;
}
for (x = 0; x < (int)size; x++)
array[x] = sttoed[x];
free(sttoed);
free(count);
}
