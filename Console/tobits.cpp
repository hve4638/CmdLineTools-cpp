#include <iostream>
#include "tobits.h"

using namespace std;

string tobits(char str) {
	string bits;
	auto ustr = static_cast<unsigned char>(str);

	for (size_t i = 0; i < 8; i++) {
		auto b = ustr >> (7 - i);
		b &= 0x1;
		if (b == 0x1) {
			bits += "1";
		}
		else {
			bits += "0";
		}
	}

	return bits;
}