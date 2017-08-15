/* 给定一个字符串由大/小写字母和空白字符组成，
返回最后一个字的长度，如果最后一个字不存在，则返回0.
注意：一个字被定义为仅由非空格字符组成的字符序列。 
例如，给定s = “Hello World”，返回5。*/

#include <iostream>
using namespace std;

int lengthOfLastWord(const char* s)
{
	int len = 0;
	while (*s) {
		if (*s++ != ' ') {
			len++;
		}
		else if (*s && *s != ' ') {
			len = 0;
		}
	}
	return len;
}

int main()
{
	char arr[] = "hello my web";
	int ret = lengthOfLastWord(arr);
	cout << ret << endl;
	system("pause");
	return 0;
}