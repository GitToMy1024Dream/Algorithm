#include <iostream>
using namespace std;
class Singleton
{
private:
	Singleton()//���캯��Ϊ˽�ж��壬��ֹ���⹹�����
	{
		cout << "Singleton()" << endl;
	}
	static Singleton *instance;//ָ��Singleton�����ָ��(��̬ʵ��)
public:
	static Singleton *Instance()//��ȡָ���������ָ��
	{
		if (instance == NULL)//��instanceΪNULLʱ����ʵ��
		{                    //��ֹ�ظ�����
			instance = new Singleton();//����instanceʵ��(���ٿռ�)
		}
		return instance;
	}
};
Singleton* Singleton::instance = NULL;//��̬��Ա���������ⶨ��
int main()
{
	Singleton* s1 = Singleton::Instance();
	//Singleton s2;�����޷�������󣬹��캯��Ϊ˽�к���
	Singleton* s3 = Singleton::Instance();
	system("pause");
	return 0;
}