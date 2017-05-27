#include <iostream>
using namespace std;
#define DataType int
#include <assert.h>
#include <stack>
enum Priority
{
	OPERATOR_NUM,//������
	OPERATOR_SYMBOL,//������
	ADD,//+
	SUB,//-
	MUL,//��
	DIV// /
};
struct Cell
{
	Priority _type;//����������
	DataType _value;//������
};
int RPN(Cell* rpn, size_t n)
{
	assert(rpn);
	stack<int> _s;
	for (size_t i = 0; i < n; ++i)
	{
		//����ǲ�����
		if (rpn[i]._type == OPERATOR_NUM)
		{
			_s.push(rpn[i]._value);
		}
		//����ǲ�����
		else if (rpn[i]._type == OPERATOR_SYMBOL)
		{
			//ȡ��ջ��������Ԫ��
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
	//����ջ��Ԫ�أ������һ��Ԫ��Ϊ������
	return _s.top();
}