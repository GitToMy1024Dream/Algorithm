//#include <iostream>
//using namespace std;
//
//struct ListNode
//{
//	ListNode* _left;
//	ListNode* _right;
//	int _data;
//};
//
//int IsBinarySearchTree(ListNode)
//{
//
//}
//#include <iostream>
//using namespace std;
//
//long MulNumber(long x, long y, long m)
//{
//	if (x <= 0 || y <= 0 || m <= 0)
//		return 0;
//	long r = 1;
//	x %= m;
//	while (y > 1)
//	{
//		if ((y & 1) != 0)
//			r = (r*x) % m;
//		x = (x*x) % m;
//		y >>= 1;
//	}
//	return (r*x) % m;
//}
//int main()
//{
//	int x = 0, y = 0, c = 0;
//	cin >> x >> y >> c;
//	cout << MulNumber(x, y, c) << endl;
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//long long x, y, z;
//long long Mul(long long x, long long y, long long c)
//{
//	long long ans = 0;
//	while (y)
//	{
//		if (y & 1)
//		{
//			y--; ans += x; ans %= c;
//		}
//		y >>= 1; x <<= 1; x %= c;
//	}
//	return ans;
//}
//long long funcTion(long long x, long long y, long long z) {
//	if (x <= 0 || y <= 0 || z <= 0)
//		return 0;
//	long long res = 1;
//	while (y) {
//		if (y & 1) res = Mul(res, x, z);
//		x = Mul(x, x, z);
//		y >>= 1;
//	}
//	return res;
//}
//int main()
//{
//	while (cin >> x >> y >> z) {
//		if (!x)printf("0\n");
//		else if (!y) {
//			cout << 1 % z; printf("\n");
//		}
//		else {
//			cout << funcTion(x, y, z);
//			cout << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//
//int main()
//{
//	string _s;
//	int n = 0;
//	cin >> n;
//	vector<string> vec;
//	vector<string> vec2;
//	while (n--)
//	{
//		cin >> _s;
//		vec.push_back(_s);
//	}
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		int left = 0;
//		while (left < vec[i].size())
//		{
//			while (vec[i] != to_string(':'))
//				++left;
//			++left;
//			if (vec[left] != to_string('-1'))
//				vec2.push_back(vec[left]);
//			left += 2;
//			if(vec[left] != to_string('-1'))
//				vec2.push_back(vec[left + 1]);
//		}
//	}
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<stdio.h>
//using namespace std;
//
//int main()
//{
//	string _s;
//	while (1)
//	{
//		char m;
//		scanf("%c", &m);
//		if (m != ' '&&m != '\n')
//			_s += m;
//		if (m == '\n')
//			break;
//	}
//
//	int k = 0;
//	cin >> k;
//	sort(_s.begin(), _s.end());
//	for (int i = 0; i < k; i++)
//	{
//		cout << _s[i] << " ";
//	}
//	cout << endl;
//
//	for (int i = 0; i < k; i++)
//	{
//		cout << _s[_s.size() - 1 - i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str;
//	char ss;
//	cin >> str >> ss;
//	int len = str.size();
//	for (int i = 0; i < len; ++i)
//	{
//		if (str[i] == ss)
//		{
//			i++;
//			cout << endl;
//		}
//		cout << str[i];
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}



