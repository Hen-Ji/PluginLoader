//vs 2022 生成 dll 文件:
//创建新项目 -> 选择空项目
//写dll
//项目 -> 属性 -> 配置属性 -> 常规 -> 配置类型 -> 动态库(.dll)
//按 F5 / 点击 本地 Windows 调试器 生成Dll, 若弹出 无法启动程序 的弹窗不用管
//Debug文件夹中找到MyDll.dll文件，则生成成功

#pragma once
#include "MetaObject.h"
class MyDll : public MetaObject //实现
{
private:
	string val;
public:
	virtual void setVal(string val);
	virtual string getVal();
	virtual int add(int a, int b);
};

#ifndef DLL_EXPORT //定义宏
#define DLL_EXPORT extern "C" _declspec(dllexport) //允许函数给外部调用
#endif // !DLL_EXPORT

DLL_EXPORT MetaObject* create(); //PluginLoader需要调用此函数来获取MetaObject类的地址

DLL_EXPORT int minus(int a, int b); //也可以写其他函数，PluginLoader需要通过函数名来找到这个函数