#include <iostream>
using namespace std;

class Power {
public:
	double pow(double x, int n)
	{
		if (n < 0)
			return 1.0 / power(x, -n);
		else
			return power(x, n);
	}
private:
	double power(double x, int n)
	{
		if (n == 0)
			return 1;
		double v = power(x, n >> 1);
		if (n % 2 == 0)
			return v*v;
		else
			return v*v*x;
	}
};

int main()
{
	Power p;
	cout << p.pow(2, 3) << endl;
	cout << p.pow(2, -3) << endl;
	cout << p.pow(2, 0) << endl;
	cout << p.pow(2, 10) << endl;
	system("pause");
	return 0;
}