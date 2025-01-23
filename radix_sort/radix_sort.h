#ifndef RADIX_SORT_H
# define RADIX_SORT_H

#include <stdlib.h>
#include <stdio.h>

int		find_max(int *arr, int size);
void	counting_sort(int *arr, int size, int digit_house);
void	radix_sort(int *arr, int size);



#endif