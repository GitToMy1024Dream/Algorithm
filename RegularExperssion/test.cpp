#include <iostream>
using namespace std;
#include <string>

bool IsMatch(const char* s, const char* p)
{
	if (*p == '\0')
		return *s == '\0';
	//��һ���ַ�����*
	if (*(p + 1) != '*')
	{
		//s��p��Ȼ�p�ĵ�ǰ�ַ�Ϊƥ�����ⵥ���ַ�ʱ��һ��������
		if (*p == *s || (*p == '.' && *s != '\0'))
			return IsMatch(s + 1, p + 1);
		return false;
	}
	//��һ���ַ���*
	else
	{
		//s��p��Ȼ�ǰ�ַ�Ϊ.������һ���ַ�Ϊ*ʱ
		while (*p == *s || (*p == '.' && *s != '\0'))
		{
			//����������ַ�ƥ�䣬�򷵻�true,����s������
			if (IsMatch(s, p + 2))
				return true;
			++s;
		}
		return IsMatch(s, p + 2);
	}
}

int main()
{
	/*char* s = "abc";
	char* p = "..c";*/
	char* s = "aab";
	char* p = "c*a*b";
	cout << IsMatch(s, p) << endl;
	system("pause");
	return 0;
}