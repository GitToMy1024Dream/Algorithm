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
	printf("������Ǯ��:\n");
	scanf("%f",&total);
	printf("����������:\n");
	scanf("%d",&num);
	min=0.01;
	srand((unsigned)time(NULL));
	for(i=1;i<num;i++){
		safe_total=(total-(num-i)*min)/(num-1);
		money=(float)(rand()%((int)(safe_total*100)))/100+min;
		total=total-money;
		printf("���%2d:%.2fԪ,��%.2fԪ\n",i,money,total);
	}
	printf("���%2d:%.2fԪ,��0.00Ԫ\n",num,total);
	system("pause");
	return 0;
}