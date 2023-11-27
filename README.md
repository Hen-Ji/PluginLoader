# PluginLoader
PluginLoader: 插件加载器

PluginLoader能够方便地加载dll文件（插件）。

例：
```cpp
//加载插件
PluginLoader pl;
pl.loadPlugin("MyDll.dll");

//调用插件中MetaObject类有声明的函数
//在MetaObject类中，有声明成员函数 virtual int add(int a, int b) = 0; 在 MyDll.dll 中有实现
MetaObject* obj = (MetaObject*)pl.instance();
cout << obj->add(3, 2) << endl;

//调用其他函数
auto func = (int(*)(int, int))pl["minus"];
cout << func(1, 2) << endl;

//卸载插件
pl.unloadPlugin();
```

输出:
```
5
-1
```
