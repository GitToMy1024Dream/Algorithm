//��ǰ����
void PrintNumber(char* arr, int size);
void _Print1ToMax(char* arr, int size, int index);
void Print1ToMax(int n)
{
	if (n <= 0)
		return;
	char* arr = new char[n + 1];
	arr[n] = '\0';
	//��һ�������⻮�ֳɶ��������
	for (int idx = 0; idx < 10; ++idx)
	{
		arr[0] = idx + '0';//�����λ��Ϊ0-9��С����
		_Print1ToMax(arr, n, 0);
	}
}
void _Print1ToMax(char* arr, int size, int index)
{
	//���λʱ�����д�ӡ
	if (index == size - 1)
	{
		PrintNumber(arr, size);
		return;
	}
	//��0-9֮������ֽ���ȫ����
	for (int i = 0; i < 10; ++i)
	{
		arr[index + 1] = i + '0';
		_Print1ToMax(arr, size, index + 1);//һֱ�ݹ鵽���λ
	}
}
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
	cout << "\t";
}