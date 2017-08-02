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
		int one = 0;//����һ�εı���λ
		int two = 0;//�������εı���λ
		int three = 0;
		for (int i = 0; i < n; ++i)
		{
			two |= (one&A[i]);//����one֮ǰ�ȸ���two
			one ^= A[i];
			three = one & two;//one two��Ϊ1˵������������
			one &= ~three;//Ĩȥ����3�εı���λ
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