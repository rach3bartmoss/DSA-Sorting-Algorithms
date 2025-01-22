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
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}
```
2) Initialize an array of size ```max + 1``` with all elements 0, so we can store the number of repetitions from the smaller value to the greatest value
   * this could be easily achieved with calloc:
```
	int	*count_arr = calloc(max + 1, sizeof(int);
```
3) After that we store the count of each element present in the input array. For example if we have a ```arr[] = {3, 5, 7, 3, 2, 1, 3, 7, 0, 5);```
   the original array block is like this:
```| 3 | 5 | 7 | 3 | 2 | 1 | 3 | 7 | 0 | 5 |``` 
   and the count array will look like this:
```
indexes:  0   1   2   3   4   5   6   7
	| 1 | 1 | 1 | 3 | 0 | 2 | 0 | 2 |  number of repetitions for each index
```
4) Now we should find the index of each element in both original array and count array, naturally starting with ```i = 0; arr[i] = 3``` so the element *n* = 3;
   will be located at the index 3 of count_arr[], the index 3 in the count_arr has a value of ```3```since the element '3' repeats itself 3 times in the original
   array so we place the **value** of arr[i] = '3'; at the **output[index]:** ```output[count_arr[arr[i]] - 1] = arr[i];``` this operation looks like the most
   mind-squeezing but is really simple. We are ordinating the output array based on the counts of each element of the original array, the code:
```
for (int i = 0; i < size; i++)
{
	output[count_arr[arr[i]] - 1] = arr[i];
	count_arr[arr[i]]--; //we also need to decrease the count of repetitions in since we already place one time
}
```
   the function will work through the loop until all the elements are put in the output array.

Is important to take not that this code was design to work with non-negative integers, but can be adapt to handle negative numbers by finding the range
of its parameters and shifting its values.
