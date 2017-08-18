#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct 
{
	char name[4];
	int start_time;
	int run_time;
	int turn_around_time;
	int end_time;
	int wait_time;
	double XYB;
	double DQZZ_Time;
}pr;
pr a[MAX];
void input(int n)
{
	int i;
	for(i = 0;i < n;i++)
	{
		printf("name:");
		scanf("%s",&a[i].name);
		printf("\n");
		printf("start_time:");
		scanf("%d",&a[i].start_time);
		printf("\n");
		printf("run_time:");
		scanf("%d",&a[i].run_time);
		printf("\n");
	}
}
//先来先服务
void FCFS(int n)
{
	int i,j,time1,time2;
	char temp[4];
	for(i = 0;i < n-1;i++)
	{
		for(j = 0;j < n-i-1;j++)
			if(a[j].start_time > a[j+1].start_time)
			{
				time1 = a[j].start_time;
				a[j].start_time = a[j+1].start_time;
				a[j+1].start_time = time1;
				time2 = a[j].run_time;
				a[j].run_time = a[j+1].run_time;
				a[j+1].run_time = time2;
				strcpy(temp,a[j].name);
				strcpy(a[j].name,a[j+1].name);
				strcpy(a[j+1].name,temp);
			}
	}
	for(i = 0;i < n;i++)
	{
		if(i == 0)
		{
			a[i].turn_around_time = a[i].run_time;
			a[j].end_time = a[i].start_time + a[i].turn_around_time;
		}
		else
		{
			if(a[i].start_time > a[i-1].end_time)
			{
				a[i].turn_around_time = a[i].run_time;
				a[i].end_time = a[i].start_time + a[i].turn_around_time;
			}
			else
			{
				a[i].turn_around_time= a[i].run_time + a[i-1].end_time-a[i].start_time;
				a[i].end_time = a[i].start_time + a[i].turn_around_time;
			}
		}
		a[i].DQZZ_Time = a[i].turn_around_time*1.0/a[i].run_time;
	}
}
//短作业优先
void SJF(int n)
{
	int i,j,time1,time2;
	int b = 0,c = 0,d = 0;
	char temp[4];
	for(i = 0;i <n-1;i++)
	{
		for(j = 0;j < n-i-1;j++)
			if(a[j].start_time > a[j+1].start_time)
			{
				time1 = a[j].start_time;
				a[j].start_time = a[j+1].start_time;
				a[j+1].start_time = time1;
				time2 = a[j].run_time;
				a[j].run_time = a[j+1].run_time;
				a[j+1].run_time = time2;
				strcpy(temp,a[j].name);
				strcpy(a[j].name,a[j+1].name);
				strcpy(a[j+1].name,temp);
			}
	}
	a[0].end_time = a[0].start_time + a[0].run_time;
	for(i = 1; i < n;i++)
	{
		if(a[i].start_time < a[0].end_time)
			b++;
	}
	for(i = 1;i < b+1;i++)
	{
		for(j = 1;j < b+1-1;j++)
		{
			if(a[j].run_time > a[j+1].run_time)
			{
				time1 = a[j].start_time;
				a[j].start_time = a[j+1].start_time;
				a[j+1].start_time = time1;
				time2 = a[j].run_time;
				a[j].run_time = a[j+1].run_time;
				a[j+1].run_time = time2;
				strcpy(temp,a[j].name);
				strcpy(a[j].name,a[j+1].name);
				strcpy(a[j+1].name,temp);
			}
		}
	}
	if(a[1].start_time > a[0].end_time)
		a[1].end_time = a[1].start_time + a[1].run_time;
	else
		a[1].end_time = a[0].end_time + a[1].run_time;
	for(i = 2;i < n;i++)
	{
		if(a[i].start_time < a[1].end_time)
			c++;
	}
	for(i = 2;i < c+2;i++)
	{
		for(j = 2;j < c+2-1;j++)
		{
			if(a[j].run_time > a[j+1].run_time)
			{
				time1 = a[j].start_time;
				a[j].start_time = a[j+1].start_time;
				a[j+1].start_time = time1;
				time2 = a[j].run_time;
				a[j].run_time = a[j+1].run_time;
				a[j+1].run_time = time2;
				strcpy(temp,a[j].name);
				strcpy(a[j].name,a[j+1].name);
				strcpy(a[j+1].name,temp);
			}
		}
	}
	if(a[2].start_time > a[1].end_time)
		a[2].end_time = a[2].start_time + a[2].run_time;
	else
		a[2].end_time = a[1].end_time + a[2].run_time;
	for(i = 3;i < n;i++)
	{
		if(a[i].start_time < a[2].end_time)
			d++;
	}
	for(j = 3;j < d+3;j++)
	{
		for(j = 3;j < d+3-1;j++)
		{
			if(a[j].run_time > a[j+1].run_time)
			{
				time1 = a[j].start_time;
				a[j].start_time = a[j+1].start_time;
				a[j+1].start_time = time1;
				time2 = a[j].run_time;
				a[j].run_time = a[j+1].run_time;
				a[j+1].run_time = time2;
				strcpy(temp,a[j].name);
				strcpy(a[j].name,a[j+1].name);
				strcpy(a[j+1].name,temp);
			}
		}
	}
	for(i = 0;i < n;i++)
	{
		if(a[i].start_time > a[i-1].end_time)
		{
			a[i].end_time = a[i].start_time + a[i].run_time;
			a[i].turn_around_time = a[i].run_time;
		}
		else
		{
			a[i].end_time = a[i-1].end_time + a[i].run_time;
			a[i].turn_around_time = a[i].end_time - a[i].start_time;
		}
		a[i].DQZZ_Time = a[i].turn_around_time*1.0/a[i].run_time;
	}
}
//最高响应比优先
void HRRF(int n)
{
	int i,j,time1,time2;
	char temp[4];
	for(i = 0;i < n-1;i++)
	{
		for(j = 0;j < n-i-1;j++)
			if(a[j].start_time > a[j+1].start_time)
			{
				time1 = a[j].start_time;
				a[j].start_time = a[j+1].start_time;
				a[j+1].start_time = time1;
				time2 = a[j].run_time;
				a[j].run_time = a[j+1].run_time;
				a[j+1].run_time = time2;
				strcpy(temp,a[j].name);
				strcpy(a[j].name,a[j+1].name);
				strcpy(a[j+1].name,temp);
			}
	}
	a[0].end_time = a[0].start_time + a[0].run_time;
	for(i = 1; i < n;i++)
	{
		a[i].wait_time = a[0].end_time - a[i].start_time;
		a[i].XYB = 1 + (a[i].wait_time/a[i].run_time);
	}
	for(i = 1;i < n-1;i++)
	{
		for(j = 1;j < n-1;j++)
		{
			if(a[j].XYB < a[j+1].XYB)
			{
				time1 = a[j].start_time;
				a[j].start_time = a[j+1].start_time;
				a[j+1].start_time = time1;
				time2 = a[j].run_time;
				a[j].run_time = a[j+1].run_time;
				a[j+1].run_time = time2;
				strcpy(temp,a[j].name);
				strcpy(a[j].name,a[j+1].name);
				strcpy(a[j+1].name,temp);
			}
		}
	}
	a[1].end_time = a[0].end_time + a[1].run_time;
	for(i = 2;i < n;i++)
	{
		a[i].wait_time = a[1].end_time - a[i].start_time;
		a[i].XYB = 1+(a[i].wait_time/a[i].run_time);
	}
	for(i = 2;i < n-1;i++)
	{
		for(j = 2;j < n-i-1;j++)
		{
			if(a[j].XYB < a[j+1].XYB)
			{
				time1 = a[j].start_time;
				a[j].start_time = a[j+1].start_time;
				a[j+1].start_time = time1;
				time2 = a[j].run_time;
				a[j].run_time = a[j+1].run_time;
				a[j+1].run_time = time2;
				strcpy(temp,a[j].name);
				strcpy(a[j].name,a[j+1].name);
				strcpy(a[j+1].name,temp);
			}
		}
	}
	a[2].end_time = a[1].end_time + a[2].run_time;
	for(i = 3;i < n;i++)
	{
		a[i].wait_time = a[2].end_time - a[i].start_time;
		a[i].XYB = 1 + (a[i].wait_time/a[i].run_time); 
	}
	for(i = 3;i < n-1;i++)
	{
		for(j = 3;j < n-i-1;j++)
		{
			if(a[j].XYB < a[j+1].XYB)
			{
				time1 = a[j].start_time;
				a[j].start_time = a[j+1].start_time;
				a[j+1].start_time = time1;
				time2 = a[j].run_time;
				a[j].run_time = a[j+1].run_time;
				a[j+1].run_time = time2;
				strcpy(temp,a[j].name);
				strcpy(a[j].name,a[j+1].name);
				strcpy(a[j+1].name,temp);
			}
		}
	}
	a[3].end_time = a[2].end_time + a[3].run_time;
	for(i = 4;i < n;i++)
	{
		a[i].wait_time = a[3].end_time - a[i].start_time;
		a[i].XYB = 1 + (a[i].wait_time/a[i].run_time);
	}
	for(i = 4;i < n-1;i++)
	{
		for(j = 4;j < n-i-1;j++)
		{
			if(a[j].XYB < a[j+1].XYB)
			{
				time1 = a[j].start_time;
				a[j].start_time = a[j+1].start_time;
				a[j+1].start_time = time1;
				time2 = a[j].run_time;
				a[j].run_time = a[j+1].run_time;
				a[j+1].run_time = time2;
				strcpy(temp,a[j].name);
				strcpy(a[j].name,a[j+1].name);
				strcpy(a[j+1].name,temp);
			}
		}
	}
	for(i = 0;i < n;i++)
	{
		if(a[i].start_time > a[i-1].end_time)
		{
			a[i].end_time = a[i].start_time + a[i].run_time;
			a[i].run_time = a[i].run_time;
		}
		else
		{
			a[i].end_time = a[i-1].end_time + a[i].run_time;;
			a[i].turn_around_time = a[i].end_time - a[i].start_time;
		}
		a[i].DQZZ_Time = a[i].turn_around_time*1.0/a[i].run_time;
	}
}
void output(int n)
{
	int sum_Time = 0;
	double sum_DQ = 0;
	int i;
	printf("\tname   start_time    run_time   turn_around_time   end_time  \tDQZZ_Time\n");
	for(i = 0;i < n;i++)
	{
		printf("%10s%11d%13d%12d%18d\t%10lf\n",a[i].name,a[i].start_time,a[i].run_time,a[i].turn_around_time,a[i].end_time,a[i].DQZZ_Time);
		sum_Time += a[i].run_time;
		sum_DQ += a[i].DQZZ_Time;
	}
	printf("平均作业周转时间为:%.2lf\n",sum_Time*1.0/n);
	printf("平均带权作业周转时间为:%.2lf\n",sum_DQ*1.0/n);
	printf("\n");
}