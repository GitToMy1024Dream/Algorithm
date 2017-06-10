#include <stdio.h>
#include <Windows.h>
#include <math.h>
int main()
{
	int x;
	int n;
	double y;
	for(y = 1; y > -1;y -= 0.1)
	{
		n = asin(y)*10;
		if(1 <= n && n <= 15 )	 //y轴正半轴
		{
			for(x = 1;x < n;x++)	 //1/4周期
			{
				printf(" ");
			}
			printf("*");
			for(;x < 30 - n;x++)	//2/4周期
			{
				printf(" ");
			}
			printf("*\n");
		}
		else if(-15 <= n && n <= -1)	//y轴负半轴
		{
			for(x = 1;x < 31 - n;x++)	//3/4周期
			{
				printf(" ");
			}
			printf("*");
			for(;x < 61 + n;x++)		//4/4周期
			{
				printf(" ");
			}
			printf("*\n");
		}
	}
	system("pause");
	return 0;
}






