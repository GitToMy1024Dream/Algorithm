#include <iostream>
#include <vector>
using namespace std;
class UnionSet
{
public:
	UnionSet(int size)
	{
		//����һ����СΪsize�����飬����ʼ��Ϊ-1
		_us.resize(size, -1);
	}
	//��ȡ���鼯�ĸ�
	int _FindRoot(int index)
	{
		int _root = index;
		//С��0Ϊ�������ڵ���0Ϊ�ӽڵ�
		while (_us[_root] >= 0)
		{
			_root = _us[_root];
		}
		return _root;
	}
	//�ϲ����鼯
	void _Union(int x, int y)
	{
		//�õ��������鼯�ĸ�
		int _root1 = _FindRoot(x);
		int _root2 = _FindRoot(y);
		//��֤������㴦�ڲ�ͬ����ʱ�źϲ�
		if (_root1 != _root2)
		{
			_us[_root1] += _us[_root2];//������ЧԪ�ظ���
			_us[_root2] = _root1;//����Ԫ�صĸ��ڵ�
		}
	}
	//��ȡ���ϵĸ���
	size_t _Count()const
	{
		size_t count = 0;
		for (int idx = 0; idx < _us.size(); ++idx)
		{
			//С��0Ϊ���ڵ�
			if (_us[idx] < 0)
				count++;
		}
		return count - 1;//-1���Ƿ�ʹ���±�Ϊ0�й�
	}
	//��������Ԫ���Ƿ�����ͬһ������
	bool IsSameSet(int x, int y)
	{
		return _FindRoot(x) == _FindRoot(y);
	}
private:
	vector<int> _us;//��vector��������
};
int main()
{
	UnionSet us(6);
	us._Union(1, 2);
	us._Union(2, 3);
	us._Union(4, 5);
	cout << us._Count() << endl;
	if (us.IsSameSet(1, 3))
		cout << "����ͬһ��" << endl;
	else
		cout << "������ͬһ��" << endl;
	if (us.IsSameSet(1, 5))
		cout << "����ͬһ��" << endl;
	else
		cout << "������ͬһ��" << endl;
	system("pause");
	return 0;
}