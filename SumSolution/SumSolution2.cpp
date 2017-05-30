class A;
A* Array[2];
class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};
class B :public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};
int SumSolution(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int value = Array[1]->Sum(n);
	return value;
}