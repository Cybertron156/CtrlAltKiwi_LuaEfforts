#pragma once
#include "LuaHelpers.h"
#include <vector>
class BasicBehavior
{
public:
	//Public behavior functions
	BasicBehavior(lua_State* L, std::string fp); //Constructor
	void Update(float dt); //Public update
	~BasicBehavior(); //Destructor
	//Public helpers
	bool CallLuaFunc(std::string FuncName); //Call function
	void CallWithReturns(std::string FuncName, int* Store, int numRets);
	int SearchInt(std::string IntName); //Search for an int
private:
	//Private data
	lua_State* state_; //LUA state machine
	std::string path_; //LUA file path
	//Private behavior functions
	void Init();
	void LateUpdate(float dt);
	void Exit();
	//Private helper overloads
	void CallBehaviorFunction(std::string FunctionName, void(*Function)());
	void CallBehaviorFunction(std::string FunctionName, void(*Function)(float), float dt);
};