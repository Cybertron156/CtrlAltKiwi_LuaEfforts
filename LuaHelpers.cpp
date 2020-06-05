#include <iostream>
#include <string>
#include "LuaHelpers.h"
#include "BasicBehavior.h"

//Helper function to check if a LUA-related operation was successful
bool CheckLua(lua_State* L, int operation)
{
	if (operation != LUA_OK)
	{
		std::string msg = lua_tostring(L, -1);
		std::cout << "ERROR: " << msg << std::endl;
		return false;
	}
	else
		return true;
}
//Searches for a LUA function with a given file and function name
bool SearchFunction(lua_State* L, std::string path, std::string FuncName)
{
	bool FunctionFound = false;
	//Check file
	if (CheckLua(L, luaL_dofile(L, path.c_str())))
	{
		//Push the function onto the stack
		lua_getglobal(L, FuncName.c_str());
		//Check function
		FunctionFound = (bool)lua_isfunction(L, -1);
	}
	return FunctionFound;
}
//Calls a function (with arguments) in a state with a filepath and a function name
bool CallLuaWithArgs(lua_State* L, std::string Path, std::string FuncName, int* args, int numArgs)
{
	bool FunctionFound = SearchFunction(L, Path, FuncName);

	//Find the desired function
	if (FunctionFound)
	{
		//Push arguments onto the stack
		for (int i = 0; i < numArgs; ++i)
			lua_pushinteger(L, args[i]);
		//Call the function
		lua_call(L, numArgs, 0);
	}

	return FunctionFound;
}
bool CallLuaWithArgs(lua_State* L, std::string Path, std::string FuncName, float* args, int numArgs)
{
	bool FunctionFound = SearchFunction(L, Path, FuncName);

	//Find the desired function
	if (FunctionFound)
	{
		//Push arguments onto the stack
		for (int i = 0; i < numArgs; ++i)
			lua_pushnumber(L, args[i]);
		//Call the function
		lua_call(L, numArgs, 0);
	}

	return FunctionFound;
}
//Basic behavior public helpers
bool BasicBehavior::CallLuaFunc(std::string FuncName)
{
	int* nul = NULL;
	return CallLuaWithArgs(state_, path_, FuncName, nul, 0);
}
void BasicBehavior::CallWithReturns(std::string FuncName, int* Store, int numRets)
{
	lua_getglobal(state_, FuncName.c_str());
	lua_call(state_, 0, numRets);
	for (int i = 0; i < numRets; ++i)
	{
		if ((bool)lua_isinteger(state_, -1))
			Store[i] = (int)lua_tointeger(state_, -1);
		lua_pop(state_, 1);
	}
}
int BasicBehavior::SearchInt(std::string IntName)
{
	int FoundNum = 0;
	//Check file
	if (CheckLua(state_, luaL_dofile(state_, path_.c_str())))
	{
		//Push the number onto the stack
		lua_getglobal(state_, IntName.c_str());
		//Check number
		if ((bool)lua_isinteger(state_, -1))
			FoundNum = (int)lua_tointeger(state_, -1);
	}
	return FoundNum;
}
//Basic behavior private helper overloads
void BasicBehavior::CallBehaviorFunction(std::string FunctionName, void(*Function)())
{
	if (Function)
		Function();
	CallLuaFunc(FunctionName);
}
void BasicBehavior::CallBehaviorFunction(std::string FunctionName, void(*Function)(float), float dt)
{
	if (Function)
		Function(dt);
	CallLuaWithArgs(state_, path_, FunctionName, &dt, 1);
}