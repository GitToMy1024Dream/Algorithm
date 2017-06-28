#include <iostream>
using namespace std;
template<class T>
void SelectSort(T* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	for (int end = size - 1; end > 0; --end)
	{
		int maxIndex = end;//最大下标
		for (int idx = 0; idx < end; ++idx)
		{
			//比最大的元素还大，更新最大下标
			if (arr[idx] > arr[maxIndex])
				maxIndex = idx;
		}
		//交换end与最大元素的值
		std::swap(arr[maxIndex], arr[end]);
	}
}
int main()
{
	int arr[] = { 9,2,1,7,4,6,5,0 };
	SelectSort<int>(arr, sizeof(arr) / sizeof(arr[0]));
	for (int idx = 0; idx < sizeof(arr) / sizeof(arr[0]); idx++)
		cout << arr[idx] << " ";
	cout << endl;
	system("pause");
	return 0;
}