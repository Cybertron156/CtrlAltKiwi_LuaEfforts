#include <iostream>
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

void PrintFromCPP()
{
	std::cout << "Hello!" << std::endl;
}

//Helper function to check if a LUA-related operation was successful
bool CheckLua(lua_State* L, int operation)
{
	if (operation != LUA_OK)
	{
		std::string msg = lua_tostring(L, -1);
		std::cout << "ERROR:" << msg << std::endl;
		return false;
	}
	else
		return true;
}

int main()
{
	/*
	Create an instance of a LUA virtual machine (or 'state')
	This state will be called L (for LUA)
	To execute LUA code, pass in the state L, and the code will be executed in that state
	*/
	lua_State* L = luaL_newstate();
	/*
	Make available to our LUA state standard libraries
	*/
	luaL_openlibs(L);

	//Put all LUA-referencing code here
	if (CheckLua(L, luaL_dofile(L, "C:/Users/Seth/Desktop/LUA Fuckery/LUA_PROJECT/LUA_PROJECT/Source/LUABASICTHING.lua")))
	{
		lua_getglobal(L, "a");
		int x = (int)lua_tonumber(L, -1);
		std::cout << "NUMBER:" << x << std::endl;
	}
	

	PrintFromCPP();

	/*
	Make sure to clean up the state when you're done with it
	*/
	lua_close(L);

	return 0;
}