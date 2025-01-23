#include <stdio.h>
#include <stdlib.h>

int	find_max(int *arr, int size)
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

void	counting_sort(int *arr, int size, int digit_house)
{
	int	output[size];		//create a outpur array with the size of original array.
	int	count[10] = {0};	//this will be used to store the digits 0 to 9.

	for (int i = 0; i < size; i++)
	{
		int	index = (arr[i] / digit_house) % 10; //for the 1st loop digit_house is 1, increse by 10 each loop
		count[index]++;//this will update the count array containing the number or repetitions of a value from the original array.
	}
	for (int i = 1; i < 10; i++)//what if the current decimal value is 0?
	{
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		int	index = (arr[i] / digit_house) % 10;
		output[count[index] - 1] = arr[i];
		count[index]--;
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = output[i];
	}
}

/*int	main(void)
{
	int	arr[] = {12, 89, -45, 1, 2, 3, 13, 90, 4};
	int	size = sizeof(arr) / sizeof(arr[0]);

	counting_sort(arr, size);
}*/