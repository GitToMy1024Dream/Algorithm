#include <iostream>
using namespace std;
int findWhichDay(int year, int month, int day)
{
	int monthDays[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i< month; i++)
		day += monthDays[i];
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		if (month > 2)
			day += 1;
	}
	return day;
}
int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	day = findWhichDay(year, month, day);
	cout << day << endl;
	system("pause");
	return 0;
}