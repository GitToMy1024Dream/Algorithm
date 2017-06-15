#include <iostream>
using namespace std;
template<class T>
struct Greate
{
	bool operator()(const T& left,const T& right)
	{
		return left > right;
	}
};
template<class T>
struct Less
{
	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};
template<class T,class Compare>
void InsertSort(T* arr, int _size)
{
	if (arr == NULL || _size <= 0)
		return;
	for (int idx = 1; idx < _size; ++idx)
	{
		int end = idx - 1;
		while (end >= 0 && Compare()(arr[end], arr[end + 1]))
		{
			int tmp = arr[end + 1];
			arr[end + 1] = arr[end];
			arr[end] = tmp;
			end--;
		}
	}
}
template<class T>
void Printf(T *arr,int size)
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
	InsertSort<int,Greate<int>>(arr1, length1);
	Printf(arr1, length1);
	InsertSort<int, Less<int>>(arr1, length1);
	Printf(arr1, length1);
	InsertSort<char, Greate<char>>(arr2, length2);
	Printf(arr2, length2);
	InsertSort<char, Less<char>>(arr2, length2);
	Printf(arr2, length2);
	system("pause");
	return 0;
}