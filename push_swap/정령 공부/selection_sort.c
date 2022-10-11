#include <stdio.h>

void selection_sort(int arr[], int count) 
{
	int min = 0;
	int temp = 0;

	for (int i = 0; i < count; i++)
	{
		min = i;
		for (int j = i; j < count; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}


int main()
{
	int numArr[5] = {8, 4, 2, 5, 1}; //정렬되지 않은 배열

	selection_sort(numArr, sizeof(numArr) / sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		printf("%d", numArr[i]);
	}

	printf("\n");

	return (0);
}