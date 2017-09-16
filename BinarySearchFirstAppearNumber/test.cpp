#include <iostream>
using namespace std;

int bin_search(int array[], int n, int v)
{
	if (array == NULL)
		return -1;
	int left = 0;
	int right = n - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left&right) + ((left^right) >> 1);
		if (array[mid] == v)
			break;
		else if (array[mid] < v)
		{
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	for (int i = mid; i >= 0; i--)
	{
		if (array[i] == v)
			continue;
		else
			return i + 1;
	}
}

int main()
{
	int findKey = 0;
	cin >> findKey;
	int arr[] = { 1,2,3,4,4,5,5,6,6,8,9 };
	int index = bin_search(arr, sizeof(arr) / sizeof(arr[0]), findKey);
	cout << index << endl;
	system("pause");
	return 0;
}