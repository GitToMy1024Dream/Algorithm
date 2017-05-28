#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <Windows.h>
enum State
{
	NORMAL,	  //����
	UNNORMAL  //�쳣
}state;
state = UNNORMAL; //����ʼ״̬��Ϊ�쳣
int my_atoi(const char *str)
{
	int flag = 1;
	long long ret = 0;
	assert(str);
	while(*str == ' ') //�����ո������
	{
		str++;
	}
	if(*str == '\0')   //�ַ����Ѿ������ֱ꣬�ӷ���0
		return 0;
	if(*str == '+')		//�ж�����
		str++;
	else if(*str == '-') //�жϸ���
	{
		flag = -1;		 //Ϊ����ʱ���ȼ�¼״̬
		str++;
	}
	while(*str >= '0' && *str <= '9')	  //���ַ�����ת��������
	{
		ret = ret * 10 + flag*(*str - '0');
		if(ret >= INT_MAX || ret <= INT_MIN)  //����������������ѭ��
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
		printf("�쳣����\n");
	printf("%d\n",ret);
	system("pause");
	return 0;
}