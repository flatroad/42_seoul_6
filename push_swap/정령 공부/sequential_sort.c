#include <stdio.h>

void sequential_sort (int arr[], int count)
{
	int temp = 0;

	for (int i = 0; i < count; i++)
	{
		for (int j= i + 1; j < count; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main()
{
	int numArr[5] = {8, 4, 2, 5, 1}; //정렬되지 않은 배열

	sequential_sort(numArr, sizeof(numArr) / sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		printf("%d", numArr[i]);
	}

	printf("\n");

	return (0);
}
