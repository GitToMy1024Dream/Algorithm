#include <iostream>
using namespace std;
struct Node
{
	Node* pNext;
	int _value;
};
//交点
Node* IsInsersect(Node* pHead1, Node* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	int loop1 = 0;
	int loop2 = 0;
	Node* pNode1 = pHead1;
	Node* pNode2 = pHead2;
	while (pNode1->pNext)
	{
		++loop1;
		pNode1 = pNode1->pNext;
	}
	while (pNode2->pNext)
	{
		++loop2;
		pNode2 = pNode2->pNext;
	}
	if (pNode1 != pNode2)
		return NULL;
	int res = loop1 - loop2;
	pNode1 = pHead1;
	pNode2 = pHead2;
	if (res > 0)
	{
		while (res--)
			pNode1 = pNode2->pNext;
	}
	else if (res < 0)
	{
		res = -res;
		while (res--)
			pNode2 = pNode2->pNext;
	}
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->pNext;
		pNode2 = pNode2->pNext;
	}
	return pNode1;
}

//可能带环
//是否带环,相遇点
Node* MeetingNode(Node* pHead)
{
	if (pHead == NULL)
		return NULL;
	Node* pSlow = pHead->pNext;
	if (pSlow == NULL)
		return NULL;
	Node* pFast = pSlow->pNext;
	while (pSlow != pFast)
	{
		if (pFast == pSlow)
			return pFast;
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
		if (pFast->pNext)
			pFast = pFast->pNext;
	}
	return NULL;
}
//环的入口点
Node* EntryNode(Node* pHead)
{
	Node* MeetNode = MeetingNode(pHead);
	if (MeetNode == NULL)
		return NULL;
	int loop = 1;
	Node* pNode = pHead;
	while (pNode->pNext != MeetNode)
	{
		++loop;
		pNode = pNode->pNext;
	}
	pNode = pHead;
	for (int i = 0; i < loop; ++i)
		pNode = pNode->pNext;
	Node* pTmp = pHead;
	while (pNode != pTmp)
	{
		pNode = pNode->pNext;
		pTmp = pTmp->pNext;
	}
	return pNode;
}
//判断环的相交位置
Node* IsInsersect(Node* pHead1, Node* pHead2)
{
	Node* Meet1 = MeetingNode(pHead1);
	Node* Meet2 = MeetingNode(pHead2);
	if (Meet1 == NULL || Meet2 == NULL)
		return NULL;
	if (Meet1 == Meet2)
		return IsInsersect(pHead1, pHead2);
	Node* Insersect1 = EntryNode(pHead1);
	Node* Insersect2 = EntryNode(pHead2);
	return Insersect1;
}