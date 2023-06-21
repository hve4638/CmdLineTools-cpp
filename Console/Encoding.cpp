#include <Windows.h>
#include <locale>
#include <codecvt>
#include "Encoding.h"

using namespace std;

namespace Encoding {
    static const int CODEPAGE_EUCKR = 20949;

    wstring UTF8ToWChar(const char* utf8str) {
        wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
        return converter.from_bytes(utf8str);
    }

    string WCharToUTF8(const wchar_t* wstr) {
        wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
        return converter.to_bytes(wstr);
    }

    string UTF16ToUTF8(const char* utf16str) {
        const wchar_t* wstr = reinterpret_cast<const wchar_t*>(utf16str);

        return WCharToUTF8(wstr);
    }

    wstring EUCKRToWChar(const char* euckr) {
        int bufferSize;
        bufferSize = MultiByteToWideChar(CODEPAGE_EUCKR, 0, static_cast<LPCCH>(euckr), -1, NULL, 0);
    
        wchar_t* readBuffer = new wchar_t[bufferSize];
        MultiByteToWideChar(CODEPAGE_EUCKR, 0, static_cast<LPCCH>(euckr), -1, readBuffer, bufferSize);
    
        wstring wstr = readBuffer;
        delete[] readBuffer;

        return wstr;
    }

    string EUCKRToUTF8(const char* euckr) {
        string utf8;
        wstring wstr;

        wstr = EUCKRToWChar(euckr);
        utf8 = WCharToUTF8(wstr.c_str());

        return utf8;
    }
}

