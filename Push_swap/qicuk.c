#include <stdio.h>
#define SWAP(x, y, tmp) (tmp = x, x = y, y = tmp)

void	quick(int *arr, int L, int R)
{
	int left;
	int right;
	int pivot;
	int tmp;

	left = L;
	right = R;
	pivot = arr[(L + R) / 2];
	while(left <= right)
	{
		while(arr[left] < pivot)
			left++;
		while(arr[right] > pivot)
			right--;
		if (left <= right)
		{
			SWAP(arr[left], arr[right], tmp);
			left++;
			right--;
		}
	}
	if(L < right)
		quick(arr, L, right);
	if(left < R)
		quick(arr, left, R);
}

int	main()
{
	int	i;
	int arr[12] = {1, 5, 3, 8, 4, 9, 1, 6, 2, 3, 4, 5};

	quick(arr, 0, 11);

	for(i = 0; i < 12; i++)
	{
		printf("%d ", arr[i]);
	}
}