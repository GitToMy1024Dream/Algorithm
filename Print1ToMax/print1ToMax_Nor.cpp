//��ǰ����
bool Increment(char* arr, int size);
void PrintNumber(char* arr, int size);
void Print1ToMax(int n)
{
	if (n <= 0)
		return;
	char* arr = new char[n + 1];
	memset(arr, '0', n);//��ʼ��
	arr[n] = '\0';
	while (!Increment(arr, n))
	{
		PrintNumber(arr, n);
	}
	delete[] arr;
}
//����
bool Increment(char* arr, int size)
{
	bool isOverflow = false;//���λ��λ��־λ
	int TakeOver = 0;//��λ��־λ
	for (int idx = size - 1; idx >= 0 ; --idx)
	{
		int nSum = arr[idx] - '0' + TakeOver;
		//���λ����
		if (idx == size - 1)
			nSum++;
		//���nSum>=10�����ܻ������λ
		if (nSum >= 10)
		{
			//���λ����λ
			if (idx == 0)
				isOverflow = true;
			//�������λ�����λ
			else
			{
				nSum -= 10;
				TakeOver = 1;//��λ��־λ��1
				arr[idx] = nSum + '0';
			}
		}
		//δ������λ��ֱ�Ӵ�ȡ
		else
		{
			arr[idx] = nSum + '0';
			break;
		}
	}
	return isOverflow;
}
//��ӡ
void PrintNumber(char* arr, int size)
{
	bool flag = true;
	for (int idx = 0; idx < size; ++idx)
	{
		//��־λΪtrue���ַ�������0ʱ����־λ��Ϊfalse
		if (flag && arr[idx] != '0')
			flag = false;
		//��һ����Ϊ'0'���ַ�(˵����һ��if�϶�ִ����)
		if (!flag)
			cout << arr[idx] << " ";
	}
}