//#include <iostream>
//using namespace std;
//
//void Reverse(char* arr, int begin, int end)
//{
//	while (begin < end)
//	{
//		char tmp = arr[begin];
//		arr[begin] = arr[end];
//		arr[end] = tmp;
//		++begin;
//		--end;
//	}
//}
//
//void leftRotate(char* arr, int n, int k)
//{
//	if (arr != NULL)
//	{
//		Reverse(arr, 0, k - 1);
//		Reverse(arr, k, n - 1);
//		Reverse(arr, 0, n - 1);
//	}
//}
//
//int main()
//{
//	int k = 0;
//	cin >> k;
//	char arr[] = "abcdefgh";
//	int len = strlen(arr);
//	k %= len;
//	leftRotate(arr, len, k);
//	for (int i = 0; i < len; ++i)
//	{
//		cout << arr[i];
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void Reverse(string& str, int begin, int end)
	{
		while (begin < end)
		{
			char tmp = str[begin];
			str[begin] = str[end];
			str[end] = tmp;
			++begin;
			--end;
		}
	}

	string LeftRotateString(string str, int n) {
		int len = str.size();
		n %= len;
		Reverse(str, 0, n - 1);
		Reverse(str, n, len - 1);
		Reverse(str, 0, len - 1);
		return str;
	}
};

int main()
{
	Solution a;
	string arr = "abcdefg";
	string ret = a.LeftRotateString(arr, 2);
	cout << ret << endl;
	system("pause");
	return 0;
}