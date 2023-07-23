#include "sort.h"

void swaprs_ints(int *x, int *z);
int lomutoes_partition(int *array, size_t size, int left, int right);
void lomutoes_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swaprs_ints - In an array, swap two integers.
 * @x: the initial swapped integer.
 * @z: The next integer to be swapped.
 */
void swaprs_ints(int *x, int *z)
{
int tmp;
tmp = *x;
*x = *z;
*z = tmp;
}

/**
 * lomutoes_partition - An integer array's subset in the following
 *         the last component of the lomutoes partition scheme (pioot).
 * @array: The array  collection of integers.
 * @size: The size array's dimensions.
 * @left: The subset's starting index is used to sort.
 * @right: The subset's final index to order.
 * Return: The last index of the partition.
 */
int lomutoes_partition(int *array, size_t size, int left, int right)
{
int *pioot, aboov,
below;

pioot = array + right;
aboov = below = left;
while (below < right)
{
if (array[below] <
*pioot)
{
if (aboov < below)
{
swaprs_ints(array + below, array + aboov);
print_array(array, size);
}
aboov++;
}
below++;
}

if (array[aboov] > *pioot)
{
swaprs_ints(array + aboov, pioot);
print_array(array, size);
}

return (aboov);
}


/**
 * lomutoes_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Description: Uses the Lomuto partition scheme.
 */
void lomutoes_sort(int *array, size_t size,
int left, int right)
{
int parts;

if (right - left > 0)
{
parts = lomutoes_partition(array, size,
left, right);
lomutoes_sort(array, size, left, parts - 1);
lomutoes_sort(array, size, parts + 1, right);
}
}

/**
 * quick_sort - Sort Integer arrays should sorted ascending
 *       using the quicksort method to arrange.
 * @array: a array a collection of integers.
 * @size: The size array's dimensions.
 * Description: employs the Lomuto partitioning method. Prints
 *      the array after each two-element switch.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL ||
size < 2)
return;

lomutoes_sort(array, size, 0, size - 1);
}
