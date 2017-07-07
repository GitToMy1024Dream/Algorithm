#include <iostream>
#include <math.h>
using namespace std;
int MaxDigit(int* arr, int size)
{
	int digit = 0;
	int number = 1;
	int max = arr[0];
	for (int idx = 0; idx < size; ++idx)
	{
		if (max < arr[idx])
			max = arr[idx];
	}         
	while (number <= max)
	{
		digit++;
		number *= 10;
	}
	return digit;
}
void LSDSort(int* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	int* bucket = new int[size];
	int digit = MaxDigit(arr, size);
	int radix = 1;
	while (digit--)
	{
		int count[10] = { 0 };
		for (int idx = 0; idx < size; ++idx)
		{
			count[arr[idx] / radix % 10]++;
		}
		int startAddr[10] = { 0 };
		for (int idx = 1; idx < 10; ++idx)
		{
			startAddr[idx] = startAddr[idx - 1] + count[idx - 1];
		}
		memset(bucket, 0, size * sizeof(int));
		for (int idx = 0; idx < size; ++idx		{
		
			bucket[startAddr[arr[idx] / radix % 10]++] = arr[idx];
		}
		memcpy(arr, bucket, size * sizeof(int));
		radix *= 10;
	}
}

int main()
{
	int arr[] = { 400,421,123,372,410,281,352 ,98,108,345,24};
	//int arr[] = { 38, 5, 19, 26, 49, 97, 1, 66 };
	//LSDSort(arr, sizeof(arr) / sizeof(arr[0]));
	MSDSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int idx = 0; idx < sizeof(arr) / sizeof(arr[0]); ++idx)
		cout << arr[idx] << " ";
	cout << endl;
	system("pause");
	return 0;
}