#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#define N 52
int main()
{
	int poker[N+1]; 
	int i,j,tmp,remain;// ≥ı ºªØ’Û¡–
	for(i=1;i<=N;i++)
		poker[i]=i;
	srand(time(0));// œ¥≈∆ 
	for(i=1;i<=N;i++)
	{
		j=rand()%52+1;
		tmp=poker[i];
		poker[i]=poker[j]; 
		poker[j]=tmp;
	}
	for(i=1;i<=N;i++)
	{
		// ≈–∂œª®…´ 
		switch((poker[i]-1)/13)
		{
		case 0:
			printf("∫ÏÃ“");
			break;
		case 1: 
			printf("¬Èª®");
			break;
		case 2:
			printf("∫⁄Ã“");
			break;
		case 3: 
			printf("∑Ω∆¨");
			break; 
		}
// ∆ÀøÀ≈∆ ˝◊÷ 
		remain=poker[i]%13; 
		switch(remain)
		{
		case 0: 
			printf("K ");
			break; 
		case 12:
			printf("Q ");
			break;
		case 11: 
			printf("J ");
			break; 
		default: 
			printf("%-6d",remain);
			break; 
		}
		if(i % 13 == 0)
			printf("\n");
}
	system("pause");
	return 0;		  
}
