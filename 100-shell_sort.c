#include "sort.h"

/**
 * shell_sort - sort and array
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, i = 0, j = 0, n = 0;
	int temp = 0, x = 0;

	if (!array || !size || size == 1)
		return;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
		n = n + 1;
	}
	for (i = gap; i > 0;)
	{
		temp = array[i];
		for (j = 0; j < size - gap;)
		{
			if (array[j] > temp)
			{
				array[gap + j] = array[j];
				array[j] = temp;
				temp = array[j];
				x = j - gap;
				while (x  >= 0)
				{
					if (array[j - gap] > array[j])
					{
						array[j] = array[j - gap];
						array[j - gap] = temp;
					}
					j--;
					x = j - gap;
				}
			}
			j++;
			temp = array[gap + j];
		}
		i = gap / 3;
		gap = i;
		print_array(array, size);
	}

}
