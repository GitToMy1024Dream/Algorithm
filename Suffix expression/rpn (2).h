//rpn.h
#pragma once
#include <iostream>
using namespace std;
#include <stack>
#pragma warning (disable:4996)
//�ж��Ƿ�Ϊ����
inline bool IsOperator(const char& _c);
//�������ȼ�
inline int priority(const char& _c);
//�����㷨������׺���ʽת��Ϊ��׺���ʽ
string postfix(const string& _s);