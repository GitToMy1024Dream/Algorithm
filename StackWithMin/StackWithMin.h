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
	void Push(const T& data);//入栈
	void Pop();//出栈
	const T& min()const;//栈内最小元素
private:
	stack<T> m_data;//数据栈
	stack<T> m_min;//辅助栈
};
template<class T>
void StackWithMin<T>::Push(const T& data)
{
	m_data.push(data);
	//若辅助栈为空或当前元素小于辅助栈的栈顶元素
	if (m_min.size() == 0 || data < m_min.top())
		m_min.push(data);
	else
		m_min.push(m_min.top());
}
template<class T>
void StackWithMin<T>::Pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	m_data.pop();//删除数据栈栈顶元素
	m_min.pop();//删除辅助栈的栈顶元素
}
template<class T>
const T& StackWithMin<T>::min()const
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();//返回辅助栈的栈顶元素
}