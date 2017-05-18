#pragma once
#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;
template<class T>
bool Is_Legle(T *StackIn, T *StackOut, const size_t LenIn, const size_t LenOut)
{
	assert(StackIn);
	assert(StackOut);
	if (LenIn != LenOut)//ջ��Ԫ�ظ�������
		return false;
	stack<T> _s;
	for (size_t i = 0; i < LenIn; i++)
	{
		static size_t j = 0;//���徲̬������ֻ��ʼ��һ��
		_s.push(StackIn[i]);//����һ��Ԫ����ջ
		//�����ǰջ���ղ��ҳ�ջԪ�ص��ڵ�ǰջ��ջ��Ԫ��
		while (_s.size() > 0 && StackOut[j] == _s.top())
		{
			_s.pop();
			j++;
		}
	}
	//���ջ��Ϊ�գ�˵����ջ˳��ƥ�䣬����false
	return _s.size() > 0 ? false : true;
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 3,1,4,2,5 };
	bool ret = Is_Legle(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0]));
	if (ret)
	{
		cout << "��ջ˳��Ϸ�" << endl;
	}
	else
	{
		cout << "��ջ˳�򲻺Ϸ�" << endl;
	}
	system("pause");
	return 0;
}
