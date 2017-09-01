#include <iostream>
using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.size() == 0)
			return -1;
		int hashTable[256] = { 0 };
		int i = 0;
		while (str[i] != '\0')
		{
			hashTable[str[i]]++;
			i++;
		}
		i = 0;
		while (str[i] != '\0')
		{
			if (hashTable[str[i]] == 1)
				return i;
			i++;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	string _s = "google";
	cout << s.FirstNotRepeatingChar(_s) << endl;
	system("pause");
	return 0;
}