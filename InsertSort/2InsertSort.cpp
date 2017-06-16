#include <iostream>
using namespace std;
//template<class T>
//struct Greate
//{
//	bool operator()(const T& left, const T& right)
//	{
//		return left > right;
//	}
//};
//template<class T>
//struct Less
//{
//	bool operator()(const T& left, const T& right)
//	{
//		return left < right;
//	}
//};
template<class T/*, class Compare*/>
void InsertSort(T* arr, int _size)
{
	if (arr == NULL || _size <= 0)
		return;
	for (int idx = 1; idx < _size; ++idx)
	{
		int left = 0;
		int right = idx - 1;
		//1.
		if (arr[idx] > arr[right])
			continue;
		//2.
		else if (arr[idx] < arr[left])
		{
			int tmp = arr[idx];
			for (int j = right; j >= 0; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[0] = tmp;
		}
		//3.
		else
		{
			while (left <= right)
			{
				int mid = (left&right) + ((left^right) >> 1);
				if (arr[idx] < arr[mid])
					right = mid - 1;
				else if (arr[idx] > arr[mid])
					left = mid + 1;
			}
			int tmp = arr[idx];
			for (int i = idx-1; i > right; --i)
			{
				arr[i + 1] = arr[i];
			}
			arr[left] = tmp;
		}
	}
}
template<class T>
void Printf(T *arr, int size)
{
	for (size_t idx = 0; idx < size; ++idx)
		cout << arr[idx] << " ";
	cout << endl;
}
int main()
{
	int arr1[] = { 3,2,1,7,5,9,8,4 };
	char arr2[] = { 'a','c','d','b','z','u','g' };
	int length1 = sizeof(arr1) / sizeof(arr1[0]);
	int length2 = sizeof(arr2) / sizeof(arr2[0]);
	//rtSort<int, Greate<int>>(arr1, length1);
	InsertSort(arr1, length1);
	Printf(arr1, length1);
	InsertSort(arr2, length2);
	Printf(arr2, length2);
	/*InsertSort<int, Less<int>>(arr1, length1);
	Printf(arr1, length1);
	InsertSort<char, Greate<char>>(arr2, length2);
	Printf(arr2, length2);
	InsertSort<char, Less<char>>(arr2, length2);
	Printf(arr2, length2);*/
	system("pause");
	return 0;
}