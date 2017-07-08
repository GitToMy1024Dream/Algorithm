void BinaryInsertSort(int *arr, int size)
{
	if (arr == NULL || size <= 0)
		return ;
	int index = 0;
	for (int idx = 1; idx < size; ++idx)
	{
		int tmp = arr[idx];//���������Ԫ��
		int left = 0;
		int right = idx - 1;
		int mid = (left&right) + ((left^right) >> 1);
		//���ַ����Ҳ���λ��
		while (left <= right)
		{
			if (tmp < arr[mid])
			{
				right = mid - 1;
				index = mid;//���²���λ��
			}		
			else if (tmp >= arr[mid])
			{
				left = mid + 1;
				index = mid + 1;//���²���λ��
			}	
			mid = (left&right) + ((left^right) >> 1);//��С�ռ�
		}
		//����Ԫ��
		for (int j = idx; j > index; j--)
		{
			arr[j] = arr[j - 1];
		}
		//������Ԫ��
		arr[index] = tmp;
	}
}
ϣ������