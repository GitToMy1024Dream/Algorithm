#include<stdio.h>  // ��ŵ�������ٴ���Ϊ��2^n-1
#include<Windows.h>
void hanoi(int n,char A,char B,char C)
{
	if(n==1)  //����ǵ�һ��
	{
		printf("Move %d layer from %c to %c\n",n,A,C); //��A�ϵ�һ��ֱ�ӷŵ�C��
	}
	else   //������ڵ�������
	{
		hanoi(n-1,A,C,B);        //��n-1�����C�ŵ�B��
		printf("Move %d layer from %c to %c\n",n,A,C); // ���յ�Ŀ�Ľ�A�ŵ�C��
		hanoi(n-1,B,A,C);      // ��B�ϵ�n-1�����A�ŵ�C��
	}

}
int main()
{
	int n=0;
	printf("please input layer��");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	system("pause");
	return 0;
}