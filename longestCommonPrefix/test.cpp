#include <iostream>
using namespace std;
#include <string>
#include <vector>

string longestCommonPrefix(vector<string>& str)
{
	if (str.empty())
		return "";
	string res;
	for (int i = 0; i < str[0].size(); ++i) //�ǰ׺�ĳ��Ȳ�����str[0].size()������ַ��ıȽ�
	{
		for (int j = 1; j < str.size(); ++j)//strs[0]�ĵ�i���ַ��ֱ��str[1...n-1]�ĵ�i���ַ��Ƚ�
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