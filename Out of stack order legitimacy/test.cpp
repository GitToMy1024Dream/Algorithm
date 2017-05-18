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
	if (LenIn != LenOut)//栈内元素个数不等
		return false;
	stack<T> _s;
	for (size_t i = 0; i < LenIn; i++)
	{
		static size_t j = 0;//定义静态变量，只初始化一次
		_s.push(StackIn[i]);//将第一个元素入栈
		//如果当前栈不空并且出栈元素等于当前栈的栈顶元素
		while (_s.size() > 0 && StackOut[j] == _s.top())
		{
			_s.pop();
			j++;
		}
	}
	//如果栈不为空，说明出栈顺序不匹配，返回false
	return _s.size() > 0 ? false : true;
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 3,1,4,2,5 };
	bool ret = Is_Legle(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0]));
	if (ret)
	{
		cout << "出栈顺序合法" << endl;
	}
	else
	{
		cout << "出栈顺序不合法" << endl;
	}
	system("pause");
	return 0;
}
