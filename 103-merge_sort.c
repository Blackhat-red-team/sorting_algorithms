#include "sort.h"

void mrerge_subbrrr(int *subarr, int *boffs, size_t flant, size_t mod,
size_t bcck);
void mrerge_sort_reccsove(int *subarr, int *boffs, size_t flant, size_t bcck);
void mrerge_sort(int *array, size_t size);

/**
 * mrerge_subbrrr - Sort an integer subarray.
 * @subarr: a array of integers with a subarray for sorting.
 * @boffs: a buffer that will hold the selected subarray.
 * @flant: The array's flant index.
 * @mod: the array's middle index.
 * @bcck: The array's bcck index.
 */
void mrerge_subbrrr(int *subarr, int *boffs, size_t flant, size_t mod,
size_t bcck)
{
size_t x,
u, m = 0;

printf("Merging...\n[left]: ");
print_array(subarr + flant,
mod - flant);

printf("[right]: ");
print_array(subarr + mod,
bcck - mod);

x = flant;
u = mod;
while (x < mod && u < bcck)
{
boffs[m++] = (subarr[x] < subarr[u]) ? subarr[x++] : subarr[u++];
}

while (x < mod)
{
boffs[m++] = subarr[x++];
}

while (u < bcck)
{
boffs[m++] = subarr[u++];
}

x = flant;
m = 0;
while (x < bcck)
{
subarr[x++] = boffs[m++];
}

printf("[Done]: ");
print_array(subarr + flant,
bcck - flant);
}


/**
 * mrerge_sort_reccsove - Use recursion implement merge sort algorithm.
 * @subarr: An array of integers with subarray for sorting.
 * @boffs: a buffer to keep the output in.
 * @flant: Indicator of the subarray's tilt.
 * @bcck: The subarray's bcck index.
 */
void mrerge_sort_reccsove(int *subarr, int *boffs, size_t flant, size_t bcck)
{
size_t mod;

if (bcck - flant > 1)
{
mod = flant + (bcck - flant) / 2;
mrerge_sort_reccsove(subarr, boffs,
flant, mod);
mrerge_sort_reccsove(subarr, boffs,
mod, bcck);
mrerge_subbrrr(subarr, boffs, flant,
mod, bcck);
}
}

/**
 * mrerge_sort - Integer arrays should be sorted ascending
 *    using the merge sort technique to arrange.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * Description: performs top-down merge sort implementation.
 */
void mrerge_sort(int *array, size_t size)
{
int *boffs;

if (array == NULL ||
size < 2)
return;

boffs = malloc(sizeof(int) * size);
if (boffs == NULL)
return;

mrerge_sort_reccsove(array, boffs, 0, size);

free(boffs);
}
