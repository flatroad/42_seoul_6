#include <stdio.h>

void insertion_sort(int arr[], int count)
{
	int temp = 0;
	int j = 0;

	for (int i = 1; i < count; i++)
	{
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

int main()
{
	int numArr[5] = {8, 4, 2, 5, 1}; //정렬되지 않은 배열

	insertion_sort(numArr, sizeof(numArr) / sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		printf("%d", numArr[i]);
	}

	printf("\n");

	return (0);
}