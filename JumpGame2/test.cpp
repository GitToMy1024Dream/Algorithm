//JumpGame2����С�����ﵽ���һ������

#include <iostream>
using namespace std;

class Solution
{
public:
	int jump(int A[], int n)
	{
		int step = 0;//��С����
		int left = 0;
		int right = 0; //[left,right]��ǰ�ܸ��ǵ�����
		if (n == 1)
			return 0;
		//���Դ�ÿһ������Զ
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