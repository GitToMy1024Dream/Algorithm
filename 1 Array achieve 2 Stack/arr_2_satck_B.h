#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
template<class T>
class arr_2_stack
{
public:
	arr_2_stack()
		:_arr(NULL)
		,_top1(0)
		,_top2(1)
		,_size(0)
		,_capacity(0)
	{}
	~arr_2_stack()
	{
		delete[] _arr;
	}
	void push(const T& data,int flag);//入栈
	void pop(int flag );//出栈
	size_t size(int flag);//栈的大小
	T& top(int flag = 0);//栈顶元素
	bool empty(int flag);//判断栈空
	const size_t length(int flag)const;//栈的下标
	void PrintStack(int flag);//打印
protected:
	//扩容
	void CheckCapacity();
private:
	T* _arr;
	size_t _top1;//栈1的栈顶
	size_t _top2;//栈2的栈顶
	size_t _size;//有效元素的个数
	size_t _capacity;//容量
};
 
template<class T>
//扩容
void arr_2_stack<T>::CheckCapacity()
{
	if (_size >= _capacity)
	{
		size_t NewCapacity = _capacity * 2 + 3;
		T* tmp = new T[NewCapacity];
		for (size_t idx = 0; idx < _size; ++idx)
		{
			tmp[idx] = _arr[idx];
		}
		delete[] _arr;
		_arr = tmp;
		_capacity = NewCapacity;
	}
}
template<class T>
T& arr_2_stack<T>::top(int flag)
{
	//stack1
	if (flag == 0)
	{
		assert(_top1 > 0);
		return _arr[_top1 - 2];
	}
	//stack2
	else
	{
		assert(_top2 > 1);
		return _arr[_top2 - 2];
	}
}
template<class T>
void arr_2_stack<T>::push(const T& data, int flag)
{
	CheckCapacity();
	//stack1
	if (flag == 0)
	{
		_arr[_top1] = data;
		_top1 += 2;
		if (_top1 > _top2)
		{
			_size += 2;
		}
	}
	//stack2
	else
	{
		_arr[_top2] = data;
		_top2 += 2;
		if (_top2 > _top1)
		{
			_size += 2;
		}
	}
}
template<class T>
size_t arr_2_stack<T>::size(int flag)
{
	if (flag == 0)
		return _top1 >> 1;
	else
		return (_top2 - 1) >> 1;
}
template<class T>
const size_t arr_2_stack<T>::length(int flag)const
{
	if (flag == 0)
	{
		return _top1 - 2;
	}
	else
		return _top2 - 2;
}
template<class T>
void arr_2_stack<T>::PrintStack(int flag)
{
	if (flag == 0)
	{
		if (_top1 <= 0)
		{
			cout << "Stack1 empty..." << endl;
			return;
		}
		for (size_t idx = 0; idx <= length(flag); idx += 2)
			cout << _arr[idx] << " ";
		cout << endl;
	}
	else
	{
		if (_top2 <= 1)
		{
			cout << "Stack2 empty..." << endl;
			return;
		}
		for (size_t idx = 1; idx <= length(flag); idx += 2)
			cout << _arr[idx] << " ";
		cout << endl;
	}
}
template<class T>
bool arr_2_stack<T>::empty(int flag)
{
	if (flag == 0)
		return _top1 == 0;
	else
		return _top2 == 1;
}
template<class T>
void arr_2_stack<T>::pop(int flag)
{
	if (flag == 0)
	{
		if (_top1 <= 0)
		{
			cout << "Stack1 empty" << endl;
			return;
		}
		_top1 -= 2;
		if (_top1 > _top2)
			_size -= 2;
	}
	else
	{
		
		if (_top2 <= 0)
		{
			cout << "Stack2 empty" << endl;
			return;
		}
		_top2 -= 2;
		if (_top2 > _top1)
			_size -= 2;
	}
}