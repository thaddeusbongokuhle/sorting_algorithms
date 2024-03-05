#include "sort.h"
#include "sort.h"

/**
 * top_down_merge - sort and array
 * @array: pointer to the array
 * @begin: star of the left array
 * @end: size of the array
 * @copy: copy of the array
 * Return: no return
 */
void top_down_merge(int *array, int begin, int end, int *copy)
{

	int i, j, k, middle;

	middle = (begin + end) / 2;
	i = begin;
	j = middle;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, middle - begin);
	printf("[right]: ");
	print_array(array + middle, end - middle);
	for (k = begin; k < end; k++)
	{
		if (i < middle && (j >= end || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i = i + 1;
		} else
		{
			copy[k] = array[j];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	print_array(copy + begin, end - begin);
}

/**
 * top_down_split_merge - sort and array
 * @array: pointer to the array
 * @begin: start left array
 * @end: size of the array
 * @copy: copy the array
 * Return: no return
 */
void top_down_split_merge(int *array, int begin, int end, int *copy)
{

	int middle = 0;

	middle = (end + begin) / 2;
	if (end - begin < 2)
		return;
	top_down_split_merge(copy, begin, middle, array);
	top_down_split_merge(copy, middle, end, array);
	top_down_merge(array, begin, end, copy);

}

/**
 * merge_sort - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return
 */
void merge_sort(int *array, size_t size)
{
	int *copy = NULL;
	size_t k = 0;

	if (!array || !size || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	for (k = 0; k < size; k++)
		copy[k] = array[k];
	top_down_split_merge(copy, 0, size, array);
	free(copy);
}
