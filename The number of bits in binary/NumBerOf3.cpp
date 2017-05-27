int NumBerOf1(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n &= (n - 1);
	}
	return count;
}