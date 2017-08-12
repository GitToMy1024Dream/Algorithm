#include"iostream"
#include"set"
using namespace std;

int main()
{
	int n, a;
	set <int> _s;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> a;
		_s.insert(a);
	}
	set <int>::iterator it;
	int num = 0;
	for (it = _s.begin(); it != _s.end(); it++)
	{
		num++;
		if (num == 3)
			cout << *it << endl;
	}
	if (num<3)  cout << "-1" << endl;
	system("pause");
	return 0;
}