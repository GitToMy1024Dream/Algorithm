#include <iostream>
using namespace std;
char FirstAppearOnce(char* string)
{
	if (string == NULL)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (size_t idx = 0; idx < tableSize; ++idx)
		hashTable[idx] = 0;
	char* HashKey = string;
	while (*(HashKey++) != '\0')
		hashTable[*(HashKey++)]++;
	HashKey = string;
	while (*HashKey != '\0')
	{
		if (hashTable[*HashKey] == 1)
			return *HashKey;
		++HashKey;
	}
	return '\0';
}
int main()
{
	//char string[] = "abaccdefh";
	//char string[] = "abab";
	char string[] = "";
	char ret = FirstAppearOnce(string);
	cout << ret << endl;
	system("pause");
	return 0;
}