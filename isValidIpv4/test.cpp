#include <iostream>
#include <string>
using namespace std;

//ipv4的合法性检测
bool isValidIpv4(const string& ip) 
{
	int segSize = 0;      //以'.'为分隔符，段的个数
	int singleSeg = 0;    //单个段的字符
	int singleSegLen = 0; //单个段的长度
	for (int i = 0; i < ip.length(); i++)
	{
		//ipv4为点分10进制，即0～9
		if (ip[i] >= '0' && ip[i] <= '9')
		{
			//特殊处理：IPv4不能有前置0，eg: 192.012.1.2
			if (singleSegLen == 0 && ip[i] == '0' && ip[i + 1] != '.')
				return false;
			singleSeg = singleSeg * 10 + (ip[i] - '0');
			singleSegLen++;
		}
		//以'.'为分隔符
		else if (ip[i] == '.') 
		{
			//通过分隔符'.'计算段的个数，段内数字范围为:0～255
			if (singleSeg <= 255 && singleSegLen > 0)
				segSize++;
			else 
				return false;

			//进入下一个段，重新定位
			singleSeg = 0;
			singleSegLen = 0;
		}
		else
			return false;
	}

	//在'.'个数的基础上+1即为段的个数
	if (singleSeg <= 255 && singleSegLen > 0)
		segSize++;

	//段个数为4即为合法
	if (segSize == 4)
		return true;
	else 
		return false;
}

int main() {
	
	string ip;
	cin >> ip;
	cout << (isValidIpv4(ip) ? "Yes" : "No") << endl;
	system("pause");
	return 0;
}
