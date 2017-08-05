#include <iostream>
#include <queue>
using namespace std;

struct Compare
{
	bool operator()(int x, int y)
	{
		return x > y;
	}
};

int HeapSort(int arr[], int n)
{
	int len = (n + 1) >> 1;
	priority_queue<int,vector<int>, Compare> _p;
	for (int i = 0; i < len; ++i)
	{
		_p.push(arr[i]);
	}
	for (int i = len; i < n; ++i)
	{
		if (arr[i] > _p.top())
		{
			_p.pop();
			_p.push(arr[i]);
		}
	}
	return _p.top();
}

int main()
{
	int arr[] = { 3,5,1,7,0,2,8,9 ,6 };
	int ret = HeapSort(arr, sizeof(arr)/sizeof(arr[0]));
	cout << ret << endl;
	system("pause");
	return 0;
}