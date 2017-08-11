#include <iostream>
#include <string.h>
using namespace std;

void rightRotate(char* arr, int left, int right)
{
	while (left < right)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		++left;
		--right;
	}
}
int main()
{
	char arr[] = "abcd1234";
	int len = strlen(arr);
	int k = 4;
	k %= len;
	rightRotate(arr, 0, len - k - 1);
	rightRotate(arr, len - k, len - 1);
	rightRotate(arr, 0, len - 1);
	for (int i = 0 ;i < len; i++)
		cout << arr[i];
	cout << endl;
	system("pause");
	return 0;
}