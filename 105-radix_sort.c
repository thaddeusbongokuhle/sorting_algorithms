#include "sort.h"


/**
 * radix_sort - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return
 */
void radix_sort(int *array, size_t size)
{

	int max = 0, num = 10;
	size_t i, digits = 0, pcount = 0;
	size_t *count = &pcount;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	while (max > 0)
	{
		max = max / num;
		digits++;
	}
	for (i = 0; i < digits; i++)
	{

		get_digits_radix2(array, size, count, digits);
	}

}


/**
 * copy_array2 - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return
 */
int *copy_array2(int *array, size_t size)
{
	size_t i = 0;
	int *copy = NULL;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	return (copy);
}

/**
 * copy_array - sort and array
 * @array: pointer to the array
 * @places: sorted array
 * @size: size of the array
 * @digits: max of digits
 * @count: counter
 * Return: no return
 */
void copy_array(int *array, int *places, size_t size, size_t digits,
		size_t *count)
{
	size_t i, j;
	int temp = 0;

	if (*count == digits)
	{
		for (i = 1; i < size + 1; i++)
		{
			if (places[i] > places[i + 1] && i < size)
			{
				temp = places[i];
				places[i] = places[i + 1];
				places[i + 1] = temp;
			}
		}
		for (j = 0; j < size + 1; j++)
			array[j] = places[j + 1];
		print_array(array, size);
	}
	else
	{
		for (i = 0; i < size + 1; i++)
			array[i] = places[i + 1];
		print_array(array, size);
	}
}

/**
 * get_digits_radix2 - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * @count: counter
 * @digits: max digits
 * Return: no return
 */
void get_digits_radix2(int *array, size_t size, size_t *count, size_t digits)
{
	size_t i = 0, j = 0, k = 0;
	int digit = 0, pos = 0, a = 0, pos2 = 0, l = 0;
	int index[10];
	int *places = NULL, *copy = NULL;

	for (i = 0; i < 10; i++)
		index[i] = 0;
	copy = copy_array2(array, size);
	if (!copy)
		return;
	if (*count == 0)
	{
		for (i = 0; i < size; i++)
		{copy[i] = copy[i] % 10, digit = copy[i];
			index[digit] = index[digit] + 1; }} else
	{
		for (k = 0; k < size; k++)
		{
			for (i = 0; i < *count; i++)
			{copy[k] = copy[k] / 10, digit = copy[k] % 10; }
			index[digit] = index[digit] + 1; }}
	for (j = 1; j < 10; j++)
		index[j] = index[j - 1] + index[j];
	places = malloc(sizeof(int) * size + 1);
	if (!places)
	{
		free(copy);
		return; }
	for (l = size - 1; l >= 0; l--)
	{
		for (a = 0; a < 11; a++)
		{
			if (copy[l] >= 10)
				copy[l] = copy[l] % 10;
			if (copy[l] == a)
			{pos = copy[l], pos2 = index[pos], places[pos2] = array[l];
				index[pos] = index[pos] - 1; }}}
	*count = *count + 1, copy_array(array, places, size, digits, count);
	free(places), free(copy); }
