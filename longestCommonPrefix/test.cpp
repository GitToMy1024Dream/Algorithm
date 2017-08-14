#include <iostream>
using namespace std;
#include <string>
#include <vector>

string longestCommonPrefix(vector<string>& str)
{
	if (str.empty())
		return "";
	string res;
	for (int i = 0; i < str[0].size(); ++i) //最长前缀的长度不超过str[0].size()，逐个字符的比较
	{
		for (int j = 1; j < str.size(); ++j)//strs[0]的第i个字符分别和str[1...n-1]的第i个字符比较
		{
			if (str[j].size() == i || str[0][i] != str[j][i])
				return res;
		}
		res.push_back(str[0][i]);
	}
	return res;
}

int main()
{
	char* a[] = { "abcfgg","abcss","abcwe","abcll" };
	longestCommonPrefix(a);
	system("pause");
	return 0;
}