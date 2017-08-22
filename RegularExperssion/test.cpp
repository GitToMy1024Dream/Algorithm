#include <iostream>
using namespace std;
#include <string>

bool IsMatch(const char* s, const char* p)
{
	if (*p == '\0')
		return *s == '\0';
	//下一个字符不是*
	if (*(p + 1) != '*')
	{
		//s和p相等或p的当前字符为匹配任意单个字符时，一起向后遍历
		if (*p == *s || (*p == '.' && *s != '\0'))
			return IsMatch(s + 1, p + 1);
		return false;
	}
	//下一个字符是*
	else
	{
		//s和p相等或当前字符为.，且下一个字符为*时
		while (*p == *s || (*p == '.' && *s != '\0'))
		{
			//如果第三个字符匹配，则返回true,否则s向后遍历
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