#include <iostream>
using namespace std;
template<class T>
int PartSort(T* arr, int begin, int end)
{
	int left = begin;
	int right = end;
	while (left < right)
	{
		while (left < right && arr[left] <= arr[end])
			++left;
		while (left < right && arr[right] >= arr[end])
			--right;
		if (left < right)
			std::swap(arr[left], arr[right]);
	}
	std::swap(arr[left], arr[end]);
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