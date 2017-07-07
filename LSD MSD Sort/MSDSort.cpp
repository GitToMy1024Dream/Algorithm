//2.0
int MaxDigit(int *arr, int size)
{
	int digit = 0;
	int max = 0;
	int number = 1;
	for (int idx = 0; idx < size; ++idx)
	{
		if (max < arr[idx])
			max = arr[idx];
	}
	while (number <= max)
	{
		digit++;
		number *= 10;
	}
	return digit;
}
void _MSDSort(int* arr,int left,int right,int digit,int* tmp)
{
	int size = right - left;
	int radix = (int)pow(10, digit - 1);
	if (digit <= 0)
		return;
	int count[10] = { 0 };
	for (int idx = left; idx < right; ++idx)
	{
		count[arr[idx] / radix % 10]++;
	}

	int startAddr[10] = { left };
	for (int idx = 1; idx < 10; ++idx)
	{
		startAddr[idx] = startAddr[idx - 1] + count[idx - 1];
	}

	for (int idx = left; idx < right; ++idx)
	{
		tmp[startAddr[arr[idx] / radix % 10]++] = arr[idx];
	}
	memcpy(arr+left, tmp + left, size * sizeof(int));
	for (int idx = 0; idx < size; ++idx)
	{
		if (count[idx] <= 1)
			continue;
		int begin = startAddr[idx] - count[idx];
		int end = startAddr[idx];
		_MSDSort(arr, begin, end, digit - 1, tmp);
	}
}
void MSDSort(int* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	int* tmp = new int[size];
	int digit = MaxDigit(arr, size);
	_MSDSort(arr, 0, size , digit, tmp);
	delete[] tmp;
}