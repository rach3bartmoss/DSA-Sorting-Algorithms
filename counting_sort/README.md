COUNTING SORT ALGORITHM

Counting sort is a non-comparison based algorithm widely know for its efficiency and stability. Although can have its performance affected by large integers
used as elements, this is related to the logic within the algorithm. Counting sort has a time complexity of *O(n+k)*, where *n* is the number of elements and *k*
is the range based on the *n* number of digits. For example, if we passed as parameter the **int	arr[] = {1, 3, 5, 4, 2};** will have better perfomance
than **int arr[] = {10000, 30000, 50000, 40000, 20000};** since the range *k* of the elements *n* are larger. So we can imply that counting sort is most
recommended to use with smaller data sets.

Besides that, is simple and straight-forward algorithm, can be easily implemented in any project that requires a stable output, here how it works:



1) We first need to find the larger element in the array, a simple implementation:
```
int	find_max(int *arr, int size)
{
	int	i = 0;
	int	max = arr[0];

	while (i < size - 1)
	{
		if (arr[i] > result)
			result = arr[i];
		i++;
	}
	return (result);
}
```
