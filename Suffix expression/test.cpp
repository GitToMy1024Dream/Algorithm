#include "RPN.h"
void FunTest()
{
	Cell rpn[] = {
		{ OPERATOR_NUM, 12 },
		{ OPERATOR_NUM, 3 },
		{ OPERATOR_NUM, 4 },
		{ OPERATOR_SYMBOL, ADD },
		{ OPERATOR_SYMBOL, MUL },
		{ OPERATOR_NUM, 6 },
		{ OPERATOR_SYMBOL, SUB },
		{ OPERATOR_NUM, 8 },
		{ OPERATOR_NUM, 2 },
		{ OPERATOR_SYMBOL, DIV },
		{ OPERATOR_SYMBOL, ADD }
	};
	int ret = RPN(rpn, sizeof(rpn) / sizeof(rpn[0]) );
	cout << ret << endl;
}
int main()
{
	FunTest();
	system("pause");
	return 0;
}