/*
给定一个字符串，确定它是否是回文，只考虑字母数字字符和忽略大小写。
例如
“A man, a plan, a canal: Panama”是一个回文。
“race a car”不是回文。

分析：从两头往中间扫*/
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
	bool isPalindrome(string s)
	{
		int i, j;
		for (i = 0, j = s.length() - 1; i < j;)
		{
			while (i < j && !isalnum(s[i]))//isalnum判断是否为字符或数字
				++i;
			while (i < j && !isalnum(s[j]))
				--j;
			if (i < j && tolower(s[i]) != tolower(s[j]))//将字符转为小写
				return false;
			++i; 
			--j;
		}
		return true;
	}
};

int main()
{
	Solution s;
	string arr = "A man,a plan,a canal: Panama";
	cout << s.isPalindrome(arr) << endl;
	system("pause");
	return 0;
}