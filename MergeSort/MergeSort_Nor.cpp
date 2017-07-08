//非递归版本
void Merge(int* arr, int left, int mid, int right, int* tmp)
{
	int begin_1 = left;
	int end_1 = mid;
	int begin_2 = mid + 1;
	int end_2 = right;
	int index = begin_1;
	while (begin_1 <= end_1 && begin_2 <= end_2)
	{
		if (arr[begin_1] < arr[begin_2])
			tmp[index++] = arr[begin_1++];
		else
			tmp[index++] = arr[begin_2++];
	}
	while (begin_1 <= end_1)
		tmp[index++] = arr[begin_1++];
	while (begin_2 <= end_2)
		tmp[index++] = arr[begin_2++];
}
void _MergeSort(int *arr, int *tmp, int size)
{
	int gap = 1;
	while (gap < size)
	{
		for (int idx = 0; idx < size; idx += 2 * gap)
		{
			int left = idx;
			int mid = left + gap - 1;
			int right = mid + gap;
			if (mid >= size)
				mid = size - 1;
			if (right >= size)
				right = size - 1;
			Merge(arr, left, mid, right, tmp);
			memcpy(arr, tmp, (right - left+1) * sizeof(int));
		}
		gap <<= 1;

	}
}
void MergeSort(int* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	int *tmp = new int[size];
	_MergeSort(arr, tmp, size);
	delete[] tmp;
}
