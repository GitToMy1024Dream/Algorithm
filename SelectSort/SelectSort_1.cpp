#include <iostream>
using namespace std;
template<class T>
void SelectSort(T* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	for (int end = size - 1; end > 0; --end)
	{
		int maxIndex = end;
		for (int idx = 0; idx < end; ++idx)
		{
			if (arr[idx] > arr[maxIndex])
				maxIndex = idx;
		}
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