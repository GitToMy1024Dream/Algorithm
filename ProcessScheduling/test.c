#include"achieve.h"
int main()
{
	int n,i;
	printf("请输入进程数n:");
	scanf("%d",&n);
	input(n);
	output(n);
	while(1)
	{
		printf("1.FCFS\n2.SJF\n3.HRRN\n4.EXIT\n");
		scanf("%d",&i);
		if(i == 1)
		{
			printf("\t\t\t\t1.FCFS\n");
			FCFS(n);
			output(n);
		}
		if(i == 2)
		{
			printf("\t\t\t\t2.SJF\n");
			SJF(n);
			output(n);
		}
		if(i == 3)
		{
			printf("\t\t\t\t3.HRRN\n");
			HRRF(n);
			output(n);
		}
		if(i == 4)
		{
			exit(0);
		}
	}
}