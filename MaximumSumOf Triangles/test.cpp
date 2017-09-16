//#include <stdio.h>
//#include <Windows.h>
//#include <string.h>
//#pragma warning (disable:4996)
//
//int a[200][200];
//int dp[200][200];
//
//int _max(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//int main()
//{
//	int i, j, n, m;
//	while (scanf("%d",&n))
//	{
//		memset(a, 0, sizeof(a));
//		for (i = 1; i <= n; ++i)
//		{
//			for (j = 1; j <= i; ++j)
//			{
//				scanf("%d", &a[i][j]);
//			}
//			for (j = 1; j <= n; ++j)
//			{
//				dp[n][j] = a[n][j];
//			}
//			for (i = n - 1; i >= 1; --i)
//			{
//				for (j = 1; j <= i; ++j)
//				{
//					dp[i][j] = a[i][j] + _max(dp[i + 1][j], dp[i + 1][j + 1]);
//				}
//				printf("%d\n", dp[1][1]);
//			}
//		}
//	}
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning (disable:4996)
struct triangle
{
	int element;
	int sum;
}*array;

int Count(struct triangle *arr, int m, int s)
{
	int i, j, temp;
	int result = 0;
	int n = 0;

	for (i = 0; i <= (m - 1) * (m - 2) / 2; i = i + n)
	{
		for (j = 0; j <= n; j++)
		{
			temp = arr[i + j].sum + arr[i + j + n + 1].element;
			if (temp > arr[i + j + n + 1].sum)
				arr[i + j + n + 1].sum = temp;

			temp = arr[i + j].sum + arr[i + j + n + 1 + 1].element;
			if (temp > arr[i + j + n + 1 + 1].sum)
				arr[i + j + n + 1 + 1].sum = temp;
		}
		n++;
	}

	for (i = m * (m - 1) / 2; i < s; i++)
	{
		if (arr[i].sum > result)
			result = arr[i].sum;
	}

	return result;
}

int main()
{
	int i;
	int degree, size;
	int result;
	while (1)
	{
		scanf("%d", &degree);
		if (degree > 1 && degree <= 100)
			break;
	}

	size = degree * (1 + degree) / 2;
	array = (struct triangle *)malloc(size * sizeof(struct triangle));

	for (i = 0; i < size; i++)
	{
		scanf("%d", &array[i].element);
		array[i].sum = array[i].element;
	}

	result = Count(array, degree, size);

	free(array);
	printf("%d\n", result);
	system("pause");
	return 0;
}










