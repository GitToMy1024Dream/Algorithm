#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <Windows.h>
enum State
{
	NORMAL,	  //正常
	UNNORMAL  //异常
}state;
state = UNNORMAL; //将初始状态赋为异常
int my_atoi(const char *str)
{
	int flag = 1;
	long long ret = 0;
	assert(str);
	while(*str == ' ') //遇到空格就跳过
	{
		str++;
	}
	if(*str == '\0')   //字符串已经遍历完，直接返回0
		return 0;
	if(*str == '+')		//判断正数
		str++;
	else if(*str == '-') //判断负数
	{
		flag = -1;		 //为负数时，先记录状态
		str++;
	}
	while(*str >= '0' && *str <= '9')	  //将字符数字转换成整型
	{
		ret = ret * 10 + flag*(*str - '0');
		if(ret >= INT_MAX || ret <= INT_MIN)  //如果存在溢出，跳出循环
			break;
		str++;
	}
	if(*str == '\0')
		state = NORMAL;
	return (int)ret;
}
int main()
{
	char arr[30] = {0};
	int ret = 0;
	scanf("%s",arr);
	ret = my_atoi(arr);
	if(state == UNNORMAL)
		printf("异常返回\n");
	printf("%d\n",ret);
	system("pause");
	return 0;
}