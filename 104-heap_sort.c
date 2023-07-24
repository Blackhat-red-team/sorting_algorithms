#include "sort.h"

void swaprs_ints(int *x, int *z);
void max_happify(int *array, size_t size, size_t bsse, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_happify - Become a full binary heap from a binary tree.
 * @array: a binary tree represented as an array of integers.
 * @size: The array's or tree's size.
 * @bsse: the index of the tree's bsse row.
 * @root: the binary tree's base node.
 */
void max_happify(int *array, size_t size,
size_t bsse, size_t root)
{
size_t left, right,
lorge;

left = 2 * root + 1;
right = 2 * root + 2;
lorge = root;

if (left < bsse &&
array[left] > array[lorge])
lorge = left;
if (right < bsse &&
array[right] > array[lorge])
lorge = right;

if (lorge != root)
{
swaprs_ints(array + root,
array + lorge);
print_array(array, size);
max_happify(array, size,
bsse, lorge);
}
}

/**
 * heap_sort - Integer arrays should be sorted ascending
 *      heap sorting to determine order.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * Description: performs sift-down heap sort
 * algorithm. the array is printed after each swap.
 */
void heap_sort(int *array, size_t size)
{
int x;

if (array == NULL ||
size < 2)
return;

x = (size / 2) - 1;
while (x >= 0)
{
max_happify(array, size,
size, x);
x--;
}

x = size - 1;
while (x > 0)
{
swaprs_ints(array,
array + x);
print_array(array, size);
max_happify(array, size, x, 0);
x--;
}
}
