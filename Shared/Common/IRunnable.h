#pragma once
#include "Common/ArgsAdditional.h"

typedef function<void(vector<string>, ArgsAdditional)> CmdCallback;

interface IRunnable {
    virtual ~IRunnable() {};
    virtual BOOL run(vector<string>, ArgsAdditional) abstract; 
};