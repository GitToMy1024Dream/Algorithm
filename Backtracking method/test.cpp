#include "packet.h"
int main() 
{
	size_t N = 0;//最大下标
	size_t sum = 0;//要求的结果
	cout << "Please enter N and num: ";
	cin >> N >> sum;
	for (size_t idx = 0; idx < N; ++idx)
	{
		_v.push_back(idx + 1);
	}
	if (N >= sum)
		N = sum;
	vector<int> ret;//存放序列的数组
	size_t result = 0;//当前求和的结果
	find_ans(ret, 0, N, result, sum);
	system("pause");
	return 0;
}