#include <stdio.h>
#include <math.h>
#include <windows.h>
int main()
{
	int m = 0;
	int x = 0;
	double y = 0;
	system("color 3e");
	for(y = 1;y >= -1;y -= 0.1)	//y为列方向，值域为[-1,1],步长为0.1
	{
		m = acos(y) * 10; //计算出y对应的弧度m，乘以10，即放大图像10倍
		for(x = 1;x < m;x++)
		{
			printf(" ");
		}
		printf("*"); //控制打印左侧的*号
			for(;x < 62-m;x++)
			{
				printf(" ");
			}
			printf("*\n"); //控制打印同一行对应的右侧*号
	} 
	system("pause");
	return 0;
}