#include <iostream>
using namespace std;

struct ListNode
{
	int _value;
	ListNode* _next;
};

ListNode* LastKthNode(ListNode* pHead, size_t K)
{
	if (pHead == NULL || K == 0)
		return NULL;
	ListNode* pCur = pHead;
	while (K--)
	{
		if (pCur->_next)
			pCur = pCur->_next;
		return NULL;
	}
	ListNode* pNode = pHead;
	while (pCur)
	{
		if (pCur->_next)
			pCur = pCur->_next;
		pNode = pNode->_next;
	}
	return pNode;
}

int main()
{
	system("pause");
	return 0;
}