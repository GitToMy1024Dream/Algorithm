#include <iostream>
using namespace std;

bool IsNumberic(char* str)
{
	if (str == NULL)
		return false;
	if (*str == '+' || *str == '-')
		++str;
	if (*str == '\0')
		return false;
	int x = 0;    //标记整数部分
	int digit = 0; //标记小数点
	int e = 0;     //标记e的状态
	while (*str != '\0')
	{
		//标记整数部分的状态
		if (*str >= '0' && *str <= '9')
		{
			++str;
			x = 1;
		}
		//小数点
		else if (*str == '.')
		{
			//前面已经出现过小数点或小数点之前存在e，则返回false
			if (digit > 0 || e > 0)
				return false;
			++str;
			digit = 1;    //标记小数点已经出现过
		}

		//e
		else if (*str == 'e' || *str == 'E')
		{
			//e之前没有整数或e已经出现过，则返回false
			if (x == 0 || e > 0)
				return false;
			++str;
			e = 1;     //标记e表示已经出现过

			//e之后可以出现+-号再加整数
			if (*str == '+' || *str == '-')
				++str;
			if (*str == '\0')
				return false;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	char arr[32] = { 0 };
	while (cin >> arr)
	{
		if (IsNumberic(arr))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	system("pause");
	return 0;
}
