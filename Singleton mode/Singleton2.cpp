#include <iostream>
using namespace std;
class Singleton
{
private:
	Singleton()//私有定义构造函数
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
	static Singleton* syncObj;//指向Singleton对象的指针
	static Singleton* instance;//指向Singleton对象的指针
public:
	static Singleton* Instance()//获取指向该类对象的指针
	{
		if (syncObj == NULL)
		{
			Lock();//boost库中的同步锁
			if (instance == NULL)
			{
				cout << "instance" << endl;
				instance = new Singleton();//创建实例
			}	
			UnLock();//boost库中的同步锁
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