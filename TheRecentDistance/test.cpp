#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n, val;
	cin >> n;
	vector<int> _v;
	map<int,int> _m;
	for (int i = 0; i < n; ++i)
	{
		cin >> val;
		_v.push_back(val);
		_m[val] = i;
	}
	sort(_v.begin(), _v.end());

	int index = n;
	int count = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (_m[_v[i]] > _m[_v[i + 1]])
		{
			_m[_v[i + 1]] = index++;
			count++;
		}
	}
	cout << count << endl;

	system("pause");
	return 0;
}