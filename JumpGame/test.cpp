// ����һ��Ǹ������������λ������ĵ�һ��������,
// �����е�ÿ��Ԫ�ش������ڸ�λ�õ������ת����,
// ȷ�����Ƿ��ܹ��ﵽ���һ��������
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool canJump(int A[], int n)
	{
		int reach = 1;//������������λ��
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
