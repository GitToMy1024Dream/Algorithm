//rpn.h
#pragma once
#include <iostream>
using namespace std;
#include <stack>
#pragma warning (disable:4996)
//判断是否为符号
inline bool IsOperator(const char& _c);
//符号优先级
inline int priority(const char& _c);
//核心算法，将中缀表达式转换为后缀表达式
string postfix(const string& _s);