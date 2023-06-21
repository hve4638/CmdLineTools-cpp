#include "CmdLineTools.h"
#include "Encoding.h"
#define DLL_PROC_LOAD(var_name, load_name, load_type) ((var_name = (load_type)GetProcAddress(m_module, load_name)) != NULL)

CmdLineTools::~CmdLineTools() {
    Unload();
}

int CmdLineTools::Load(string dllpath) {
    bool loaded;
    wstring wstr = Encoding::UTF8ToWChar(dllpath.c_str());
    m_module = LoadLibraryW(wstr.c_str());
    
    loaded = (m_module != NULL);
    if (!loaded) {
        return -1;
    }
    else {
        loaded &= DLL_PROC_LOAD(m_createArgsAsChar, "createArgsAsChar", CreateArgsAsCharFunc);
        loaded &= DLL_PROC_LOAD(m_createArgsAsVector, "createArgsAsVector", CreateArgsAsVectorFunc);
        loaded &= DLL_PROC_LOAD(m_createArgsAsString, "createArgsAsString", CreateArgsAsStringFunc);
        loaded &= DLL_PROC_LOAD(m_createCmdLineParser, "createCmdLineParser", CreateCmdLineParserFunc);
    }

    if (!loaded) {
        Unload();
        return -2;
    }
    else {
        return 0;
    }
}

void CmdLineTools::Unload() {
    if (m_module != NULL) {
        FreeLibrary(m_module);
        m_module = NULL;
    }
}

shared_ptr<IArgs> CmdLineTools::createArgs(int argc, char** argv) {
    shared_ptr<IArgs> ptr;
    ptr.reset(m_createArgsAsChar(argc, argv));

    return ptr;
}
shared_ptr<IArgs> CmdLineTools::createArgs(vector<string> v) {
    shared_ptr<IArgs> ptr;
    ptr.reset(m_createArgsAsVector(v));

    return ptr;
}
shared_ptr<IArgs> CmdLineTools::createArgs(string str) {
    shared_ptr<IArgs> ptr;
    ptr.reset(m_createArgsAsString(str));

    return ptr;
}
shared_ptr<ICmdLineParser> CmdLineTools::createCmdLineParser() {
    shared_ptr<ICmdLineParser> ptr;
    ptr.reset(m_createCmdLineParser());

    return ptr;
}