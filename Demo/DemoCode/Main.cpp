//vs 2022 ���� dll �ļ�
#include <iostream>
#include "PluginLoader.h"
#include "MetaObject.h"
using namespace std;

int main() {

	//����dll
	PluginLoader pl;
	pl.loadPlugin("MyDll.dll"); //���� MyDll.dll

	cout << pl.getName() << ' ' << pl.isLoaded() << ' ' << pl.getHandle() << endl;

	//����dll��MetaObject���еĺ���
	MetaObject* obj = (MetaObject*)pl.instance(); //��ȡ���ص�dll��ʵ������ǿתΪ���������
	//ע��: dll��Ҫʵ��create()�����Ի�ȡ��ĵ�ַ����������Ҫʵ������MataObject�еĴ��麯��

	cout << obj->add(3, 2) << endl; //���ò���ӡ

	obj->setVal("value");
	cout << obj->getVal() << endl;

	//������������
	auto func = (int(*)(int, int))pl["minus"]; //int(*)(int, int)��һ������ָ�����ͣ���ߵ�int�Ƿ������ͣ��ұߵ�����int�ǲ�������
	cout << func(1, 2) << endl; //���ݲ���������ָ�룬��ӡ����ֵ

	//cout << ((int(*)(int, int))pl.findFunc("minus"))(2, 1) << endl; //�������Ķ��������ˣ�

	//ж��dll
	pl.unloadPlugin();

	return 0;
}


