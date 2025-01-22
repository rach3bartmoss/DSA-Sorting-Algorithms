#include <stdio.h>
#include <stdlib.h>

static int	find_max(int *arr, int size)
{
	int	i = 0;
	int	result = arr[0];

	while (i < size - 1)
	{
		if (arr[i] > result)
			result = arr[i];
		i++;
	}
	return (result);
}

void	counting_sort(int *arr, int size)
{
	int	max;
	int	*temp_arr;
	int	i;
	int	*output = malloc(size * sizeof(int));

	max = find_max(arr, size);
	temp_arr = calloc(max + 1, sizeof(int));
	i = 0;
	while (i < size)
	{
		temp_arr[arr[i++]]++;
	}
	for (int i = 0; i < max + 1; i++)
	{
		temp_arr[i+1] += temp_arr[i];
	}
	for(int i = 0; i < size; i++)
	{
		output[temp_arr[arr[i]] - 1] = arr[i];
		temp_arr[arr[i]]--;
	}


	printf("---output---\n");
	for (int i = 0; i < size; i++)
	{
		printf("output[%d]: |%d|\n", i, output[i]);
	}
}

int	main(void)
{
	int	arr[] = {12, 89, -45, 1, 2, 3, 13, 90, 4};
	int	size = sizeof(arr) / sizeof(arr[0]);

	counting_sort(arr, size);
}

	/*for (int i = 0; i < size; i++)
	{
		printf("|%d|\n", temp_arr[i]);
	}*/