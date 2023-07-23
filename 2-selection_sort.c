#include "sort.h"

/**
 * swaprs_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @z: The second integer to swap.
 */
void swaprs_ints(int *x, int *z)
{
int tmp;

tmp = *x;
*x = *z;
*z = tmp;
}

/**
 * selection_sort - Integer arrays should be sorted in ascending order.
 *         selecting the sort algorithm.
 * @array: a array a collection of integers.
 * @size: The size The array's dimensions.
 * Description: the array is printed after each swap.
 */
void selection_sort(int *array, size_t size)
{
int *min;
size_t x,
z;

if (array == NULL ||
size < 2)
return;

x = 0;
while (x < size - 1)
{
min = array + x;
z = x + 1;
while (z < size)
{
min = (array[z] < *min) ?
(array + z) : min;
z++;
}

if ((array + x) != min)
{
swaprs_ints(array + x, min);
print_array(array, size);
}

x++;
}
}
