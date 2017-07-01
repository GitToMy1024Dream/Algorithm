//前后指针法
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
	int Cur = begin;
	int Prev = Cur - 1;
	int keyIndex = GetMidIndex(arr, begin, end);
	std::swap(arr[keyIndex], arr[end]);
	T key = arr[end];
	while (Cur < end)
	{
		if (arr[Cur] < key && ++Prev != Cur)
			std::swap(arr[Prev], arr[Cur]);
		++Cur;
	} 
	++Prev;
	std::swap(arr[Prev], arr[Cur]);
	return Prev;
}
template<class T>
void QuickSort(T* arr, int left, int right)
{
	if (arr == NULL || left >= right)
		return;
	int div = PartSort(arr, left, right);
	QuickSort(arr, left, div - 1);
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
