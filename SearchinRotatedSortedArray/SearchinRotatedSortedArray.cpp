#include <iostream>
using namespace std;

class Solution
{
public:
	bool search(int A[], int n, int target)
	{
		int first = 0;
		int end = n;
		while (first != end)
		{
			int mid = (first&end) + ((first^end) >> 1);
			if (A[mid] == target)
				return true;
			if (A[first] < A[mid])
			{
				if (A[first] <= target && target < A[mid])
				{
					end = mid;
				}
				else
					first = mid + 1;
			}
			else if (A[first] > A[mid])
			{
				if (A[mid] < target && target <= A[end-1])
				{
					first = mid + 1;
				}
				else
					end = mid;
			}
			else
			{
				first++;
			}

		}
		return false;
	}
};
int main()
{
	int A[] = { 3,3,3,4,5,1,2 };
	Solution s;
	bool flag = s.search(A, 7, 6);
	if (flag)
		cout << "exit" << endl;
	else
		cout << "not found" << endl;
	system("pause");
	return 0;
}