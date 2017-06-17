#include <iostream>
using namespace std;
int GetMinNumber(int x, int y, int z);
int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;
	int* pUglyNumber = new int[index];
	pUglyNumber[0] = { 1 };
	int nextUglyNumber = 1;
	int* UglyNumber2 = pUglyNumber;
	int* UglyNumber3 = pUglyNumber;
	int* UglyNumber5 = pUglyNumber;
	while (nextUglyNumber < index)
	{
		int min = GetMinNumber(*UglyNumber2 * 2, *UglyNumber3 * 3, *UglyNumber5 * 5);
		pUglyNumber[nextUglyNumber] = min;
		while (*UglyNumber2 * 2 <= pUglyNumber[nextUglyNumber])
			++UglyNumber2;
		while (*UglyNumber3 * 3 <= pUglyNumber[nextUglyNumber])
			++UglyNumber3;
		while (*UglyNumber5 * 5 <= pUglyNumber[nextUglyNumber])
			++UglyNumber5;
		++nextUglyNumber;
	}
	int ret = pUglyNumber[nextUglyNumber - 1];
	delete[] pUglyNumber;
	return ret;
}
int GetMinNumber(int x, int y, int z)
{
	int min = (x > y) ? y : x;
	min = (min > z) ? z : min;
	return min;
}
int main()
{
	cout << GetUglyNumber(1) << endl;
	cout << GetUglyNumber(2) << endl;
	cout << GetUglyNumber(3) << endl;
	cout << GetUglyNumber(4) << endl;
	cout << GetUglyNumber(5) << endl;
	cout << GetUglyNumber(1500) << endl;
	system("pause");
	return 0;
}