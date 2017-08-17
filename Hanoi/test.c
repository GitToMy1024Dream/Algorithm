#include<stdio.h>  // 汉诺塔的最少次数为：2^n-1
#include<Windows.h>
void hanoi(int n,char A,char B,char C)
{
	if(n==1)  //如果是第一层
	{
		printf("Move %d layer from %c to %c\n",n,A,C); //将A上的一层直接放到C上
	}
	else   //如果大于等于两层
	{
		hanoi(n-1,A,C,B);        //将n-1层借助C放到B上
		printf("Move %d layer from %c to %c\n",n,A,C); // 最终的目的将A放到C上
		hanoi(n-1,B,A,C);      // 将B上的n-1层借助A放到C上
	}

}
int main()
{
	int n=0;
	printf("please input layer：");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	system("pause");
	return 0;
}