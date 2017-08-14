//#include <iostream>
//using namespace std;

//int SingleNumber(int *arr,int n)
//{
//	int key = arr[0];
//	for (int i = 1; i < n; ++i)
//	{
//		key ^= arr[i];
//	}
//	return key;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,3,2,1};
//	cout << SingleNumber(arr, 7) << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;

int bitIndexOf1(int num)
{
	int count = 0;
	while ((num & 1) == 0 && count < 8 * sizeof(int))
	{
		++count;
		num = num >> 1;
	}
	return count;
}

bool isBit1(int x, int index)
{
	x = x >> index;
	return x & 1;
}

void FindSingleNum(int arr[], int length, int *tmp1, int *tmp2)
{
	if (length < 2)
		return;
	int key = arr[0];
	for (int i = 1; i < length; ++i)
	{
		key ^= arr[i];
	}

	int indexOf1 = bitIndexOf1(key);

	*tmp1 = *tmp2 = 0;
	for (int j = 0; j < length; ++j)
	{
		if (isBit1(arr[j], indexOf1))
		{
			*tmp1 ^= arr[j];
		}
		else
			*tmp2 ^= arr[j];
	}
}


int main()
{
	int arr[] = { 1,2,3,4,3,2,1,5};
	int tmp1 = 0;
	int tmp2 = 0;
	FindSingleNum(arr, 8, &tmp1, &tmp2);
	system("pause");
	return 0;
}