#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace Encoding {
	extern wstring UTF8ToWChar(const char*);
	extern string WCharToUTF8(const wchar_t*);
	extern string UTF16ToUTF8(const char*);
	extern wstring EUCKRToWChar(const char*);
	extern string EUCKRToUTF8(const char*);
}