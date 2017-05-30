template <unsigned int n>
struct SumSolution
{
	enum Value
	{
		N = SumSolution<n - 1>::N + n
	};
};
template <> 
struct SumSolution<1>
{
	enum Value
	{
		N = 1
	};
};