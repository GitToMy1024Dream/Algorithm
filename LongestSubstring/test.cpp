#include<iostream>
#include<string>
#include<vector>
using namespace std;

//����ظ��Ӵ�
string LongestSubstring(string s)
{
	int prevIndex[10];
	memset(prevIndex, -1, sizeof(int) * 10);
	int max = 0;   //���ظ��Ӵ�����󳤶�
	int begin = 0; //�ַ������ײ��±�
	int subBegin = 0;   //�Ӵ����ײ��±�
	for (int i = 0; i < s.size(); i++)
	{
		//�Ϸ��Լ��0��9
		if (!(s[i] >= '0'&&s[i] <= '9'))
		{
			return string();
		}
		if (prevIndex[s[i] - '0'] >= begin)
		{
			//�����������max
			if (i - begin > max)
			{
				max = i - begin;
				subBegin = begin;
			}
			begin = prevIndex[s[i] - '0'] + 1;
		}
		prevIndex[s[i] - '0'] = i;
	}

	//����max
	if ((int)s.size() - begin > max)
	{
		max = int(s.size()) - begin;
		subBegin = begin;
	}
	return string(&s[subBegin], &s[subBegin + max]);  //������Ӵ�
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
