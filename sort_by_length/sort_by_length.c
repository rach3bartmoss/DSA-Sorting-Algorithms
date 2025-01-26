#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	counting_sort(int *arr, int size)
{
	int	output[size];

}

//function must sort a given string array by the length of the strings
void	sort_by_length(const char *str[])
{
	int	*length_index = calloc(5, sizeof(int));
	int	size = 0;

	for (size = 0; str[size] != NULL; size++)
	{
		length_index[size] = strlen(str[size]);
	}
	for (int i = 0; str[i] != NULL; i++)
	{
		printf("%d\n", length_index[i]);
	}
}
//i have a int *arr with the length of unsorted array.
//need to sort the array, and create a mirrored array of string with the lengths.
//10 7 4 8 9 becomes a array of strings with sizes: 4 7 8 9 10
// now we take from the 'lenght index' we copy the 0th array,which has the lenght 10
//and put at the corresponding index in sorted array, in this case index 4.
// logic similar to counting sort, discover how to do it.

int	main(void)
{
	const char	*str[] = {"Telescopes", "Glasses", "Eyes", "Monocles", "Cyberpunk", NULL};

	sort_by_length(str);
}