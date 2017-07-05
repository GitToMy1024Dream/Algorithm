#include <iostream>
using namespace std;
//µ›πÈ πÈ≤¢≈≈–Ú
void Merge(int* arr, int* tmp, int left, int mid, int right)
{
	int begin_1 = left;
	int end_1 = mid;
	int begin_2 = mid + 1;
	int end_2 = right;
	int index = begin_1;
	while (begin_1 <= end_1 && begin_2 <= end_2)
	{
		if (arr[begin_1] < arr[begin_2])
			tmp[index++] = arr[begin_1++];
		else
			tmp[index++] = arr[begin_2++];
	}
	while (begin_1 <= end_1)
		tmp[index++] = arr[begin_1++];
	while (begin_2 <= end_2)
		tmp[index++] = arr[begin_2++];
}
void _MergeSort(int* arr, int *tmp, int left, int right)
{
	if (left >= right)
		return;
	int mid = (left&right) + ((left^right) >> 1);
	_MergeSort(arr, tmp, left, mid);
	_MergeSort(arr, tmp, mid + 1, right);
	Merge(arr, tmp, left, mid, right);
	memcpy(arr + left, tmp + left, (right - left + 1) * sizeof(int));
}
void MergeSort(int *arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	int* tmp = new int[size];
	_MergeSort(arr, tmp, 0, size - 1);
	delete[] tmp;
}
int main()
{
	int arr[] = { 2,1,4,9,3,6,8,7,0,5 };
	MergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int idx = 0; idx < sizeof(arr) / sizeof(arr[0]); ++idx)
		cout << arr[idx] << " ";
	system("pause");
	return 0;
}