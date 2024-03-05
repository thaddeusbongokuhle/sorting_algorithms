#include "sort.h"


/**
 * swap_heapsort - sort and array
 * @array: pointer to the array
 * @min: lowest position
 * @max: higuer position
 * @size: size of the array
 * Return: no return
 */
void swap_heapsort(int *array, int min, int max, size_t size)
{

	int temp, value;

	value = array[min];
	temp = array[max];
	array[max] = value;
	array[min] = temp;
	print_array(array, size);
}

/**
 * heap_swap - sort and array
 * @array: pointer to the array
 * @size: index max in tree
 * @i: index
 * @size2: size of the array
 * Return: no return
 */
void heap_swap(int *array, size_t size, int i, size_t size2)
{

	int max = i;
	size_t l = 2 * i + 1;
	size_t r = 2 * i + 2;


	if (l < size && array[l] > array[max])
		max = l;

	if (r < size && array[r] > array[max])
		max = r;

	if (max != i)
	{
		swap_heapsort(array, i, max, size2);

		heap_swap(array, size, max, size2);
	}
}

/**
 * heap_sort - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return
 */
void heap_sort(int *array, size_t size)
{
	int i = 0;

	if (!array || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heap_swap(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		swap_heapsort(array, 0, i, size);
		heap_swap(array, i, 0, size);
	}
}
