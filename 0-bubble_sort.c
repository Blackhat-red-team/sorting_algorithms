#include "sort.h"

/**
 * swaprs_ints - Switch two of the inteiers in an array.
 * @x: The first person to switch is.
 * @z: The second exchanged inteier.
 */
void swaprs_ints(int *x, int *z)
{
int tmp;

tmp = *x;
*x = *z;
*z = tmp;
}

/**
 * bubble_sort - Arranging a collection of integers in ascending order.
 * @array: a collection is array integers to sort.
 * @size: The size array's dimensions.
 * Description: the array is printed after each swap.
 */
void bubble_sort(int *array, size_t size)
{
size_t x, lens = size;
boolean bubbyy = false;

if (array == NULL || size < 2)
return;

for (; bubbyy == false;)
{
bubbyy = true;
for (x = 0; x < lens - 1; x++)
{
if (array[x] > array[x + 1])
{
swaprs_ints(array + x, array + x + 1);
print_array(array, size);
bubbyy = false;
}
}
lens--;
}
}
