/*
����һ���ַ�����ȷ�����Ƿ��ǻ��ģ�ֻ������ĸ�����ַ��ͺ��Դ�Сд��
����
��A man, a plan, a canal: Panama����һ�����ġ�
��race a car�����ǻ��ġ�

����������ͷ���м�ɨ*/
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
			while (i < j && !isalnum(s[i]))//isalnum�ж��Ƿ�Ϊ�ַ�������
				++i;
			while (i < j && !isalnum(s[j]))
				--j;
			if (i < j && tolower(s[i]) != tolower(s[j]))//���ַ�תΪСд
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