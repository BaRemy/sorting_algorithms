#include "sort.h"
#include "stdlib.h"

/**
 * counting_sort - a function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int a, max;
	int *count = NULL, *copy = NULL;
	size_t b, temp, total = 0;


	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (b = 0, max = 0; b < size; b++)
	{
		copy[b] = array[b];
		if (array[b] > max)
			max = array[b];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(copy);
		return;
	}
	for (a = 0; a <= max; a++)
		count[a] = 0;
	for (b = 0; b < size; b++)
		count[array[b]] += 1;
	for (a = 0; a <= max; a++)
	{
		temp = count[a];
		count[a] = total;
		total += temp;
	}
	for (b = 0; b < size; b++)
	{
		array[count[copy[b]]] = copy[b];
		count[copy[b]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(copy);
}
