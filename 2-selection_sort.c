#include "sort.h"

/**
 * min - search the minimun element
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Return: address of the minimum item of a array
 */
int *min(int *array, size_t size)
{
	int *min_mul = &array[0];

	while (size--)
	{
		if (array[size] < *min_mul)
		{
			min_mul = &array[size];
		}
	}

	return (min_mul);
}

/**
 * selection_sort - sort array by selection
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		int *min_mul = min(&array[i], size - i);
		int tmp = 0;

		if (&array[i] != min_mul)
		{
			tmp = array[i];

			array[i] = *min_mul;
			*min_mul = tmp;

			print_array(array, size);
		}
	}
}
