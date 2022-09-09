#pragma once

#include <vector>
#include <string>
#include "commands.h"

void parse(std::string input, Output &out)
{
	std::string command;
	std::string params;
	int num;
	//Get command
	for(int i = 0; i < input.size(); i++)
	{
		if(std::isspace(input[i]))
		{
			num = i;
			break;
		}
		else
		{
			command += input[i];
		}
	}
	//Get parameters
	params = input.erase(0, num);
	//Check for command
	bool isCommand = false;
	for(int i = 0; i < commandNames.size(); i++)
	{
		if(commandNames[i] == command)
		{
			//Run command
			commandFuncs[i](params, out);
			isCommand = true;
		}
	}
	//Use system() on unknown command
	if(isCommand == false)
	{
		std::string newCommand = command + params;
		system(newCommand.c_str());
	}
}
