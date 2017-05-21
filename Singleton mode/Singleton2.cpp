#include <iostream>
using namespace std;
class Singleton
{
private:
	Singleton()//˽�ж��幹�캯��
	{
		cout << "Singleton()" << endl;
	}
        ~Singleton()
	{
		if (instance)
		{
			delete instance;
			instance = NULL;
		}
	}
	static Singleton* syncObj;//ָ��Singleton�����ָ��
	static Singleton* instance;//ָ��Singleton�����ָ��
public:
	static Singleton* Instance()//��ȡָ���������ָ��
	{
		if (syncObj == NULL)
		{
			Lock();//boost���е�ͬ����
			if (instance == NULL)
			{
				cout << "instance" << endl;
				instance = new Singleton();//����ʵ��
			}	
			UnLock();//boost���е�ͬ����
		}
		return instance;
	}
};
Singleton* Singleton::syncObj = NULL;
Singleton* Singleton::instance = NULL;
int main()
{
	Singleton* s1 = Singleton::Instance();
	Singleton* s2 = Singleton::Instance();
	system("pause");
	return 0;
}