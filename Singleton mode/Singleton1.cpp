#include <iostream>
using namespace std;
class Singleton
{
private:
	Singleton()//构造函数为私有定义，防止类外构造对象
	{
		cout << "Singleton()" << endl;
	}
	static Singleton *instance;//指向Singleton对象的指针(静态实例)
public:
	static Singleton *Instance()//获取指向该类对象的指针
	{
		if (instance == NULL)//当instance为NULL时创建实例
		{                    //防止重复创建
			instance = new Singleton();//创建instance实例(开辟空间)
		}
		return instance;
	}
};
Singleton* Singleton::instance = NULL;//静态成员变量在类外定义
int main()
{
	Singleton* s1 = Singleton::Instance();
	//Singleton s2;类外无法构造对象，构造函数为私有函数
	Singleton* s3 = Singleton::Instance();
	system("pause");
	return 0;
}