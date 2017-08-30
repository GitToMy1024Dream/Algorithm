#include<iostream>
#include<string>
#include<vector>
using namespace std;

//最长不重复子串
string LongestSubstring(string s)
{
	int prevIndex[10];
	memset(prevIndex, -1, sizeof(int) * 10);
	int max = 0;   //不重复子串的最大长度
	int begin = 0; //字符串的首部下标
	int subBegin = 0;   //子串的首部下标
	for (int i = 0; i < s.size(); i++)
	{
		//合法性检测0～9
		if (!(s[i] >= '0'&&s[i] <= '9'))
		{
			return string();
		}
		if (prevIndex[s[i] - '0'] >= begin)
		{
			//更新最大区间max
			if (i - begin > max)
			{
				max = i - begin;
				subBegin = begin;
			}
			begin = prevIndex[s[i] - '0'] + 1;
		}
		prevIndex[s[i] - '0'] = i;
	}

	//更新max
	if ((int)s.size() - begin > max)
	{
		max = int(s.size()) - begin;
		subBegin = begin;
	}
	return string(&s[subBegin], &s[subBegin + max]);  //返回最长子串
}

int main()
{
	cout << LongestSubstring("123423") << endl;
	cout << LongestSubstring("1111") << endl;
	cout << LongestSubstring("   ") << endl;
	cout << LongestSubstring("12344321") << endl;
	system("pause");
	return 0;
}
