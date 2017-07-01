#include <iostream>
#include <vector>
using namespace std;
class UnionSet
{
public:
	UnionSet(int size)
	{
		//开辟一个大小为size的数组，并初始化为-1
		_us.resize(size, -1);
	}
	//获取并查集的根
	int _FindRoot(int index)
	{
		int _root = index;
		//小于0为根，大于等于0为子节点
		while (_us[_root] >= 0)
		{
			_root = _us[_root];
		}
		return _root;
	}
	//合并并查集
	void _Union(int x, int y)
	{
		//得到两个并查集的根
		int _root1 = _FindRoot(x);
		int _root2 = _FindRoot(y);
		//保证两个结点处于不同集合时才合并
		if (_root1 != _root2)
		{
			_us[_root1] += _us[_root2];//更新有效元素个数
			_us[_root2] = _root1;//更新元素的根节点
		}
	}
	//获取集合的个数
	size_t _Count()const
	{
		size_t count = 0;
		for (int idx = 0; idx < _us.size(); ++idx)
		{
			//小于0为根节点
			if (_us[idx] < 0)
				count++;
		}
		return count - 1;//-1与是否使用下标为0有关
	}
	//查找两个元素是否属于同一个集合
	bool IsSameSet(int x, int y)
	{
		return _FindRoot(x) == _FindRoot(y);
	}
private:
	vector<int> _us;//用vector代替数组
};
int main()
{
	UnionSet us(6);
	us._Union(1, 2);
	us._Union(2, 3);
	us._Union(4, 5);
	cout << us._Count() << endl;
	if (us.IsSameSet(1, 3))
		cout << "属于同一组" << endl;
	else
		cout << "不属于同一组" << endl;
	if (us.IsSameSet(1, 5))
		cout << "属于同一组" << endl;
	else
		cout << "不属于同一组" << endl;
	system("pause");
	return 0;
}