#include "topk.h"
void Test()
{
	int arr[N] = { 0 };
	int top[K] = { 0 };
	srand((unsigned)time(0));//Ëæ»úÖÖ×Ó
	for (size_t idx = 0; idx < N; ++idx)
	{
		arr[idx] = rand()%1234;
	}
	topK(arr, top);
}
int main()
{
	Test();
	system("pause");
	return 0;
}