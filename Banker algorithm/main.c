#include "banker.h"
void MaxProcess(int *p,int *r)			   //各资源总的资源数
{
	int i = 0;
	int j = 0;
	char k = 'A';
	printf("请输入各资源最大资源数:\n");
	for (i = 0;i < (*r) ;i++)
	{
		printf("%c:",k++);
		scanf("%d",&Resource[i]);
	}
}
void AllocationProcess(int *p,int *r)		//已分配的资源数
{
	int i = 0;
	int j = 0;
	int k = 1;
	int g = 0;
	char m = 'A';
	printf("请输入已分配各资源的数目:\n");
	printf("       ");
	for(g = 0;g < (*r);g++)
	{
		printf("%c  ",m++);
	}
	printf("\n");
	for(i = 0; i < (*p);i++)
	{
		printf("进程%d:",k++);
		for(j = 0;j < (*r);j++)
		{
			scanf("%d",&Allocation[i][j]);
		}
	}
}
void MaxNeedProcess(int *p,int *r)		  //各进程需求的最大资源数
{
	int i = 0;
	int j = 0;
	int k = 1;
	int g = 0;
	char m = 'A';
	printf("请输入各进程需求的最大资源数的:\n");
	printf("       ");
	for(g = 0;g < (*r);g++)
	{
		printf("%c  ",m++);
	}
	printf("\n");
	for(i = 0; i < (*p);i++)
	{
		printf("进程%d:",k++);
		for(j = 0;j < (*r);j++)
		{
			scanf("%d",&MaxNeed[i][j]);
		}
	}
}
void NeedProcess(int *p,int *r)
{
	int i = 0;
	int j = 0;
	int k = 1;
	int g = 0;
	char m = 'A';
	printf("各进程还需求的资源数为:\n");
	printf("       ");
	for(g = 0;g < (*r);g++)
	{
		printf("%c  ",m++);
	}
	printf("\n");
	for(i = 0; i < (*p);i++)
	{
		printf("进程%d:",k++);
		for(j = 0;j < (*r);j++)
		{
			Need[i][j] = MaxNeed[i][j] - Allocation[i][j];
			printf("%d ",Need[i][j]);
		}
		printf("\n");
	}
}
void AvailableProcess(int *p,int *r) //可用的资源数
{
	int i = 0;
	int j = 0;
	int k = 0;
	char m = 'A';
	int s = 0;
	int arr[rows];
	for(s = 0; s < (*r);s++)
	{
		arr[s] = Resource[s];
	}
	printf("剩余可用资源为:\n");
	for(i = 0; i < (*r);i++)
	{
		printf("%c ",m++);
	}
	printf("\n");
	for(i = 0;i < (*r);i++)
	{
		for(j = 0;j < (*p);j++)
		{
			arr[i] -= Allocation[j][i]; 
		}
	}
		for(i = 0 ;i < (*r);i++)
		{
			Available[i] = arr[i];
		}
		for(i = 0 ; i < (*r);i++)
		{
			printf("%d ",Available[i]);
		}
			printf("\n");
}
int Compare(int *p,int *r,int j)  //返回进程的返回值
{
	int i = 0;
	int flag;
	for(i = 0; i < (*r);i++)
	{
		if(Need[j][i] > Available[i])
		{
				return 0;
		}
	}
				return 1;
}
int SafeCheck(int *p,int *r)  //安全检查
{
	int i = 0;
	int j = 0;
	int k = 0;
	int buff[rows] = {0};  //print number
	int cook[rows] = {false}; //panduan F T
	for(i = 0;i <(*p);i++)
	{
		for(j = 0;j < (*p);j++)
		{
			if(cook[j] == true)
				continue;
			else
			{
				if(Compare(p,r,j))
				{
					cook[j] = true;
					for(k = 0; k < (*r);k++)
					{
						Available[k] += Allocation[j][k];
					}
 
					break;
				}
			}
		}
		buff[i] = j + 1;
	}
	for(i = 0;i < (*p);i++)
	{
		if(cook[i] == false)
				{
					printf("The system is unsafe!");
					return 0;
		        }
	}
		
			printf("The system is safe!\n");
			printf("The safe_number is:");
			for(i = 0; i < (*p);i++)
			{
				printf("%d ",buff[i]);
			}
			printf("\n");
			return 1;
}
void Select(int *p, int *r)
{
	int select = 0;
	printf("1->Request    2->Insert    3->Quit\n");
	printf("请选择你要执行的操作：");
	scanf("%d",&select);
	switch(select)
	{
		case 1:
			Request(p,r);
			break;
		case 2:
			Insert(p,r);
			break;
		case 3:
			Exit();
			break;
	}
}
void Insert(int *p,int *r)
{
	int i = 0;
	int j = 0;
 
	int Old = (*p);
	int New = *p + 1;
	char c = 'A';
	char d = 'A';
	for(i = Old;i < New;i++)
	{
		printf("进程%d的已分配资源分别为：",New);
		for(i = 0; i < (*r);i++)
		{
			printf("%c ",c++);
		}
		printf("->");
		for(i = Old;i < New;i++)
		{
 
			for(j = 0;j < (*r);j++)
				{
					scanf("%d",&Allocation[i][j]);
				}
		}
		printf("进程%d的最大需求资源分别为：",New);
		for(i = 0;i < (*r);i++)
		{
			printf("%c ",d++);
		}
		printf("->");
		for(i = Old;i < New;i++)
		{
			for(j = 0;j < (*r);j++)
				{
					scanf("%d",&MaxNeed[i][j]);
				}
		}
			(*p)++;
			NeedProcess(p,r);
			AvailableProcess(p,r);
			SafeCheck(p,r); 
			Select(p,r);
	}
	
}
void Exit()
{
	printf("bye bye ...");
	exit(0);
}
void Request(int *p,int *r)  //请求资源
{
		int ret;
		int Request[rows];
		int Num;
		int i = 0;
		int j = 0;
		int name = 0;
			printf("请输入要申请资源进程的编号：");
			scanf("%d",&Num);
			printf("请输入该进程所需的各类资源的数目：");
				for (i = 0; i < (*r); ++i)
				{
					scanf("%d",&Request[i]);
						if (Request[i] > Need[Num-1][i])
							{
								printf("请求的资源大于所需要资源数目，无法分配！\n");
								return;
							}
						else if (Request[i] > Available[i] )
							{
								printf("请求的资源大于可分配资源数目，无法分配！\n");
								return;
									}
				}
					for (i = 0; i < (*r); ++i)
						{
							Available[i] -= Request[i];
							Allocation[Num-1][i] += Request[i];
							Need[Num-1][i] -= Request[i];
						}
						ret = SafeCheck(p,r);
						if(!ret)
							{
								for (i = 0; i < (*r); ++i)
									{
										Available[i] += Request[i];
										Allocation[Num-1][i] -= Request[i];
										Need[Num-1][i] += Request[i];
									}
						    }
						else
						{
							NeedProcess(p,r);
							AvailableProcess(p,r);
							SafeCheck(p,r);
							Select(p, r);
						}
						
						
}
int main()
{
	int p = 0;//进程
	int r = 0;//资源种类
	int i = 0;
	system("color 3e"); 
	printf("请输入进程数:");
	scanf("%d",&p);
	printf("请输入资源种类的个数:");
	scanf("%d",&r);
	MaxProcess(&p,&r);
	AllocationProcess(&p,&r);
	MaxNeedProcess(&p,&r);
	NeedProcess(&p,&r);
	AvailableProcess(&p,&r);
	SafeCheck(&p,&r);
	Select(&p,&r);
	system("pause");		 
	return 0;
}