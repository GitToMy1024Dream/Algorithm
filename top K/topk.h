#pragma once
#include <iostream>
#include <assert.h>
#include <time.h>
#define K 10
#define N 100000
using namespace std;
//���µ���(��С��)
template<class T>
void Adjustdown(T* top, size_t root)
{
	assert(root < K);
	size_t parent = root;
	size_t child = 2 * parent + 1;
	while (parent < K)
	{
		//�Һ��Ӵ�����С��K���Һ���С������
		if (child + 1 < K && top[child + 1] < top[child])
			child++;//��childָ���С�Ľ��
		//��ǰ��С����С�ڸ��ڵ�ʱ������������
		if (child < K && top[child] < top[parent])
		{
			std::swap(top[child], top[parent]);
			parent = child;
			child = child << 1 + 1;
		}
		else
			break;
	}
}
template<class T>
void topK(T *arr, T *top)
{
	assert(K < N);
	//��top����洢��
	for (size_t i = 0; i < K; ++i)
	{
		top[i] = arr[i];
	}
	for (int j = (K - 2) >> 1; j >= 0; --j)
	{
		Adjustdown(top, j);
	}
	for (size_t k = K; k < N; ++k)
	{
		if (top[0] < arr[k])//�Ѷ�С���±Ƚϵ�Ԫ�ؽ���
		{
			std::swap(top[0], arr[k]);
			Adjustdown(top, 0);//������С�ѵĽṹ
		}
	}
	//������ɣ�top�����ڴ洢�ľ�������ǰK����
	for (size_t idx = 0; idx < K; ++idx)
	{
		cout << top[idx] << " ";
	}
	cout << endl;
}

