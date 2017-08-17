#include <stdio.h>
#include <Windows.h>
#include <math.h>
int main()
{
	double y;
	int x,m;
	for(y = 10;y >= -10;y--)//10为圆的半径
	{
		m = 2.5*sqrt(100 - y * y);
    //计算行y对应的列坐标m，2.5是屏幕纵横比调节系数
	//因为屏幕的行距大于列距，不调节会显示椭圆
		for(x = 1;x < 50 - m;x++)
		{		 
			printf(" ");//图形左侧的空白
		}
		printf("*");	//圆的左侧
		for(;x < 50 + m;x++)
		{
			printf(" ");//图形右侧的空白
		}
		printf("*\n");	//圆的右侧
	}
	system("pause");
	return 0;
}