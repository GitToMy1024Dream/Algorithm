#include iostream
using namespace std;
char removeRepeat(char str)
{
	if (str == 0)
		return 0;
	const int tableSize = 256;
	char hashTable[tableSize];
	for (int idx = 0; idx  tableSize; ++idx)
		hashTable[idx] = false;
	char fast = str;
	char slow = str;
	while (fast != '0')
	{
		if (hashTable[fast] == true)
			++fast;
		else
		{
			hashTable[fast] = true;
			slow = fast;
			++fast;
			++slow;
		}
	}
	slow = '0';
	return str;
}
int main()
{
	char arr[] = google;
	char ret = removeRepeat(arr);
	cout  ret  endl;
	system(pause);
	return 0;
}