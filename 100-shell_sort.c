#include "sort.h"

/**
 * shell_sort - a function that sorts an array of integers
 * in ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t a, b, gap = 1;
	int insert;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (a = gap; a < size; a++)
		{
			insert = array[a];
			for (b = a; b >= gap && array[b - gap] > insert; b = b - gap)
				array[b] = array[b - gap];
			array[b] = insert;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
