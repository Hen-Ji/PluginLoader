#include "MyDll.h"

void MyDll::setVal(string val) {
	this->val = val;
}
string MyDll::getVal() {
	return val;
}
int MyDll::add(int a, int b) {
	return a + b;
}

MetaObject* create() {
	return new MyDll(); //创建MyDll对象并以MetaObject*类型返回这个对象的地址
}

int minus(int a, int b) {
	return a - b;
}
