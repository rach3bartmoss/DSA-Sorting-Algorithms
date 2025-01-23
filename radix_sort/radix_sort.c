#include <stdlib.h>
#include <stdio.h>
#include "radix_sort.h"

int	count_digits(int value)
{
	int	count;

	count = 0;
	if (value == 0)
		return (1);

	while (value != 0)
	{
		value = value / 10;
		count++;
	}
	return (count);
}

void	radix_sort(int *arr, int size)
{
	int	max;
	int	n_digits;
	int	place = 1;

	max = find_max(arr, size);
	while (max / place > 0)
	{
		counting_sort(arr, size, place);
		place *= 10;
	}
}

int	main(void)
{
	int	size;

	int	arr[] = {121, 432, 564, 23, 1, 45, 788};

	size = sizeof(arr) / sizeof(arr[0]);
	radix_sort(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("sorted: |%d|\n", arr[i]);
	}
}