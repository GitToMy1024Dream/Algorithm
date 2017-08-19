#include <stdio.h>
#include <Windows.h>
#include <assert.h>
//void* mymemcpy(void* dest,const void* src, size_t count)
//{
//	if (dest == NULL || src == NULL)
//		return NULL;
//	char* pdest = (char*)dest;
//	const char* psrc = (char*)src;
//	int n = count;
//	//内存重叠时，从后向前拷贝
//	if (pdest > psrc && pdest < psrc + count)
//	{
//		for (int i = n - 1; i >= 0; --i)
//		{
//			pdest[i] = psrc[i];
//		}
//	}
//	//正常情况，从前向后拷贝
//	else
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			pdest[i] = psrc[i];
//		}
//	}
//	return dest;
//}

void *mymemcpy(void* dest,const void* src, size_t n)
{
	assert(dest&&src);
	int wordnum = n >> 2;//假设计算机为32位，按4字节拷贝
	int slice = n % 4;  // 剩余的按字节拷贝
	const char* psrc = (char*)src;
	char* pdest = (char*)dest;
	//按4字节拷贝
	while (wordnum--)
	{
		*pdest++ = *psrc++;
	}
	//按单字节拷贝
	while (slice--)
	{
		*pdest++ = *psrc++;
	}
	return dest;
}


int main()
{
	char dst[] = "1234";
	const char src[] = "45678";
	printf("%s\n", mymemcpy(dst, src, 3));
	system("pause");
	return 0;
}

