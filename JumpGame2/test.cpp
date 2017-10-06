//JumpGame2以最小跳数达到最后一个索引

#include <iostream>
using namespace std;

class Solution
{
public:
	int jump(int A[], int n)
	{
		int step = 0;//最小步数
		int left = 0;
		int right = 0; //[left,right]当前能覆盖的区域
		if (n == 1)
			return 0;
		//尝试从每一层跳最远
		while (left <= right)
		{
			++step;
			const int old_right = right;
			for (int i = left; i <= old_right; ++i)
			{
				int new_right = i + A[i];
				if (new_right >= n - 1)
					return step;
				if (new_right > right)
					right = new_right;
			}
			left = old_right + 1;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	int arr[] = { 2,3,1,1,4 };
	cout << s.jump(arr, 5) << endl;
	system("pause");
	return 0;
}