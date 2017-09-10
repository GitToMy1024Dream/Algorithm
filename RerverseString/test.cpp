//#include<stdio.h>
//#include<Windows.h>
//#include<assert.h>
//int  str_len(char *str)        //数组的长度
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
//void reverse(char *start, char *end)     //逆置整个字符数组
//{
//	assert(start&&end);                 //数组收尾逻辑与为真保证数组不为空
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
//	int len = str_len(str);         //求数组的长度
//	assert(str);                   //保证数组不为空
//	reverse(str, str + len - 1);
//	while (*str != '\0')
//	{
//		char *pos = str;
//		while ((*str != ' ') && (*str != '\0'))
//		{
//			str++;
//		}
//		reverse(pos, str - 1);    //逆置每个字符数组
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
///*请完成下面这个函数，实现题目要求的功能
//当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
//******************************开始写代码******************************/
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
///******************************结束写代码******************************/
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



