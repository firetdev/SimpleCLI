#pragma once

#include <string>
#include "output.h"

std::string say(std::string param, Output &out)
{
	out.addText(param);
	return param;
}
