#include <iostream>
using namespace std;

void CountSort(int arr[], int n)
{
	if (arr == NULL)
		return;
	const int N = 65535;
	int temp[N];
	memset(temp, 0, sizeof(int)*N);
	for (int i = 0; i < n; ++i)
	{
		temp[arr[i]]++;
	}
	int index = 0;
	for (int i = 0; i < N; ++i)
	{
		while (temp[i]--)
		{
			arr[index++] = i;
		}
	}
}

int main()
{
	int arr[] = { 12,13,12,13,19,18,15,12,15,16,17 };
	CountSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 11; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}