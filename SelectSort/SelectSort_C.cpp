#include <iostream>
using namespace std;
template<class T>
void SelectSort(T* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		for (int idx = left; idx <= right; ++idx)
		{
			//比left小的交换
			if (arr[idx] < arr[left])
				std::swap(arr[idx], arr[left]);
			//比right大的交换
			if (arr[idx] > arr[right])
				std::swap(arr[idx], arr[right]);
		}
		//缩小左右区间
		++left;
		--right;
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