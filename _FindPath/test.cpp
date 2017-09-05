#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
	int _value;
	ListNode* _left;
	ListNode* _right;
	ListNode(const int& value)
		:_value(value)
		,_left(NULL)
		,_right(NULL)
	{}
};

void _FindPath(ListNode* pRoot, int exception, vector<int>& path, int sum);

void Path(ListNode* pRoot, int exception)
{
	if (pRoot == NULL)
		return ;
	vector<int> path;
	int sum = 0;
	_FindPath(pRoot, exception, path, sum);
}

void _FindPath(ListNode* pRoot,int exception, vector<int>& path, int sum)
{
	sum += pRoot->_value;
	path.push_back(pRoot->_value);
	if (pRoot->_left == NULL && pRoot->_right == NULL)
	{
		if (exception == sum)
		{
			vector<int>::iterator it = path.begin();
			while (it++ != path.end())
				cout << *it << " ";
			cout << endl;
		}
	}
	if(pRoot->_left)
		_FindPath(pRoot->_left, exception, path, sum);
	if(pRoot->_right)
		_FindPath(pRoot->_right, exception, path, sum);
	path.pop_back();
}

void func()
{
	ListNode* node1 = new ListNode(10);
	ListNode* node2 = new ListNode(5);
	ListNode* node3 = new ListNode(12);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(7);
	node1->_left = node2;
	node1->_right = node3;
	node3->_left = node3->_right = NULL;
	node2->_left = node4;
	node2->_right = node5;
	node4->_left = node4->_right = node5->_left = node5->_right = NULL;
	Path(node1, 22);
}


int main()
{
	func();
	system("pause");
	return 0;
}