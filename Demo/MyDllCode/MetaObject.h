#pragma once
#include <string>
using namespace std;

class MetaObject { //�����, ����������Ҫʵ�ֵĺ���
public:
	MetaObject() {};
	~MetaObject() {};
	virtual void setVal(string val) = 0;
	virtual string getVal() = 0;
	virtual int add(int a, int b) = 0;
};

