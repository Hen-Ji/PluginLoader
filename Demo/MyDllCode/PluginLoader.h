#pragma once
#include <windows.h>
#include <string>
using namespace std;

class PluginLoader
{
private:
	HINSTANCE hDllInst;
	string dllName;
	void* inst;
	bool loaded;

public:
	PluginLoader();
	PluginLoader(string str);

	void* loadPlugin(string str);
	void* reloadPlugin();
	void unloadPlugin();
	void* instance();

	bool isLoaded();
	HINSTANCE getHandle();
	string getName();


	FARPROC findFunc(string str);
	FARPROC operator[](string str);
	
};

