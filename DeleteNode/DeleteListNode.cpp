#include <iostream>
using namespace std;
struct ListNode {
	int data;
	ListNode* pNext;
};
ListNode* DeleteNode(ListNode* pHead, ListNode* pDelete)
{
	if (pHead == NULL || pDelete == NULL)
		return NULL;
	//1.只有一个节点
	if (pHead->pNext == NULL && pDelete == pHead)
	{
		delete pDelete;
		pHead = NULL;
		pDelete = NULL;
	}
	//2.非尾
	else if (pDelete->pNext != NULL)
	{
		ListNode* pNext = pDelete->pNext;
		pDelete->data = pNext->data;
		pDelete->pNext = pNext->pNext;
		delete pNext;
	}
	//3.尾
	else
	{
		ListNode* pNode = pHead;
		while (pNode->pNext != pDelete)
		{
			pNode = pNode->pNext;
		}
		delete pDelete;
		pNode->pNext = NULL;
		pDelete = NULL;
	}
}
int main()
{}