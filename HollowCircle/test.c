#include <stdio.h>
#include <Windows.h>
#include <math.h>
int main()
{
	double y;
	int x,m;
	for(y = 10;y >= -10;y--)//10ΪԲ�İ뾶
	{
		m = 2.5*sqrt(100 - y * y);
    //������y��Ӧ��������m��2.5����Ļ�ݺ�ȵ���ϵ��
	//��Ϊ��Ļ���о�����о࣬�����ڻ���ʾ��Բ
		for(x = 1;x < 50 - m;x++)
		{		 
			printf(" ");//ͼ�����Ŀհ�
		}
		printf("*");	//Բ�����
		for(;x < 50 + m;x++)
		{
			printf(" ");//ͼ���Ҳ�Ŀհ�
		}
		printf("*\n");	//Բ���Ҳ�
	}
	system("pause");
	return 0;
}