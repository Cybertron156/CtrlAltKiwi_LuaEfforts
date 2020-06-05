#pragma once
//Include C-based lua headers
extern "C"
{
#include "C:/Program Files (x86)/Lua/include/lua.h"
#include "C:/Program Files (x86)/Lua/include/lauxlib.h"
#include "C:/Program Files (x86)/Lua/include/lualib.h"
}
#ifdef _WIN32
#pragma comment(lib, "C:/Program Files (x86)/Lua/lua.lib")
#endif // _WIN32

bool CheckLua(lua_State* L, int operation); //Checks a LUA operation
bool SearchFunction(lua_State* L, std::string path, std::string FuncName); //Searches for a LUA function
//Overloads, since LUA doesn't support templated functions
bool CallLuaWithArgs(lua_State* L, std::string Path, std::string FuncName, int* args, int numArgs);
bool CallLuaWithArgs(lua_State* L, std::string Path, std::string FuncName, float* args, int numArgs);