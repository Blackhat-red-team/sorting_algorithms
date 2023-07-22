#include "sort.h"

void swaprs_ints(int *x, int *z);
int hoare_partttion(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partttion - sorted subset of an integer array
 *       based on the Hoare Partitioning Scheme.
 * @array: The collection of integers.
 * @size: The array's dimensions.
 * @left: The subset's starting index is used to sort.
 * @right: The subset's final index to order.
 * Return: The last index of the partition.
 * Description: utilises the partition's final component as the point
 * after every two element swap, prints the array.
 */
int hoare_partttion(int *array, size_t size,
int left, int right)
{
int pioot,
abbve, below;

pioot = array[right];
abbve = left - 1;
below = right + 1;

while (abbve < below)
{
while (array[++abbve] < pioot)
;
while (array[--below] > pioot)
;

if (abbve < below)
{
swaprs_ints(array + abbve,
array + below);
print_array(array,
size);
}
}

return (abbve);
}


/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array,
size_t size,
int left, int right)
{
int parts;

if (right - left > 0)
{
parts = hoare_partttion(array, size,
left, right);
hoare_sort(array, size,
left, parts - 1);
hoare_sort(array, size,
parts, right);
}
}

/**
 * quick_sort_hoare - Integer arrays should be sorted ascending
 *    using the quicksort method to arrange.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * Description: utilises the Hoare partitioning method. Prints
 * the array each time two members are switched.
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL ||
size < 2)
return;

hoare_sort(array, size,
0, size - 1);
}
