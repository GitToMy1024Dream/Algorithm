#include <iostream>
using namespace std;
#define DataType int
#include <assert.h>
#include <stack>
enum Priority
{
	OPERATOR_NUM,//操作数
	OPERATOR_SYMBOL,//操作符
	ADD,//+
	SUB,//-
	MUL,//×
	DIV// /
};
struct Cell
{
	Priority _type;//操作符类型
	DataType _value;//操作数
};
int RPN(Cell* rpn, size_t n)
{
	assert(rpn);
	stack<int> _s;
	for (size_t i = 0; i < n; ++i)
	{
		//如果是操作数
		if (rpn[i]._type == OPERATOR_NUM)
		{
			_s.push(rpn[i]._value);
		}
		//如果是操作符
		else if (rpn[i]._type == OPERATOR_SYMBOL)
		{
			//取出栈顶的两个元素
			int y = _s.top();
			_s.pop();
			int x = _s.top();
			_s.pop();
			switch (rpn[i]._value)
			{
			case 2:
				_s.push(x + y);
				break;
			case 3:
				_s.push(x - y);
				break;
			case 4:
				_s.push(x * y);
				break;
			case 5:
				if (y == 0)
					cout << "error" << endl;
				else
					_s.push(x / y);
				break;
			default:
				break;
			}
		}
	}
	//返回栈顶元素，即最后一个元素为运算结果
	return _s.top();
}