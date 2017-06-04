#include "Array2stack.h"
void Test1()
{
	/*arr_2_stack<int> _s;
	_s.push(1, 0);
	_s.push(2, 0);
	_s.push(3, 0);
	_s.push(10, 1);
	_s.push(20, 1);
	_s.push(30, 1);
	_s.push(40, 1);
	cout << _s.size(0) << endl;
	cout << _s.size(1) << endl;
	cout << _s.top(0) << endl;
	cout << _s.top(1) << endl;
	cout << _s.length(0) << endl;
	cout << _s.length(1) << endl;
	_s.PrintStack(0);
	_s.PrintStack(1);
	cout << _s.empty(0) << endl;
	cout << _s.empty(1) << endl;
	_s.PrintStack(0);
	_s.PrintStack(1);*/
}
void Test2()
{
	arr_2_stack<int> _s;
	_s.push(1, 0);
	_s.push(2, 0);
	_s.push(3, 0);
	_s.push(10, 1);
	_s.push(20, 1);
	_s.push(30, 1);
	_s.push(40, 1);
	_s.push(20, 1);
	_s.push(30, 1);
	_s.push(40, 1);
	_s.PrintStack(0);
	_s.PrintStack(1);
	/*_s.pop(0);
	_s.pop(0);
	_s.pop(1);
	_s.PrintStack(0);
	_s.PrintStack(1);*/
	cout << _s.size(0) << endl;
	cout << _s.size(1) << endl;
	cout << _s.top(0) << endl;
	cout << _s.top(1) << endl;
	cout << _s.empty(0) << endl;
	cout << _s.empty(1) << endl;
}
int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}