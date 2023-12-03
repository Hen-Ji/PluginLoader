//vs 2022 调用 dll 文件
#include <iostream>
#include "PluginLoader.h"
#include "MetaObject.h"
using namespace std;

int main() {

	//加载dll
	PluginLoader pl;
	pl.loadPlugin("MyDll.dll"); //加载 MyDll.dll

	cout << pl.getName() << ' ' << pl.isLoaded() << ' ' << pl.getHandle() << endl;

	//调用dll的MetaObject类中的函数
	MetaObject* obj = (MetaObject*)pl.instance(); //获取加载的dll的实例，并强转为所需的类型
	//注意: dll中要实现create()函数以获取类的地址，且类中需要实现所有MataObject中的纯虚函数

	cout << obj->add(3, 2) << endl; //调用并打印

	obj->setVal("value");
	cout << obj->getVal() << endl;

	//调用其他函数
	auto func = (int(*)(int, int))pl["minus"]; //int(*)(int, int)是一个函数指针类型，左边的int是返回类型，右边的两个int是参数类型
	cout << func(1, 2) << endl; //传递参数给函数指针，打印返回值

	//cout << ((int(*)(int, int))pl.findFunc("minus"))(2, 1) << endl; //看不懂的东西出现了！

	//卸载dll
	pl.unloadPlugin();

	return 0;
}


