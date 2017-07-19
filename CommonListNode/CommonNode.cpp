#include <iostream>
using namespace std;

struct Node
{
	Node* pNext;
	int _value;
	Node(const int& data)
		:pNext(NULL)
		,_value(data)
	{}
};
unsigned int Length(Node* pHead)
{
	unsigned int count = 0;
	Node* pCur = pHead;
	while (pCur)
	{
		++count;
		pCur = pCur->pNext;
	}
	return count;
}
Node* FindFirstCommonNode(Node* pHead1, Node* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	int pHead1Length = Length(pHead1);
	int pHead2Length = Length(pHead2);
	int diff = pHead1Length - pHead2Length;
	Node* pCur1 = pHead1;
	Node* pCur2 = pHead2;
	if (diff > 0)
	{
		while (diff--)
			pCur1 = pCur1->pNext;
	}
	else if (diff < 0)
	{
		diff = -diff;
		while (diff--)
			pCur2 = pCur2->pNext;
	}
	while (pCur1 != NULL && pCur2 != NULL && pCur1 != pCur2)
	{
		pCur1 = pCur1->pNext;
		pCur2 = pCur2->pNext;
	}
	return pCur1;
}

void Test()
{
	Node* pNode1 = new Node(10);
	Node* pNode2 = new Node(20);
	Node* pNode3 = new Node(30);
	Node* pNode4 = new Node(40);
	Node* pNode5 = new Node(50);
	Node* pNode6 = new Node(60);
	Node* _pNode1 = new Node(100);
	Node* _pNode2 = new Node(200);
	pNode1->pNext = pNode2;
	pNode2->pNext = pNode3;
	pNode3->pNext = pNode4;
	pNode4->pNext = pNode5;
	pNode5->pNext = pNode6;
	_pNode1->pNext = _pNode2;
	_pNode2->pNext = pNode5;
	pNode6->pNext = NULL;
	FindFirstCommonNode(pNode1,_pNode1);
}

int main()
{
	Test();
	system("pause");
	return 0;
}