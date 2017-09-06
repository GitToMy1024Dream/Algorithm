#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class DynamicArray
{
public:
	void Insert(T num)
	{
		//偶数位
		if (((max.size() + min.size()) & 1) == 0)
		{
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>());
				num = max[0];
				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());
		}
		//奇数位
		else
		{
			if(min.size() > 0 && num > min[0])
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(),greater<T>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}

	T GetMedian()
	{
		int size = max.size() + min.size();
		T median = 0;
		if ((size & 1) == 1)
			median = min[0];
		else
			median = (min[0] + max[0]) >> 1;
		return median;
	}
private:
	std::vector<T> min;
	std::vector<T> max;
};

int main()
{
	DynamicArray<int> dy;
	vector<int> arr = { 3,9,1,0,2,4,7,8,12 };
	for (int i = 0; i < arr.size(); ++i)
		dy.Insert(arr[i]);
	cout << dy.GetMedian() << endl;
	system("pause");
	return 0;
}