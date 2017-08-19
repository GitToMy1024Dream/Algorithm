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
//	//�ڴ��ص�ʱ���Ӻ���ǰ����
//	if (pdest > psrc && pdest < psrc + count)
//	{
//		for (int i = n - 1; i >= 0; --i)
//		{
//			pdest[i] = psrc[i];
//		}
//	}
//	//�����������ǰ��󿽱�
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
	int wordnum = n >> 2;//��������Ϊ32λ����4�ֽڿ���
	int slice = n % 4;  // ʣ��İ��ֽڿ���
	const char* psrc = (char*)src;
	char* pdest = (char*)dest;
	//��4�ֽڿ���
	while (wordnum--)
	{
		*pdest++ = *psrc++;
	}
	//�����ֽڿ���
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

