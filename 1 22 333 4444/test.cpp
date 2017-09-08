#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n = 0;
	cin >> n;
	long long num = sqrt(n);
	while (num*num + num < 2 * n)
	{
		++num;
	}
	cout << num << endl;
	system("pause");
	return 0;
}