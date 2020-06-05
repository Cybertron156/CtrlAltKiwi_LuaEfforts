#pragma once
#include "C:/Users/Seth/Desktop/Adrian/GAM-200-250-master/_game/subsystems/ObjectSerilazation/rapidjson/document.h"
#include "C:/Users/Seth/Desktop/Adrian/GAM-200-250-master/_game/subsystems/ObjectSerilazation/rapidjson/istreamwrapper.h"
#include "C:/Users/Seth/Desktop/Adrian/GAM-200-250-master/_game/subsystems/ObjectSerilazation/rapidjson/error/en.h"
#include "C:/Users/Seth/Desktop/Adrian/GAM-200-250-master/_game/subsystems/ObjectSerilazation/rapidjson/error/error.h"
double jsonNum(rapidjson::GenericMemberIterator<false, rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>> it)
{
    return it->value.GetDouble();
}
std::string jsonStr(rapidjson::GenericMemberIterator<false, rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>> it)
{
    return it->value.GetString();
}
//Code by Adrian
rapidjson::Document JSON_setup(std::string filename)
{
	std::ifstream file(filename.c_str());
	rapidjson::IStreamWrapper stream(file);
	rapidjson::Document doc;
	doc.ParseStream(stream);
	return doc;
}