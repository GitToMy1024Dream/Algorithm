#include <iostream>
using namespace std;
template<class T>
void ShellSort(T* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	int gap = size;//gap为增量
	while (gap > 1)
	{
		gap = gap / 3 + 1;//这样给是最优的
		for (int idx = gap; idx < size; ++idx)
		{
			int end = idx - gap;//分组后，当前元素的前一个元素
			int key = arr[idx];//保存当前元素
			//按升序排序
			while (end >= 0 && arr[end] > key)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
	}
}
int main()
{
	int arr[] = { 3,5,7,4,1,2,8,9,10,0 };
	ShellSort<int>(arr, sizeof(arr) / sizeof(arr[0]));
	for (int idx = 0; idx < sizeof(arr) / sizeof(arr[0]); ++idx)
		cout << arr[idx] << " ";
	cout << endl;
	system("pause");
	return 0;
}