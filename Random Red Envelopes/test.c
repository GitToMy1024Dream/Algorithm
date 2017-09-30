#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
int main(void)
{
	float total;
	int num;
	float min;
	float safe_total;
	float money;
	int i;
	printf("输入总钱数:\n");
	scanf("%f",&total);
	printf("输入红包数量:\n");
	scanf("%d",&num);
	min=0.01;
	srand((unsigned)time(NULL));
	for(i=1;i<num;i++){
		safe_total=(total-(num-i)*min)/(num-1);
		money=(float)(rand()%((int)(safe_total*100)))/100+min;
		total=total-money;
		printf("红包%2d:%.2f元,余额：%.2f元\n",i,money,total);
	}
	printf("红包%2d:%.2f元,余额：0.00元\n",num,total);
	system("pause");
	return 0;
}