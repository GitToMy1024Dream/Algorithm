#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

//�Զ���º������Ƚ�map��ֵ�ĵڶ���Ԫ�ؼ�ˮ�����ֵĴ���
struct Compare
{
	bool operator()(map<string, int>::iterator left, map<string, int>::iterator right)
	{
		return left->second < right->second;
	}
};

void GetFavoriteFruit(vector<string>& fruit, size_t K)
{
	//1.ͨ��mapͳ��ˮ�����ֵĴ���
	map<string, int> _map;
	for (int i = 0; i < fruit.size(); ++i)
	{
		_map[fruit[i]]++;
	}
	//2.ͨ�����ȼ�������������С�ѣ���ˮ�����ֵĴ�������
	priority_queue<map<string,int>::iterator, vector<map<string,int>::iterator>, Compare> _pq;
	map<string, int>::iterator it = _map.begin();
	while (it != _map.end())
	{
		_pq.push(it); //������ˮ���ͳ��ִ�������Ϣ�洢�����ȼ�����
		++it;
	}

	//3.��ӡ���ִ�������K��ˮ��
	while(K--)
	{
		cout << _pq.top()->first << " " << _pq.top()->second << ",";
		_pq.pop();
	}
}

int main()
{
	vector<string> V;
	V.push_back("ƻ��");
	V.push_back("�㽶");
	V.push_back("����");
	V.push_back("����");
	V.push_back("���ܹ�");
	V.push_back("����");
	V.push_back("����");
	V.push_back("������");
	V.push_back("����");
	V.push_back("�㽶");
	V.push_back("����");
	V.push_back("����");
	GetFavoriteFruit(V, 3);
	system("pause");
	return 0;
}