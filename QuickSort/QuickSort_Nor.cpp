#include <iostream>
using namespace std;
#include <stack>
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
void QuickSort_Nor(T* arr, int left, int right)
{
	if (arr == NULL || left >= right)
		return;
	stack<int> _s;
	_s.push(left);
	_s.push(right);
	while (!_s.empty())
	{
		int end = _s.top();
		_s.pop();
		int begin = _s.top();
		_s.pop();
		int div = PartSort(arr, begin, end);
		if (div - 1 > begin)
		{
			_s.push(begin);
			_s.push(div - 1);
		}
		if (div + 1 < end)
		{
			_s.push(div + 1);
			_s.push(end);
		}
	}
}
int main()
{
	int arr[] = { 3,2,1,9,7,6,4,0,8 };
	QuickSort_Nor<int>(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	for (int idx = 0; idx < sizeof(arr) / sizeof(arr[0]); ++idx)
		cout << arr[idx] << " ";
	cout << endl;
	system("pause");
	return 0;
}