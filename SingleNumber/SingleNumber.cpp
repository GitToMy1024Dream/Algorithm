#include <iostream>
using namespace std;


//1.0
//class Solution
//{
//public:
//	int SingleNumber(int A[], int n)
//	{
//		int x = 0;
//		for (int i = 0; i < n; i++)
//		{
//			x ^= A[i];
//		}
//		return x;
//	}
//};

class Solution
{
public:
	int SingleNumber(int A[], int n)
	{
		int one = 0;//出现一次的比特位
		int two = 0;//出现两次的比特位
		int three = 0;
		for (int i = 0; i < n; ++i)
		{
			two |= (one&A[i]);//更新one之前先更新two
			one ^= A[i];
			three = one & two;//one two都为1说明出现了三次
			one &= ~three;//抹去出现3次的比特位
			two &= ~three;
		}
		return one;
	}
};


int main()
{
	Solution s;
	int arr[] = { 1,1,1,2,2,2,3,4,4,4,5,5,5 };
	cout << s.SingleNumber(arr, 9) << endl;
	system("pause");
	return 0;
}