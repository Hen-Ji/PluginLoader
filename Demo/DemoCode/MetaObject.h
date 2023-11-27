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

