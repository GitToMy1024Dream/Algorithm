//提前声明
void PrintNumber(char* arr, int size);
void _Print1ToMax(char* arr, int size, int index);
void Print1ToMax(int n)
{
	if (n <= 0)
		return;
	char* arr = new char[n + 1];
	arr[n] = '\0';
	//将一个大问题划分成多个子问题
	for (int idx = 0; idx < 10; ++idx)
	{
		arr[0] = idx + '0';//将最高位分为0-9个小部分
		_Print1ToMax(arr, n, 0);
	}
}
void _Print1ToMax(char* arr, int size, int index)
{
	//最低位时，进行打印
	if (index == size - 1)
	{
		PrintNumber(arr, size);
		return;
	}
	//对0-9之间的数字进行全排列
	for (int i = 0; i < 10; ++i)
	{
		arr[index + 1] = i + '0';
		_Print1ToMax(arr, size, index + 1);//一直递归到最低位
	}
}
void PrintNumber(char* arr, int size)
{
	bool flag = true;
	for (int idx = 0; idx < size; ++idx)
	{
		//标志位为true且字符不等于0时将标志位置为false
		if (flag && arr[idx] != '0')
			flag = false;
		//第一个不为'0'的字符(说明上一个if肯定执行了)
		if (!flag)
			cout << arr[idx] << " ";
	}
	cout << "\t";
}