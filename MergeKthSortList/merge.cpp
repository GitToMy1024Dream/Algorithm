#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;
		ListNode* pnewHead = NULL;
		if (l1->val < l2->val)
		{
			pnewHead = l1;
			pnewHead->next = mergeTwoLists(l1->next, l2);
		}
		else {
			pnewHead = l2;
			pnewHead->next = mergeTwoLists(l1, l2->next);
		}
		return pnewHead;
	}
	ListNode* MergeKSortList(vector<ListNode*>& list)
	{
		if (list.size() == 0)
			return NULL;
		ListNode* p = list[0];
		for (int i = 1; i < list.size(); ++i)
		{
			p = mergeTwoLists(p, list[i]);
		}
		return p;
	}
};