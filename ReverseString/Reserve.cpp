#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> _v;
	int value = 0;
	while (n-- && cin >> value)
	{
		_v.push_back(value);
		reverse(_v.begin(), _v.end());
	}
	for (int i = 0; i < _v.size(); ++i)
	{
		cout << _v[i] << " ";
	}
	system("pause");
	return 0;
}