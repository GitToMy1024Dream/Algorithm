#include <iostream>
using namespace std;

bool IsNumberic(char* str)
{
	if (str == NULL)
		return false;
	if (*str == '+' || *str == '-')
		++str;
	if (*str == '\0')
		return false;
	int x = 0;    //�����������
	int digit = 0; //���С����
	int e = 0;     //���e��״̬
	while (*str != '\0')
	{
		//����������ֵ�״̬
		if (*str >= '0' && *str <= '9')
		{
			++str;
			x = 1;
		}
		//С����
		else if (*str == '.')
		{
			//ǰ���Ѿ����ֹ�С�����С����֮ǰ����e���򷵻�false
			if (digit > 0 || e > 0)
				return false;
			++str;
			digit = 1;    //���С�����Ѿ����ֹ�
		}

		//e
		else if (*str == 'e' || *str == 'E')
		{
			//e֮ǰû��������e�Ѿ����ֹ����򷵻�false
			if (x == 0 || e > 0)
				return false;
			++str;
			e = 1;     //���e��ʾ�Ѿ����ֹ�

			//e֮����Գ���+-���ټ�����
			if (*str == '+' || *str == '-')
				++str;
			if (*str == '\0')
				return false;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	char arr[32] = { 0 };
	while (cin >> arr)
	{
		if (IsNumberic(arr))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	system("pause");
	return 0;
}
