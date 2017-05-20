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
	void AppendTail(const T& data);//����β������
	T DeleteBack();//����β��ɾ��
private:
	queue<T> _queue1;
	queue<T> _queue2;
};
template<class T>
void Myqueue<T>::AppendTail(const T& element)
{
	_queue1.push(element);//��Ԫ�������1
}
template<class T>
T Myqueue<T>::DeleteBack()
{
	if (_queue1.empty())//����1Ϊ��ֱ�ӷ���NULL
	{
		cout << "queue is empty!" << endl;
		return NULL;
	}
	while (_queue1.size() != 1)//��֤����1ֻʣ�����һ��Ԫ��
	{
		T& data = _queue1.front();//�������1�Ķ�ͷԪ��
		_queue2.push(data);//����ڶ���2��
		_queue1.pop();//����1������
	}
	T head = _queue1.front();//�������1��Ψһ��Ԫ��
	_queue1.pop();//���һ��Ԫ�س�����
	while (_queue2.size() > 0)//������2�е�ǰn-1��Ԫ�ط��ص�����1��
	{
		T& data = _queue2.front();//�������2�Ķ�ͷԪ��
		_queue1.push(data);//����ڶ���1��
		_queue2.pop();//����2ͷɾ
	}
	return head;//�������һ��Ԫ��
}