//Include Basic Libraries
#include <iostream>
#include <fstream>
#include <string>
//Include User-Made Headers
#include "BasicBehavior.h" //Seth
#include "jsonHelpers.h"   //Adrian

int main()
{
	/*
	Create an instance of a LUA virtual machine (or 'state')
	This state will be called L (for LUA)
	LUA code will be executed using this state at runtime
	*/
	lua_State* L = luaL_newstate();
	//Make standard libraries available to our LUA state
	luaL_openlibs(L);

	//Show off monobehavior function override shit
	BasicBehavior* bb = new BasicBehavior(L, "Source/LUABASICTHING.lua");
	for(float dt = 0; dt < 2; dt += .5f)
		bb->Update(dt);
	//Other shit
	int array[2];
	bb->CallWithReturns("foobar", array, 2);
	std::cout << "x = " << array[0] << std::endl;
	std::cout << "y = " << array[1] << std::endl;
	std::cout << "z = " << bb->SearchInt("z") << std::endl;
	//Clean up monobehavior
	delete bb;

	//Test out Adrian's JSON functionality
	rapidjson::Document document = JSON_setup("Source/j.json");
	std::cout << "name: " << jsonStr(document.FindMember("name")) << std::endl;

	//Make sure to clean up the state when you're done with it
	lua_close(L);

	return 0;
}