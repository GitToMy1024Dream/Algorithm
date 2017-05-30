class Sum
{
public:
	Sum()
	{
		++n;
		sum += n;
	}
	static void Resert()
	{
		n = 0;
		sum = 0;
	}
	static unsigned int GetSum()
	{
		return sum;
	}
private:
	static unsigned int n;
	static unsigned int sum;
}; 
unsigned int Sum::n = 0;
unsigned int Sum::sum = 0;
unsigned int SumSolution(unsigned int n)
{
	Sum::Resert();
	Sum *tmp = new Sum[n];
	delete[] tmp;
	tmp = NULL;
	return Sum::GetSum();
}