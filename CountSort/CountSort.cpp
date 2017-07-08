#include <iostream>
using namespace std;
void CountSort(int* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	int max = arr[0];
	int min = arr[0];
	for (int idx = 0; idx < size; ++idx)
	{
		if (max < arr[idx])
			max = arr[idx];
		if (min > arr[idx])
			min = arr[idx];
	}
	int range = max - min + 1;
	int* tmp = new int[range];
	memset(tmp, 0, range * sizeof(int));
	for (int idx = 0; idx < size; ++idx)
	{
		tmp[arr[idx] - min]++;
	}
	int index = 0;
	for (int idx = 0; idx < range; ++idx)
	{
		while (tmp[idx]--)
		{
			arr[index++] = idx + min;
		}
	}
	delete[] tmp;
}
int main()
{
	int arr[] = { 3,7,5,2,1,3,7,4 };
	CountSort(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
	return 0;
}