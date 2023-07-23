#include "sort.h"

void swaprs_ints(int *x, int *z);
int hoarees_partttion(int *array, size_t size, int left, int right);
void hoarees_sort(int *array, size_t size, int left, int right);
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
 * hoarees_partttion - sorted subset of an integer array
 *       based on the Hoare Partitioning Scheme.
 * @array: The collection of integers.
 * @size: The array's dimensions.
 * @left: The subset's starting index is used to sort.
 * @right: The subset's final index to order.
 * Return: The last index of the partition.
 * Description: utilises the partition's final component as the point
 * after every two element swap, prints the array.
 */
int hoarees_partttion(int *array, size_t size,
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
 * hoarees_sort - Recursion is used to implement the quicksort algorithm.
 * @array: Sorting an array of numbers.
 * @size: The array's dimensions.
 * @left: The array partition order's initial index.
 * @right: The array partition's final index in sequence.
 * Description: utilises the Hoare partitioning method.
 */
void hoarees_sort(int *array,
size_t size,
int left, int right)
{
int parts;

if (right - left > 0)
{
parts = hoarees_partttion(array, size,
left, right);
hoarees_sort(array, size,
left, parts - 1);
hoarees_sort(array, size,
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

hoarees_sort(array, size,
0, size - 1);
}
