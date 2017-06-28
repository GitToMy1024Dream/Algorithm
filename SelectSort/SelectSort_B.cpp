#include <iostream>
using namespace std;
template<class T>
void SelectSort(T* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int maxPos = begin;//最大元素下标
		int minPos = begin;//最小元素下标
		for (int idx = begin + 1; idx <= end; ++idx)
		{
			//比最大的元素还大，更新最大下标
			if (arr[idx] > arr[maxPos])
				maxPos = idx;
			//比最小的元素还小，更新最大下标
			if (arr[idx] < arr[minPos])
				minPos = idx;
		}
		//交换begin与最小元素的值
		std::swap(arr[begin], arr[minPos]);
		//如果最大元素下标与begin相同，上面begin与minPos已经交换，因此maxPos也应该指向minPos
		if (maxPos == begin)
			maxPos = minPos;
		//交换end与最大元素的值
		std::swap(arr[end], arr[maxPos]);
		//缩小区间
		++begin;
		--end;
	}
}
int main()
{
	int arr[] = { 9,2,1,7,4,6,5,0 };
	SelectSort<int>(arr, sizeof(arr) / sizeof(arr[0]));
	for (int idx = 0; idx < sizeof(arr) / sizeof(arr[0]); idx++)
		cout << arr[idx] << " ";
	system("pause");
	return 0;
}