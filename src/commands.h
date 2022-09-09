#pragma once

#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "output.h"
#include "commandIncludes.h"

//Add name of your command
std::vector<std::string> commandNames
{
	"say"
};

//Add the function name of your command
std::vector<std::function<std::string(std::string, Output &out)>> commandFuncs
{
	say
};
