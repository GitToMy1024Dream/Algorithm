#pragma once
#include <iostream>
#include <vector>
using namespace std;
vector<int> _v;
void find_ans(vector<int> ret, size_t pos, size_t N, size_t res, size_t sum)
{
	//已经遍历结束，直接退出
	if (pos >= N)
		return;
	res += _v[pos];
	ret.push_back(_v[pos]);
	//当前和与要求的和相等
	if (res == sum)
	{
		for (size_t idx = 0; idx < ret.size(); ++idx)
			cout << ret[idx] << " ";
		cout << endl;
		return;
	}
	//大于要求的和时，进行剪枝操作
	else if (res > sum)
		return;
	//将当前值放入ret中，继续下一个
	find_ans(ret, pos + 1, N, res, sum);
	//不要当前值，从下一个位置搜索
	vector<int>::iterator it = ret.end() ;
	--it;
	ret.erase(it);
	find_ans(ret, pos + 1, N, res - _v[pos], sum);
}
