#pragma once
#include<iostream>
#include <assert.h>
#define DataType int
using namespace std;
enum  MyStack
{
	MyStack1,
	MyStack2
};
template<class T>
class ArrayStack
{
public:
	ArrayStack()
		:_capacity(5)
		,arr(new T[_capacity])
		,_s1Top(0)
		,_s2Top(_capacity-1)
	{}
	~ArrayStack()
	{
		if (arr)
		{
			delete[] arr;
			arr = NULL;
		}
	}
	void Push(MyStack _ms, const T data)
	{
		assert(arr);
		if (_s1Top > _s2Top)
			Dilatation();
		if (_ms == 0)
		{
			arr[++_s1Top] = data;
		}
		else
			arr[_s2Top--] = data;
	}
	void Pop(MyStack _ms)
	{
		if (_ms == 0)
		{
			if (_s1Top == 0)
			{
				cout << "Stack1 is empty!" << endl;
				return;
			}
			--_s1Top;
		}
		else
		{
			if (_s2Top == _capacity)
			{
				cout << "Stack2 is empty!" << endl;
				return;
			}
			++_s2Top;
		}
	}
protected:
	void Dilatation()//À©ÈÝ
	{
		DataType  Temp= _capacity;	
		_capacity *= 2;
		T* NewCapacity = new T[_capacity];
		for (size_t idx = 0; idx < _s1Top; ++idx)
		{
			NewCapacity[idx] = arr[idx];
		}
		size_t p_s1Top = _capacity - _s2Top;
		_s2Top += _capacity + 1;
		for (size_t idx = _capacity - 1; --p_s1Top; --idx)
		{
			NewCapacity[idx] = arr[_capacity];
		}
		delete[] arr;
		std::swap(arr, NewCapacity);
	}
private:
	T* arr;
	DataType _capacity;
	DataType _s1Top;
	DataType _s2Top;
};