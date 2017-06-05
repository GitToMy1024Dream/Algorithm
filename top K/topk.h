#pragma once
#include <iostream>
#include <assert.h>
#include <time.h>
#define K 10
#define N 100000
using namespace std;
//向下调整(最小堆)
template<class T>
void Adjustdown(T* top, size_t root)
{
	assert(root < K);
	size_t parent = root;
	size_t child = 2 * parent + 1;
	while (parent < K)
	{
		//右孩子存在且小于K且右孩子小于左孩子
		if (child + 1 < K && top[child + 1] < top[child])
			child++;//将child指向更小的结点
		//当前较小孩子小于父节点时交换，并下滤
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
	//将top数组存储满
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
		if (top[0] < arr[k])//堆顶小于新比较的元素交换
		{
			std::swap(top[0], arr[k]);
			Adjustdown(top, 0);//调整最小堆的结构
		}
	}
	//遍历完成，top数据内存储的就是最大的前K个数
	for (size_t idx = 0; idx < K; ++idx)
	{
		cout << top[idx] << " ";
	}
	cout << endl;
}

