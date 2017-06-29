//ÍÚ¿Ó·¨
#include <iostream>
using namespace std;
template<class T>
int GetMidIndex(T* arr, int left, int right)
{
	int mid = (left & right) + ((left^right) >> 1);
	if (arr[left] < arr[mid])
	{
		if (arr[right] > arr[mid])
			return mid;
		if (arr[right] < arr[left])
			return left;
		return right;
	}
	else
	{
		if (arr[right] > arr[left])
			return left;
		if (arr[right] < arr[mid])
			return mid;
		return right;
	}
}
template<class T>
int PartSort(T* arr, int begin, int end)
{
	int left = begin;
	int right = end;
	int keyIndex = GetMidIndex(arr, begin, end);
	std::swap(arr[keyIndex], arr[end]);
	T key = arr[end];
	while (left < right)
	{
		while (left < right && arr[left] <= key)
			++left;
		if (left < right)
			arr[right] = arr[left];
		while (left < right && arr[right] >= key)
			--right;
		if (left < right)
			arr[left] = arr[right];
	}
	arr[left] = key;
	return left;
}
template<class T>
void QuickSort(T* arr, int left, int right)
{
	if (arr == NULL || left >= right)
		return;
	int div = PartSort(arr, left, right);
	if (div - 1 > left)
		QuickSort(arr, left, div - 1);
	if (div + 1 < right)
		QuickSort(arr, div + 1, right);
}
int main()
{
	int arr[] = { 2,1,4,9,3,6,8,7,0,5 };
	QuickSort<int>(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	for (int idx = 0; idx < sizeof(arr) / sizeof(arr[0]); ++idx)
		cout << arr[idx] << " ";
	cout << endl;
	system("pause");
	return 0;
}
