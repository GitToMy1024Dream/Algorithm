#include "packet.h"
int main() 
{
	size_t N = 0;//����±�
	size_t sum = 0;//Ҫ��Ľ��
	cout << "Please enter N and num: ";
	cin >> N >> sum;
	for (size_t idx = 0; idx < N; ++idx)
	{
		_v.push_back(idx + 1);
	}
	if (N >= sum)
		N = sum;
	vector<int> ret;//������е�����
	size_t result = 0;//��ǰ��͵Ľ��
	find_ans(ret, 0, N, result, sum);
	system("pause");
	return 0;
}