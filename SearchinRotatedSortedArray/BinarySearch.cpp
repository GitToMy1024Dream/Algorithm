#include <iostream>
using namespace std;

class Solution
{
public:
	int Search(int A[], int n,int target)
	{
		int first = 0;
		int last = n;
		while (first != last)
		{
			int mid = (first&last) + ((first^last) >> 1);
			if (target == A[mid])
				return mid;
			if (A[first] <= A[mid])
			{
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			}
			else
			{
				if (A[mid] < target && target <= A[last - 1])
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;
	}
};

int main()
{
	Solution a;
	int A[] = { 1,2,4,5,6,7 };
	cout << a.Search(A, 6, 5) << endl;
	system("pause");
	return 0;
}