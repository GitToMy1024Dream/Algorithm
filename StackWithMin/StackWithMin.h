#pragma once
#include <iostream>
#include <stack>
#include <assert.h> 
using namespace std;
template<class T>
class StackWithMin
{
public:
	StackWithMin(void)
	{}
	~StackWithMin(void)
	{}
	void Push(const T& data);//��ջ
	void Pop();//��ջ
	const T& min()const;//ջ����СԪ��
private:
	stack<T> m_data;//����ջ
	stack<T> m_min;//����ջ
};
template<class T>
void StackWithMin<T>::Push(const T& data)
{
	m_data.push(data);
	//������ջΪ�ջ�ǰԪ��С�ڸ���ջ��ջ��Ԫ��
	if (m_min.size() == 0 || data < m_min.top())
		m_min.push(data);
	else
		m_min.push(m_min.top());
}
template<class T>
void StackWithMin<T>::Pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	m_data.pop();//ɾ������ջջ��Ԫ��
	m_min.pop();//ɾ������ջ��ջ��Ԫ��
}
template<class T>
const T& StackWithMin<T>::min()const
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();//���ظ���ջ��ջ��Ԫ��
}