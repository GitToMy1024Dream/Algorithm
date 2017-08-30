#include <iostream>
#include <string>
using namespace std;

//ipv4�ĺϷ��Լ��
bool isValidIpv4(const string& ip) 
{
	int segSize = 0;      //��'.'Ϊ�ָ������εĸ���
	int singleSeg = 0;    //�����ε��ַ�
	int singleSegLen = 0; //�����εĳ���
	for (int i = 0; i < ip.length(); i++)
	{
		//ipv4Ϊ���10���ƣ���0��9
		if (ip[i] >= '0' && ip[i] <= '9')
		{
			//���⴦��IPv4������ǰ��0��eg: 192.012.1.2
			if (singleSegLen == 0 && ip[i] == '0' && ip[i + 1] != '.')
				return false;
			singleSeg = singleSeg * 10 + (ip[i] - '0');
			singleSegLen++;
		}
		//��'.'Ϊ�ָ���
		else if (ip[i] == '.') 
		{
			//ͨ���ָ���'.'����εĸ������������ַ�ΧΪ:0��255
			if (singleSeg <= 255 && singleSegLen > 0)
				segSize++;
			else 
				return false;

			//������һ���Σ����¶�λ
			singleSeg = 0;
			singleSegLen = 0;
		}
		else
			return false;
	}

	//��'.'�����Ļ�����+1��Ϊ�εĸ���
	if (singleSeg <= 255 && singleSegLen > 0)
		segSize++;

	//�θ���Ϊ4��Ϊ�Ϸ�
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
