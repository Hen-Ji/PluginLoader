//这个MetaObject类需要和dll中的MetaObject类保持一致，dll中需要实现这个类的虚函数，而程序需要通过这个类调用dll中实现的函数
#pragma once
#include <string>
using namespace std;

class MetaObject { //虚基类, 定义所有需要实现的函数
public:
	MetaObject() {};
	~MetaObject() {};
	virtual void setVal(string val) = 0;
	virtual string getVal() = 0;
	virtual int add(int a, int b) = 0;
};

