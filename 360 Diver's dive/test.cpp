#include <iostream>
#include <vector>
using namespace std;
void solution(vector<int>& v)
{
    if(v.empty())
        return ;
    int begin = 0;
    int end = 0;
    int count = 0;
    for(int i = 0; i < v.size();++i)
    {
        if(i == 0)
            cout<<"0"<<" ";
        else
        {
            ++end;
            while(begin != end)
            {
                if(v[begin] > v[end])
                {
                    ++count;
                }
                ++begin;
            }
			cout<<count<<" ";
			count = 0;
            begin = 0;
        }
    }
}

int main()
{
    int n = 0;
    cin >> n;
    int vue = 0;
    vector<int> v;
    while(n--)
    {
        cin >> vue;
        v.push_back(vue);
    }
    solution(v);
	system("pause");
    return 0 ;
}