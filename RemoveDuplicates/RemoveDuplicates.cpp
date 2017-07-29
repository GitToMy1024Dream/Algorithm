#include <iostream>
using namespace std;

class Solution
{
public:
	int RemoveDuplicates(int A[], int n)
	{
		if (n == 0)
			return 0;
		int index = 0;
		for (int i = 1; i < n; ++i)
		{
			if (A[index] != A[i])
			{
				A[++index] = A[i];
			}
		}
		return index + 1;
	}
};

int main()
{
	Solution a;
	int A[] = { 1,2,2,3,6,6,7 };
	a.RemoveDuplicates(A, 7);
	system("pause");
	return 0;
}