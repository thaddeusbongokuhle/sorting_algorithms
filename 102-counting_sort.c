#include "sort.h"

/**
 * counting_sort - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int pos = 0, k = 0, j = 0, a = 0;
	unsigned int i = 0, l = 0;
	int *index = NULL, *places = NULL;

	if (!array || !size || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i]; }
	index = malloc(sizeof(int) * (k + 1));
	if (!index)
		return;
	for (i = 0; i < size; i++)
		index[i] = 0;
	for (l = 0; l < size; l++)
	{
		for (a = 0; a < (k + 1); a++)
		{
			if (array[l] == a)
				index[a] = index[a] + 1; }}
	for (j = 1; j < (k + 1); j++)
		index[j] = index[j - 1] + index[j];
	print_array(index, (k + 1)), places = malloc(sizeof(int) * size);
	if (!places)
	{
		free(index);
		return; }
	for (l = 0; l < size; l++)
	{
		for (a = 0; a < (k + 1); a++)
		{
			if (array[l] == a)
			{pos = index[a];
				places[pos] = array[l], index[a] = index[a] - 1; }}}
	for (l = 0; l < size; l++)
		array[l] = places[l + 1];
	free(index);
	free(places);
}
