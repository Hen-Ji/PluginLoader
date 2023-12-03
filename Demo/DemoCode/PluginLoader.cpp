#include "PluginLoader.h"

PluginLoader::PluginLoader() {
	hDllInst = nullptr;
	loaded = false;
	inst = nullptr;
	dllName = "";
}

PluginLoader::PluginLoader(string str) {
	hDllInst = nullptr;
	loaded = false;
	inst = nullptr;
	dllName = "";

	loadPlugin(str);
}

void* PluginLoader::loadPlugin(string str) {
	if (loaded) unloadPlugin();

	dllName = str;
	wstring dllNameW = wstring(dllName.begin(), dllName.end()); //string 转 wstring
	hDllInst = LoadLibrary((LPCWSTR)dllNameW.c_str()); //加载dll，返回此dll的句柄

	FARPROC proc = findFunc("create"); //找到dll中名为create的函数
	if (GetLastError()) return nullptr; //没找到这个函数则返回nullptr

	inst = (void*)proc(); //执行此函数，将返回的地址强转为void*类型
	loaded = true;
	return inst;
}
void PluginLoader::unloadPlugin() {
	delete inst;
	FreeLibrary(hDllInst);
	inst = nullptr;
	hDllInst = nullptr;
	loaded = false;
}
void* PluginLoader::reloadPlugin() {
	if (loaded) unloadPlugin();
	if (dllName != "") return loadPlugin(dllName);
	return nullptr;
}

FARPROC PluginLoader::findFunc(string str) {
	return GetProcAddress(hDllInst, str.c_str()); //获取dll中的函数
}
FARPROC PluginLoader::operator[](string str) {
	return findFunc(str);
}
void* PluginLoader::instance() {
	return inst;
}

bool PluginLoader::isLoaded() {
	return loaded;
}
HINSTANCE PluginLoader::getHandle() {
	return hDllInst;
}
string PluginLoader::getName() {
	return dllName;
}