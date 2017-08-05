#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

//自定义仿函数，比较map键值的第二个元素即水果出现的次数
struct Compare
{
	bool operator()(map<string, int>::iterator left, map<string, int>::iterator right)
	{
		return left->second < right->second;
	}
};

void GetFavoriteFruit(vector<string>& fruit, size_t K)
{
	//1.通过map统计水果出现的次数
	map<string, int> _map;
	for (int i = 0; i < fruit.size(); ++i)
	{
		_map[fruit[i]]++;
	}
	//2.通过优先级队列来建立最小堆，对水果出现的次数排序
	priority_queue<map<string,int>::iterator, vector<map<string,int>::iterator>, Compare> _pq;
	map<string, int>::iterator it = _map.begin();
	while (it != _map.end())
	{
		_pq.push(it); //将包含水果和出现次数的信息存储于优先级队列
		++it;
	}

	//3.打印出现次数最多的K种水果
	while(K--)
	{
		cout << _pq.top()->first << " " << _pq.top()->second << ",";
		_pq.pop();
	}
}

int main()
{
	vector<string> V;
	V.push_back("苹果");
	V.push_back("香蕉");
	V.push_back("西瓜");
	V.push_back("葡萄");
	V.push_back("哈密瓜");
	V.push_back("菠萝");
	V.push_back("橘子");
	V.push_back("火龙果");
	V.push_back("橙子");
	V.push_back("香蕉");
	V.push_back("葡萄");
	V.push_back("橘子");
	GetFavoriteFruit(V, 3);
	system("pause");
	return 0;
}