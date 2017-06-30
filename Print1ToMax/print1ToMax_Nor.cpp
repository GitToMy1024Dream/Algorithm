//提前声明
bool Increment(char* arr, int size);
void PrintNumber(char* arr, int size);
void Print1ToMax(int n)
{
	if (n <= 0)
		return;
	char* arr = new char[n + 1];
	memset(arr, '0', n);//初始化
	arr[n] = '\0';
	while (!Increment(arr, n))
	{
		PrintNumber(arr, n);
	}
	delete[] arr;
}
//递增
bool Increment(char* arr, int size)
{
	bool isOverflow = false;//最高位进位标志位
	int TakeOver = 0;//进位标志位
	for (int idx = size - 1; idx >= 0 ; --idx)
	{
		int nSum = arr[idx] - '0' + TakeOver;
		//最低位递增
		if (idx == size - 1)
			nSum++;
		//如果nSum>=10，可能会产生进位
		if (nSum >= 10)
		{
			//最高位不进位
			if (idx == 0)
				isOverflow = true;
			//不是最高位，则进位
			else
			{
				nSum -= 10;
				TakeOver = 1;//进位标志位置1
				arr[idx] = nSum + '0';
			}
		}
		//未产生进位，直接存取
		else
		{
			arr[idx] = nSum + '0';
			break;
		}
	}
	return isOverflow;
}
//打印
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
}