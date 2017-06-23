#include <iostream>
#include <assert.h>
using namespace std;
void AdjustDown(int *arr, int root, int size)//½¨´ó¶Ñ
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] > arr[child])
			child += 1;
		if (arr[child] > arr[parent])
		{
			std::swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int *arr, int size)
{
	assert(arr && size > 1);
	for (int idx = (size - 2) / 2; idx >= 0; --idx)
	{
		AdjustDown(arr, idx, size);
	}
	int end = size - 1;
	while (end > 0)
	{
		std::swap(arr[0], arr[end]);
		AdjustDown(arr, 0, end);
		--end;
	}
}
int main()
{
	int arr[] = { 5,1,2,7,9,6,0,3 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int idx = 0; idx < 8; ++idx)
		cout << arr[idx] << " ";
	cout << endl;
	system("pause");
	return 0;
}
