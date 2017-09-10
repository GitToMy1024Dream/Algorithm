//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int Solution(vector<int>& vec)
//{
//	if (vec.size() == 0)
//		return 0;
//	int n = 0;
//	sort(vec.begin(), vec.end(), less<int>());
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		int count = 0;
//		if (vec[i] == 0)
//			++n;
//		for (int j = i+1; j < vec.size(); ++j)
//		{
//			count ^= vec[j++];
//			if (count == 0)
//				++n;
//		}
//	}
//	return n;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int val = 0;
//	vector<int> vec;
//	while (n--)
//	{
//		cin >> val;
//		vec.push_back(val);
//	}
//	cout << Solution(vec) << endl;
//	system("pause");
//	return 0;
//}



#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n = 0;
	int val = 0;
	vector<int> vec;
	cin >> n;
	while (n--)
	{
		cin >> val;
		vec.push_back(val);
	}
	
	int begin = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
	if (vec[i] == 0)
		{
				++count;
				begin = i + 1;
				continue;
			}
			for (int j = begin; j < i; j++)
			{
				int status = 0;
				for (int k = j; k <= i; k++)
				{
					status ^= vec[k];
				}
				if (status == 0)
				{
					count++;
					begin = i + 1;
					continue;
				}
			}
		}
		cout << count << endl;
	return 0;
}

