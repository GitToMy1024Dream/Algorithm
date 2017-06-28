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
		int maxPos = begin;//���Ԫ���±�
		int minPos = begin;//��СԪ���±�
		for (int idx = begin + 1; idx <= end; ++idx)
		{
			//������Ԫ�ػ��󣬸�������±�
			if (arr[idx] > arr[maxPos])
				maxPos = idx;
			//����С��Ԫ�ػ�С����������±�
			if (arr[idx] < arr[minPos])
				minPos = idx;
		}
		//����begin����СԪ�ص�ֵ
		std::swap(arr[begin], arr[minPos]);
		//������Ԫ���±���begin��ͬ������begin��minPos�Ѿ����������maxPosҲӦ��ָ��minPos
		if (maxPos == begin)
			maxPos = minPos;
		//����end�����Ԫ�ص�ֵ
		std::swap(arr[end], arr[maxPos]);
		//��С����
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