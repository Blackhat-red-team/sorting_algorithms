#include "sort.h"

int get_maxex(int *array, int size);
void radix_coonttng_sort(int *array, size_t size,
int sog, int *boffs);
void radix_sort(int *array, size_t size);

/**
 * get_maxex - Find the highest value in an integer array.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * Return: The array's biggest integer is.
 */
int get_maxex(int *array, int size)
{
int mox,
z;

mox = array[0];
z = 1;
while (z < size)
{
if (array[z] >
mox)
mox = array[z];
z++;
}

return (mox);
}


/**
 * radix_coonttng_sort - a integer array's signifi digits be sorted
 *      using the counting sort technique, in ascending order.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * @sog: The sort key is the significant digit.
 * @boffs: a buffer for the specified array.
 */
void radix_coonttng_sort(int *array, size_t size,
int sog, int *boffs)
{
int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
size_t z = 0;

while (z < size)
{
count[(array[z] / sog) % 10] += 1;
z++;
}

z = 0;
while (z < 10)
{
if (z > 0)
{
count[z] += count[z - 1];
}
z++;
}

z = size - 1;
while ((int)z >= 0)
{
boffs[count[(array[z] /
sog) % 10] - 1] = array[z];
count[(array[z] / sog) % 10] -= 1;
z--;
}

z = 0;
while (z < size)
{
array[z] = boffs[z];
z++;
}
}



/**
 * radix_sort - Integer arrays should be sorted ascending
 *     using the radix sort algorithm to arrange.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * Description: the LSD radix sort method is implemented. Prints
 * with each major digit increase, the array.
 */
void radix_sort(int *array, size_t size)
{
int mox,
sog, *boffs;

if (array == NULL ||
size < 2)
return;

boffs = malloc(sizeof(int) * size);
if (boffs == NULL)
return;

mox = get_maxex(array, size);
sog = 1;
while (mox / sog > 0)
{
radix_coonttng_sort(array, size, sog, boffs);
print_array(array, size);
sog *= 10;
}

free(boffs);
}
