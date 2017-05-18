#include "Stack.h"
int main()
{
	ArrayStack<int> _as;
	_as.Push(MyStack1, 1);
	_as.Push(MyStack1, 2);
	_as.Push(MyStack1, 3);
	_as.Push(MyStack1, 4);
	_as.Push(MyStack1, 5);
	_as.Push(MyStack2, 10);
	_as.Push(MyStack2, 9);
	_as.Push(MyStack2, 8);
	_as.Push(MyStack2, 7);
	_as.Push(MyStack2, 6);
	system("pause");
	return 0;
}