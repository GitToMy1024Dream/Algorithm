#include <iostream>
using namespace std;

void myFunc(char arr[])
{
	if (arr == NULL)
		return;
	int len = strlen(arr);
	bool tmp[256];
	memset(tmp, 0, sizeof(tmp));
	int i = 0;
	int j = 0;
	for (i = 0; i < len; ++i)
	{
		if (!tmp[arr[i]])
		{
			tmp[arr[i]] = true;
			arr[j] = arr[i];
			++j;
		}
	}
	arr[j] = '\0';
}


int main()
{
	char arr[] = "bbcacdww";
	myFunc(arr);
	char *str = arr;
	while(*str != '\0')
	{
		cout << *(str++);
	}
	cout << endl;
	system("pause");
	return 0;
}