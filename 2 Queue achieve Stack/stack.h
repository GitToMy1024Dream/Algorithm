#pragma once
#include <iostream>
#include <queue>
using namespace std;
template<class T>
class Myqueue
{
public:
	Myqueue(void)
	{}
	~Myqueue(void)
	{}
	void AppendTail(const T& data);//队列尾部插入
	T DeleteBack();//队列尾部删除
private:
	queue<T> _queue1;
	queue<T> _queue2;
};
template<class T>
void Myqueue<T>::AppendTail(const T& element)
{
	_queue1.push(element);//新元素入队列1
}
template<class T>
T Myqueue<T>::DeleteBack()
{
	if (_queue1.empty())//队列1为空直接返回NULL
	{
		cout << "queue is empty!" << endl;
		return NULL;
	}
	while (_queue1.size() != 1)//保证队列1只剩下最后一个元素
	{
		T& data = _queue1.front();//保存队列1的队头元素
		_queue2.push(data);//存放在队列2中
		_queue1.pop();//队列1出队列
	}
	T head = _queue1.front();//保存队列1中唯一的元素
	_queue1.pop();//最后一个元素出队列
	while (_queue2.size() > 0)//将队列2中的前n-1个元素返回到队列1中
	{
		T& data = _queue2.front();//保存队列2的队头元素
		_queue1.push(data);//存放在队列1中
		_queue2.pop();//队列2头删
	}
	return head;//返回最后一个元素
}