#include <iostream>
#include "dprint.h"
#include "tobits.h"

using namespace std;

union UChar {
	const wchar_t w;
	const char c[2];
};

static void countLF(int& count, int w) {
	if (w == 0 || count++ % w == 0) cout << endl;
	else cout << " ";
}

void printwb(const wchar_t* wstr, int w) {
	const UChar* u = reinterpret_cast<const UChar*>(wstr);

	int count = 1;
	while (u->w != NULL) {
		cout << tobits(u->c[0]);
		countLF(count, w);

		cout << tobits(u->c[1]);
		countLF(count, w);
		u++;
	}
	if (w != 0 && (count - 1) % w != 0) cout << endl;
}

void printb(const char* p, int w) {
	int count = 1;
	while (*p != NULL) {
		cout << tobits(*p);
		countLF(count, w);
		p++;
	}
	if (w != 0 && (count - 1) % w != 0) cout << endl;
}