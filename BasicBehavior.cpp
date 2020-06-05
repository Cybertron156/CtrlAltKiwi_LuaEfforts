#include <iostream>
#include "BasicBehavior.h"

//Defaults
void DefaultInit()
{
	std::cout << "Default Init. ";
}
void DefaultUpdate(float dt)
{
	std::cout << "Default Update. ";
}
void DefaultLateUpdate(float dt)
{

}
void DefaultExit()
{
	std::cout << "Default Exit. ";
}
//Constructor
BasicBehavior::BasicBehavior(lua_State* L, std::string path)
	: state_(L)
	, path_(path)
{
	Init();
}
//Monobehavior functions
void BasicBehavior::Init()
{
	CallBehaviorFunction("Init", DefaultInit);
}
void BasicBehavior::Update(float dt)
{
	CallBehaviorFunction("Update", DefaultUpdate, dt);
	LateUpdate(dt);
}
void BasicBehavior::LateUpdate(float dt)
{
	CallBehaviorFunction("LateUpdate", DefaultLateUpdate, dt);
}
void BasicBehavior::Exit()
{
	CallBehaviorFunction("Exit", DefaultExit);
}
//Destructor
BasicBehavior::~BasicBehavior()
{
	Exit();
}