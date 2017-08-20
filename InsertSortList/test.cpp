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
	Node* insertSortList(Node* pHead)
	{
		if (pHead == NULL || pHead->_pnext == NULL)
			return pHead;
		list<int> l;
		Node* pCur = pHead;
		while (pCur != NULL)
		{
			l.push_back(pCur->_val);
			pCur = pCur->_pnext;
		}
		l.sort();
		pCur = pHead;
		while (pCur != NULL)
		{
			pCur->_val = l.front();
			l.pop_front();
			pCur = pCur->_pnext;
		}
		return pHead;
	}
};
int main()
{

	system("pause");
	return 0;
}