#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	comp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void	sort_by_length(const char *str[])
{
	int	*length_index = calloc(5, sizeof(int));
	int	size = 0;
	int	i = 0;

	for (size = 0; str[size] != NULL; size++)
	{
		length_index[size] = strlen(str[size]);
	}
	qsort(length_index, size, sizeof(int), comp);
	while (i < size)
	{
		int	j = 0;
		while (j < size)
		{
			if (strlen(str[j]) == length_index[i])
			{
				const char	*tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	const char	*str[] = {"Telescopes", "Glasses", "Eyes", "Monocles", "Cyberpunk", NULL};

	sort_by_length(str);
	for (int i = 0; str[i] != NULL; i++)
	{
		printf("%s\n", str[i]);
	}
}