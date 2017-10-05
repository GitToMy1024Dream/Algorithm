#include <iostream>
using namespace std;

class Solution
{
public:
	bool canJump(int A[], int n)
	{
		if (n == 0)
			return true;
		//逆向下楼梯，看是否能到达初始0位置
		int left_most = n - 1;
		for (int i = n - 2; i >= 0; --i)
		{
			if (i + A[i] >= left_most)
				left_most = i;
		}
		return left_most == 0;
	}
};

int main()
{
	Solution s;
	int arr[] = { 2,3,1,1,4 };
	cout << s.canJump(arr, 5) << endl;
	system("pause");
	return 0;
}