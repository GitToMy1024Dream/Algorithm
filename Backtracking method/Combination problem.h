#pragma once
#include <iostream>
#include <vector>
using namespace std;
vector<int> _v;
void find_ans(vector<int> ret, size_t pos, size_t N, size_t res, size_t sum)
{
	//�Ѿ�����������ֱ���˳�
	if (pos >= N)
		return;
	res += _v[pos];
	ret.push_back(_v[pos]);
	//��ǰ����Ҫ��ĺ����
	if (res == sum)
	{
		for (size_t idx = 0; idx < ret.size(); ++idx)
			cout << ret[idx] << " ";
		cout << endl;
		return;
	}
	//����Ҫ��ĺ�ʱ�����м�֦����
	else if (res > sum)
		return;
	//����ǰֵ����ret�У�������һ��
	find_ans(ret, pos + 1, N, res, sum);
	//��Ҫ��ǰֵ������һ��λ������
	vector<int>::iterator it = ret.end() ;
	--it;
	ret.erase(it);
	find_ans(ret, pos + 1, N, res - _v[pos], sum);
}
