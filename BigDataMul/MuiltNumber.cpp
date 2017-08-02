#include <iostream>
#include <string.h>
using namespace std;

char* MuiltNumber(char* x, char* y)
{
	if (x == NULL || y == NULL)
		return '\0';
	int x_len = strlen(x);
	int y_len = strlen(y);
	int *tmp = new int[x_len + y_len];
	int new_len = x_len + y_len;
	for (int i = 0; i < new_len; ++i)
	{
		tmp[i] = 0;
	}
	for (int i = 0; i < x_len; ++i)
	{
		for (int j = 0; j < y_len; ++j)
		{
			tmp[i + j + 1] += (x[i] - '0')*(y[j] - '0');
		}
	}
	for (int i = new_len - 1; i > 0; --i)
	{
		if (tmp[i] >= 10)
		{
			int rec = tmp[i] / 10;
			tmp[i - 1] += rec;
			tmp[i] %= 10;
		}
	}

	int i = 0;
	int j = 0;
	char* s = new char[new_len];
	while (tmp[i] == 0)
	{
		++i;
	}

	for (j = 0; i < new_len; i++, j++)
	{
		s[j] = tmp[i] + '0';
	}
	s[j] = '\0';
	return s;
}

int main()
{
	char arr[100] = "72106547548473106236";
	char arr[100] = "982161082972751393";
	char* ret = MuiltNumber(a, b);
	cout << ret << endl;
	system("pause");
	return 0;
}

