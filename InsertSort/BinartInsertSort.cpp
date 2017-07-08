void BinaryInsertSort(int *arr, int size)
{
	if (arr == NULL || size <= 0)
		return ;
	int index = 0;
	for (int idx = 1; idx < size; ++idx)
	{
		int tmp = arr[idx];//保存待插入元素
		int left = 0;
		int right = idx - 1;
		int mid = (left&right) + ((left^right) >> 1);
		//二分法查找插入位置
		while (left <= right)
		{
			if (tmp < arr[mid])
			{
				right = mid - 1;
				index = mid;//更新插入位置
			}		
			else if (tmp >= arr[mid])
			{
				left = mid + 1;
				index = mid + 1;//更新插入位置
			}	
			mid = (left&right) + ((left^right) >> 1);//缩小空间
		}
		//后移元素
		for (int j = idx; j > index; j--)
		{
			arr[j] = arr[j - 1];
		}
		//插入新元素
		arr[index] = tmp;
	}
}
希尔排序