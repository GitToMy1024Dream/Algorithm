#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<windows.h>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
int main() 
{
	int n = 0;
	scanf("%d", &n);
	vector<double> vec(n);
	for (int i = 0; i<n; i++)
		scanf("%lf", &vec[i]);
	double result = -1;
	for (int i = 0; i < n - 1; i++) 
	{
		int begin = i + 1;
		int end = n - 1;
		while (begin <= end) 
		{
			int mid = (begin&end) + (begin^end) >> 1;
			double temp = fabs(vec[i] - vec[mid]);
			if (temp < 180)
				begin = mid + 1;
			else if (temp == 180) 
			{
				printf("%.8lf\n", 180.0);
				return 0;
			}
			else {
				end = mid - 1;
			}
			if (temp > 180)
				temp = 360 - temp;
			result = max(result, temp);
		}
	}
	printf("%.8lf\n", result);
	system("pause");
	return 0;
}
