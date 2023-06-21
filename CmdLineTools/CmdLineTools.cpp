#include "CmdLineTools.h"
#include "CmdLineParser.h"
#include "CharArgs.h"
#include "StringArgs.h"

using namespace std;

IArgs* createArgsAsChar(int argc, char** argv) {
	return new CharArgs(argc, (const char**)argv);
}

IArgs* createArgsAsVector(vector<string> vec) {
	return new StringArgs(vec);
}

IArgs* createArgsAsString(string str) {
	return new StringArgs(str);
}

ICmdLineParser* createCmdLineParser() {
	return new CmdLineParser();
}
