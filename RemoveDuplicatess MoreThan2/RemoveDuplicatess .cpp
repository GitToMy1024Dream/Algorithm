#include <iostream>
using namespace std;

class Solution
{
public:
	int RemoveDuplicates(int A[],int n)
	{
		if (n <= 2)
			return n;
		int index = 2;
		for (int i = 2; i < n; i++)
		{
			if (A[i] != A[index - 2])
				A[index++] = A[i];
		}
		return index;
	}
};

int main()
{
	Solution a;
	int A[] = { 1,1,1,2,2,3 };
	cout << a.RemoveDuplicates(A, 6) << endl;
	system("pause");
	return 0;
}