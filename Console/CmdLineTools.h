#pragma once
#include "Common/IArgs.h"
#include "Common/ICmdLineParser.h"

using namespace std;

typedef IArgs* (*CreateArgsAsCharFunc)(int, char**);
typedef IArgs* (*CreateArgsAsVectorFunc)(vector<string>);
typedef IArgs* (*CreateArgsAsStringFunc)(string);
typedef ICmdLineParser* (*CreateCmdLineParserFunc)();

class CmdLineTools {
	HMODULE m_module = NULL;
	CreateArgsAsCharFunc m_createArgsAsChar = NULL;
	CreateArgsAsVectorFunc m_createArgsAsVector = NULL;
	CreateArgsAsStringFunc m_createArgsAsString = NULL;
	CreateCmdLineParserFunc m_createCmdLineParser = NULL;

public:
	~CmdLineTools();
	int Load(string);
	void Unload();

	shared_ptr<IArgs> createArgs(int argc, char** argv);
	shared_ptr<IArgs> createArgs(vector<string>);
	shared_ptr<IArgs> createArgs(string);
	shared_ptr<ICmdLineParser> createCmdLineParser();
};