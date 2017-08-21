#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
	int _val;
	ListNode* _pnext;
};

class Solution
{
	typedef ListNode Node;
public:

	Node* MergeList(Node* pHead)
	{
		if (pHead == NULL || pHead->_pnext == NULL)
			return pHead;
		Node* pfast = pHead;
		Node* pslow = pHead;
		while (pfast->_pnext && pfast->_pnext->_pnext)
		{
			pfast = pfast->_pnext->_pnext;
			pslow = pslow->_pnext;
		}
		pfast = pslow;
		pslow = pslow->_pnext;
		pfast->_pnext = NULL;
		Node* p1 = MergeList(pHead);//Ç°°ë¶ÎÅÅÐò
		Node* p2 = MergeList(pslow);//ºó°ë¶ÎÅÅÐò
		return Merge2SortList(p1, p2);
	}

	Node* Merge2SortList(Node* pHead1, Node* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		else if (pHead2 == NULL)
			return pHead1;
		Node* pNewHead = NULL;
		if (pHead1->_val < pHead2->_val)
		{
			pNewHead = pHead1;
			pNewHead->_pnext = Merge2SortList(pHead1->_pnext, pHead2);
		}
		else 
		{
			pNewHead = pHead2;
			pNewHead->_pnext = Merge2SortList(pHead1, pHead2->_pnext);
		}
		return pNewHead;
	}
};
int main()
{

	system("pause");
	return 0;
}