#include "sort.h"


/**
 * bubble_sort - sort and array
 * @array: array
 * @size: size of the array
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0;
	int temp = 0;
	int flag = 1;

	if (!array || !size || size == 1)
		return;
	while (flag)
	{
		flag = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
	}
}
