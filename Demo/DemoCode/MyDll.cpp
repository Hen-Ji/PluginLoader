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
	return new MyDll(); //����MyDll������MetaObject*���ͷ����������ĵ�ַ
}

int minus(int a, int b) {
	return a - b;
}
