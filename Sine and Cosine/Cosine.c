#include <stdio.h>
#include <math.h>
#include <windows.h>
int main()
{
	int m = 0;
	int x = 0;
	double y = 0;
	system("color 3e");
	for(y = 1;y >= -1;y -= 0.1)	//yΪ�з���ֵ��Ϊ[-1,1],����Ϊ0.1
	{
		m = acos(y) * 10; //�����y��Ӧ�Ļ���m������10�����Ŵ�ͼ��10��
		for(x = 1;x < m;x++)
		{
			printf(" ");
		}
		printf("*"); //���ƴ�ӡ����*��
			for(;x < 62-m;x++)
			{
				printf(" ");
			}
			printf("*\n"); //���ƴ�ӡͬһ�ж�Ӧ���Ҳ�*��
	} 
	system("pause");
	return 0;
}