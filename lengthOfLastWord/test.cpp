/* ����һ���ַ����ɴ�/Сд��ĸ�Ϳհ��ַ���ɣ�
�������һ���ֵĳ��ȣ�������һ���ֲ����ڣ��򷵻�0.
ע�⣺һ���ֱ�����Ϊ���ɷǿո��ַ���ɵ��ַ����С� 
���磬����s = ��Hello World��������5��*/

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