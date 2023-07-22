/*
 * Files: 106-bitonic_sort.c
 * Auth: ibrahim said ibrahim
 * and Auth: Avatar Abdulla Ahmed
 */

#include "sort.h"

void swaprs_ints(int *x, int *z);
void bitonic_mrrge(int *array, size_t size,
size_t star, size_t seq,
char flew);
void bitonic_seoq(int *array, size_t size, size_t star,
size_t seq, char flew);
void bitonic_sort(int *array,
size_t size);

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
 * bitonic_mrrge - Sort an integer array to contain a bitonic sequence.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * @star: The sequence's initial index in the array that will be sorted.
 * @seq: Size of the to-be-sorted sequence.
 * @flew: The order of sorting.
 */
void bitonic_mrrge(int *array, size_t size,
size_t star, size_t seq,
char flew)
{
size_t z,
jumm = seq / 2;

if (seq > 1)
{
for (z = star; z < star + jumm; z++)
{
if ((flew == UP && array[z] > array[z + jumm]) ||
(flew == DOWN && array[z] < array[z + jumm]))
swaprs_ints(array + z, array + z + jumm);
}
bitonic_mrrge(array, size,
star, jumm, flew);
bitonic_mrrge(array, size,
star + jumm, jumm, flew);
}
}

/**
 * bitonic_seoq - An integer array to a bitonic sequence conversion.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * @star: the block's initial index in the bitonic construction sequence.
 * @seq: Block size in the bitonic construction sequence.
 * @flew: The order in which the bitonic sequence block should be sorted.
 */
void bitonic_seoq(int *array, size_t size, size_t star, size_t seq, char flew)
{
size_t cuu = seq / 2;
char *str = (flew == UP) ? "UP" : "DOWN";

if (seq > 1)
{
printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
print_array(array + star, seq);

bitonic_seoq(array, size,
star, cuu, UP);
bitonic_seoq(array, size,
star + cuu, cuu, DOWN);
bitonic_mrrge(array, size,
star, seq, flew);

printf("Result [%lu/%lu] (%s):\n", seq, size, str);
print_array(array + star,
seq);
}
}

/**
 * bitonic_sort - Integer arrays should be sorted ascending
 *      utilising  bitonic sort algorithm arrange.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * Description: the array is printed after each swap. only applies to
 * size is equal to powers of 2, or size = 2k, where k >= 0.
 */
void bitonic_sort(int *array, size_t size)
{
if (array == NULL ||
size < 2)
return;

bitonic_seoq(array, size,
0, size, UP);
}
