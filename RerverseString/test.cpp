//#include<stdio.h>
//#include<Windows.h>
//#include<assert.h>
//int  str_len(char *str)        //����ĳ���
//{
//	int count = 0;
//	assert(str);
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}
//
//void reverse(char *start, char *end)     //���������ַ�����
//{
//	assert(start&&end);                 //������β�߼���Ϊ�汣֤���鲻Ϊ��
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//
//void str_reverse(char *str)
//{
//	int len = str_len(str);         //������ĳ���
//	assert(str);                   //��֤���鲻Ϊ��
//	reverse(str, str + len - 1);
//	while (*str != '\0')
//	{
//		char *pos = str;
//		while ((*str != ' ') && (*str != '\0'))
//		{
//			str++;
//		}
//		reverse(pos, str - 1);    //����ÿ���ַ�����
//		if (*str != '\0')
//			str++;
//	}
//}
//
//int main()
//{
//	char str[] = "much very me love you";
//	str_reverse(str);
//	printf("%s\n", str);
//	system("pause");
//	return 0;
//}




//#include <math.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <limits.h>
//#include <stdbool.h>
//#pragma warning (disable:4996)
//
///*������������������ʵ����ĿҪ��Ĺ���
//��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
//******************************��ʼд����******************************/
//int str_len(char* input)
//{
//	int count = 0;
//	while (*input++)
//	{
//		++count;
//	}
//	return count;
//}
//void my_reverse(char* start, char* end)
//{
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//char* convert(char* input) {
//	int len = str_len(input);
//	my_reverse(input, input + len - 1);
//	char* ret = input;
//	while (*input != '\0')
//	{
//		char *pos = input;
//		while ((*input != ' ') && (*input != '\0'))
//		{
//			++input;
//		}
//		my_reverse(pos, input - 1);
//		if (*input != '\0')
//			++input;
//	}
//	return ret;
//}
///******************************����д����******************************/
//
//
//int main() {
//	char* res;
//
//	char* _input;
//	_input = (char *)malloc(512000 * sizeof(char));
//	scanf("\n%[^\n]", _input);
//
//	res = convert(_input);
//	printf("%s\n", res);
//	system("pause");
//	return 0;
//
//}



