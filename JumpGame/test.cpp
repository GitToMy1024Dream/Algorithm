// 给定一组非负整数，您最初位于数组的第一个索引处,
// 数组中的每个元素代表您在该位置的最大跳转长度,
// 确定您是否能够达到最后一个索引。
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool canJump(int A[], int n)
	{
		int reach = 1;//最右能跳到的位置
		for (int i = 0; i < reach && reach < n; ++i)
			reach = max(reach, i + 1 + A[i]);
		return reach >= n;
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
