#pragma once
#include "Common/IArgs.h"
#include "Common/IRunnable.h"

interface ICmdLineParser {
    virtual void run(shared_ptr<IArgs>) abstract;
    virtual void run(int args, const char** argv) abstract;
    virtual void run(string) abstract;
        
    virtual void add(
        shared_ptr<IArgs> cmd,
        shared_ptr<IRunnable> runnable
    ) abstract;
    virtual void add(
        string cmd,
        CmdCallback callback,
        string options = u8"",
        string booleanOptions = u8""
    ) abstract;
};