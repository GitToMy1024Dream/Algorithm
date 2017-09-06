#include <iostream>
#include <vector>
#include <deque>
using namespace std;


vector<int> MaxWindows(vector<int>& num, unsigned int size)
{
	vector<int> maxWindows;
	if (num.size() >= size && size > 0)
	{
		deque<int> index;
		for (unsigned int i = 0; i < size; ++i)
		{
			if (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			index.push_back(i);
		}
		for (unsigned int i = size; i < num.size(); ++i)
		{
			maxWindows.push_back(num[index.front()]);
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			if (!index.empty() && (int)(i - size) >= index.front())
				index.pop_front();
			index.push_back(i);
		}
		maxWindows.push_back(num[index.front()]);
	}
	return maxWindows;
}

int main()
{
	vector<int> arr;
	int str[] = { 2,3,4,2,6,2,5,1};
	for (int i = 0; i < 8; ++i)
	{
		arr.push_back(str[i]);
	}
	vector<int> ret = MaxWindows(arr, 3);
	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}