#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;
// ���������������������ظ�������
//1. ����Ϊn�������е����ֵķ�Χ��0~n-1  ���ҳ�����������һ���ظ������֡�

//����һ��  ����������Ȼ������������ҵ��ظ���ʱ�临�Ӷȣ�o��N*logN��   �ռ临�Ӷ�o��1��


//�������� ����n��Ԫ�صĹ�ϣ��  ӳ�䣬�����ظ���  ʱ�临�Ӷ�o��N��   �ռ临�Ӷ�o��N�� ʱ�临�Ӷ���Ȼ�����˵��������˿ռ�


//�������� ������Ŀ����������������ظ������֣��ض����������еģ�ֻҪ���������@�����飬�ض��ܹ��ҵ��Ǹ��ظ�������
//�ؼ���������������@�������ʱ�临�Ӷȿ�����o��N��   �ռ临�Ӷ�Ϊo��1��

//int FindRepetition(int *a,size_t n)
//{
//	assert(a);
//	size_t i = 0;
//	for (; i < n; i++)
//	{
//		if (a[i]>n-1)
//		{
//			printf("���鲻����Ҫ��\n");
//			return 0;
//		}
//		if (a[i] == i)
//			continue;
//		if (a[i] == a[a[i]])
//			return a[i];
//		else
//			swap(a[i], a[a[i]]);
//	}
//	if (i == n)
//		printf("δ�ҵ��ظ�����\n");
//	return 0;
//}
//void test1()
//{
//	size_t size = 7;
//	int arr[] = { 2, 3, 1, 0, 2, 5, 3 };
//	cout<<FindRepetion(arr, size);
//}
//


/////////////////////////////////////////////////////////////////////////
//2.n+1���ȵ�������������1~n֮�ڣ����ܸı�ԭ�������飬��������һ���ظ�������

//����һ�� �@��������ǰ��һ����ͬ���ǣ��@����������һ�������ظ������֣���һ����һ��
//ʹ�ù�ϣ�ķ�ʽ��ʱ�临�Ӷȣ� o��N��   �ռ临�Ӷ�o��N��

//�Ż��� ������ �� ����һ�������ظ����ֵ����ԣ����ı����飬��ȡ���ƶ��ֲ����㷨��ÿ����Сһ��ķ�Χ
//ʱ�临�Ӷȣ�o��N*lgN�� �ռ临�Ӷ�o��1��   

int BinarySearch(const int* a, int n, int min, int max, int mid)
{
	assert(max > min);
	size_t i = 0;
	size_t j = 0;
	int count = 0;
	while (max - min > 1)         //whileѭ���ߴ��lgN��
	{
		for (; i < n; i++)
		{
			if (a[i]>n)
			{
				printf("���鲻����Ҫ��\n");
				return 0;
			}
			if (a[i] >= min&&a[i] <= mid)
				count++;
		}
		if (count>(mid - min))
		{
			max = mid;
			mid = max + (min - max >> 1);
			continue;
		}
		else
		{
			min = mid + 1;
			mid = max + (min - max >> 1);
		}
	}
	//ѭ��������ֻʣ����������������һ���ж�˭�ظ�
	count = 0;
	for (; j < n; j++)
	{
		if (a[i] == a[max])
			count++;
	}
	if (count == 1)
		return a[max];
	else
		return a[min];
}
int FindRepetition2(const int* a,size_t n)     //�@�����const  ��������Ͻ�
{
	assert(a);
	assert(n);
	int begin = 1;
	int end = n - 1;
	int mid = begin + (end - begin >> 1);
	return BinarySearch(a, n, begin, end, mid);

}
void Test2()
{
	size_t size = 8;
	int arr[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	cout << FindRepetition2(arr, size) << endl;
}

int main()
{
	Test2();
	//test1();
	return 0;
}