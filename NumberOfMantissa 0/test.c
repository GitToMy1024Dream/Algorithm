#include <stdio.h>
#include <Windows.h>
#include <math.h>
int main()
{
	int i = 0;
	int j = 0;
	int number = 0;
	int count = 0;
	int flag = -1;
	int cache = 0;
	printf("Please enter this number:");
	scanf("%d",&number);
	cache = number;
	while(cache)
	{
		cache /= 5;
		flag++;
	}
	if(number < 5)
	{
		printf("The number of 0 in the end of %d: 0\n",number);
	}
	else 
	{
		for(i = 5;i <= number;i += 5)
		{
			count++; 
			if(flag > 1)
			{
				for(j = 1;j < flag;j++)
				{		 
					count += flag - 1;
				}
			}
		}
		
	}
	printf("The number of 0 in the end %d: %d\n",number,count);
	system("pause");
	return 0;
}









