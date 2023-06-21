#include <iostream>
#include <string>
#include <atlstr.h>
#include "Encoding.h"
#include "dprint.h"
#include "CmdLineTools.h"

using namespace std;
CmdLineTools cmdTools;

int wmain(int argc, wchar_t** argv) {
	string str;
	SetConsoleOutputCP(CP_UTF8);
	
	int errorCode = cmdTools.Load(u8"./CmdLineTools.dll");
	if (errorCode != 0) {
		cout << u8"Load Fail (" << errorCode << ")" << endl;
		exit(-1);
	}

	auto parser = cmdTools.createCmdLineParser();

	parser->add(
		u8"echo",
		[](vector<string> args, ArgsAdditional addition) {
			for (const auto& str : args) {
				cout << str << " ";
			}
			cout << endl;
			cout << addition.options->get('t') << endl;
			cout << addition.booleanOptions->has('p') << endl;
			cout << endl;
		},
		u8"t",
		u8"p"
	);

	parser->run(u8"echo hello world -t 15 -p");
}