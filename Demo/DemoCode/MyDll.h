//vs 2022 ���� dll �ļ�:
//��������Ŀ -> ѡ�����Ŀ
//дdll
//��Ŀ -> ���� -> �������� -> ���� -> �������� -> ��̬��(.dll)
//�� F5 / ��� ���� Windows ������ ����Dll, ������ �޷��������� �ĵ������ù�
//Debug�ļ������ҵ�MyDll.dll�ļ��������ɳɹ�

#pragma once
#include "MetaObject.h"
class MyDll : public MetaObject //ʵ��
{
private:
	string val;
public:
	virtual void setVal(string val);
	virtual string getVal();
	virtual int add(int a, int b);
};

#ifndef DLL_EXPORT //�����
#define DLL_EXPORT extern "C" _declspec(dllexport) //���������ⲿ����
#endif // !DLL_EXPORT

DLL_EXPORT MetaObject* create(); //PluginLoader��Ҫ���ô˺�������ȡMetaObject��ĵ�ַ

DLL_EXPORT int minus(int a, int b); //Ҳ����д����������PluginLoader��Ҫͨ�����������ҵ��������