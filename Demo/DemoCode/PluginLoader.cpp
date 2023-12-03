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
	wstring dllNameW = wstring(dllName.begin(), dllName.end()); //string ת wstring
	hDllInst = LoadLibrary((LPCWSTR)dllNameW.c_str()); //����dll�����ش�dll�ľ��

	FARPROC proc = findFunc("create"); //�ҵ�dll����Ϊcreate�ĺ���
	if (GetLastError()) return nullptr; //û�ҵ���������򷵻�nullptr

	inst = (void*)proc(); //ִ�д˺����������صĵ�ַǿתΪvoid*����
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
	return GetProcAddress(hDllInst, str.c_str()); //��ȡdll�еĺ���
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