#include <stdio.h>

void bubble_sort(int arr[], int count)  //매개변수로 정렬할 배열과 요소의 개수를 받음
{
	int temp;

	for (int i = 0; i < count; i++)  // 요소의 개수만큼 반복
	{
		for (int j = 0; j < count - 1; j++) // 요소의 개수 -1 만큼 반복
		{
			if(arr[j] > arr[j + 1])  // 현재 요소의 값과 다음 요소의 값을
			{						 // 배교하여 큰 값을 다음 요소로 보냄
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int numArr[5] = {8, 4, 2, 5, 1}; //정렬되지 않은 배열

	bubble_sort(numArr, sizeof(numArr) / sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		printf("%d", numArr[i]);
	}

	printf("\n");

	return (0);
}