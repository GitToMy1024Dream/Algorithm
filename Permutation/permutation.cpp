#include <stdio.h>
#include <Windows.h>
void _StringSort(char *str, char* begin);
int count = 0;
void StringSort(char* str)
{
	if (str == NULL)
		return;
	_StringSort(str, str);
}
void _StringSort(char *str, char* begin)
{
	if (*begin == '\0')
	{
		printf("%s\n", str);
		count++;
	}	
	else
	{
		for (char* c = begin; *c != '\0'; ++c)
		{
			char tmp = *c;
			*c = *begin;
			*begin = tmp;	
			_StringSort(str, begin + 1);
		}

	}
}
int main()
{
	char str[] = "abcdefg";
	StringSort(str);
	printf("%d\n", count);
	system("pause");
	return 0;
}