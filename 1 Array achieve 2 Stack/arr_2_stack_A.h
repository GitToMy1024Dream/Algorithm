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
		,_top2(0)
		,_capacity(1)
	{}
	~arr_2_stack()
	{
		delete[] _arr;
	}
	void push(const T& data,int flag);//��ջ
	void pop(int flag );//��ջ
	const size_t size(int flag)const;//ջ�Ĵ�С
	T& top(int flag = 0);//ջ��Ԫ��
	bool empty(int flag);//�ж�ջ��
	const size_t length(int flag)const;//ջ���±�
	void PrintStack(int flag);//��ӡ
protected:
	//����
	void CheckCapacity();
private:
	T* _arr;
	size_t _top1;//ջ1��ջ��
	size_t _top2;//ջ2��ջ��
	size_t _capacity;//����
};
 
template<class T>
void arr_2_stack<T>::CheckCapacity()
{
	if (_top1 == _top2)
	{
		size_t NewCapacity = 2 * _capacity + 2;
		T* tmp = new T[NewCapacity];
		for (size_t idx = 0; idx < _top1; ++idx)
			tmp[idx] = _arr[idx];
		int k = _capacity - 1;
		for (size_t idx = NewCapacity - 1; k > _top2; --idx, --k)
		{
			tmp[idx] = _arr[k];
		}
		delete[] _arr;
		_arr = tmp;
		size_t count = 0;//stack2��Ԫ�ظ���
		if (_capacity)
		{
			count = _capacity - 1 - _top2;
		}
		_capacity = NewCapacity;
		_top2 = _capacity - 1 - count;//�޸�stack2��ջ��
	}
}
 
template<class T>
void arr_2_stack<T>::push(const T& data, int flag)
{
	CheckCapacity();
	//stack1
	if (flag == 0)
		_arr[_top1++] = data;
	else
		_arr[_top2--] = data;
}
 
template<class T>
void arr_2_stack<T>::pop(int flag)
{
	if (flag == 0)
	{
		if (_top1 <= 0)
		{
			cout << "Stack1 empty..." << endl;
			return;
		}
		_top1--;
	}
	else
	{
		if (_top2 == _capacity - 1)
		{
			cout << "Stack2 empty..." << endl;
			return;
		}	
		_top2--;
	}
}
 
template<class T>
const size_t arr_2_stack<T>::size(int flag)const
{
	//stack1
	if (flag == 0)
		return _top1;
	else
		return _capacity - 1 - _top2;
}
 
template<class T>
T& arr_2_stack<T>::top(int flag)
{
	if (flag == 0)
		return _arr[_top1 - 1];
	else
		return _arr[_top2 + 1];
}
 
template<class T>
const size_t arr_2_stack<T>::length(int flag)const
{
	if (flag == 0)
	{
		return _top1 - 1;
	}
	else
		return _top2 + 1;
}
 
template<class T>
bool arr_2_stack<T>::empty(int flag)
{
	if (flag == 0)
		return _top1 == 0;
	else
		return _top2 == (_capacity - 1);
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
		for (size_t idx = 0; idx <= length(flag); ++idx)
			cout << _arr[idx] << " ";
		cout << endl;
	}
	else
	{
		if (_top2 == _capacity - 1)
		{
			cout << "Stack2 empty..." << endl;
			return;
		}
		for (size_t idx = _capacity - 1; idx > length(flag) ; --idx)
			cout << _arr[idx] << " ";
		cout << endl;
	}
}