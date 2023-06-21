#pragma once
#include "Common/ICmdLineParser.h"
#include "Common/ArgsAdditional.h"
#include "Common/IArgs.h"
#include "CmdNode.h"
#include <functional>

typedef function<void(vector<string>, ArgsAdditional)> CmdCallback;

class CmdLineParser : public ICmdLineParser {
    shared_ptr<CmdNode> m_root;

public:
    CmdLineParser();
    void run(shared_ptr<IArgs>) override;
    void run(int args, const char** argv) override;
    void run(string) override;

    void add(
        shared_ptr<IArgs> cmd,
        shared_ptr<IRunnable> runnable
    ) override;
    void add(
        string path,
        CmdCallback callback,
        string options,
        string booleanOptions
    ) override;
};