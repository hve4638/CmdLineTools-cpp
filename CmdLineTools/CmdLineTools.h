#pragma once
#include <string>
#include <vector>
#include "api.h"
#include "Common/IArgs.h"
#include "Common/ICmdLineParser.h"

extern "C" CMDLINETOOLS_API IArgs* createArgsAsChar(int argc, char** argv);
extern "C" CMDLINETOOLS_API IArgs* createArgsAsVector(std::vector<std::string>);
extern "C" CMDLINETOOLS_API IArgs* createArgsAsString(std::string);
extern "C" CMDLINETOOLS_API ICmdLineParser* createCmdLineParser();
