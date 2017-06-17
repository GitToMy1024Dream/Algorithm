#include <iostream>
using namespace std;
bool IsUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return (number == 1) ? true : false;
}
int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;
	int number = 0;
	int uglyFind = 0;
	while (uglyFind < index)
	{
		++number;
		if (IsUgly(number))
			++uglyFind;
	}
	return number;
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