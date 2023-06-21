#pragma once
#include "Common/IRunnable.h"
#include "Common/ArgsAdditional.h"
#include <set>

class BasicRunnable : public IRunnable {
    set<char> m_option;
    set<char> m_booleanOption;
    CmdCallback m_call;

public:
    BasicRunnable(CmdCallback callback);
    BasicRunnable(CmdCallback callback, string kvoption = u8"", string boption = u8"");
    BasicRunnable& options(string);
    BasicRunnable& booleanOptions(string);
    BOOL run(vector<string>, ArgsAdditional) override;
};