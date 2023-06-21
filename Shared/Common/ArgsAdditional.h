#pragma once
#include "typedef.h"
#include "ICmdOptions.h"

struct ArgsAdditional {
    shared_ptr<ICmdOptions> options;
    shared_ptr<ICmdOptions> booleanOptions;
    vector<string> cmd;
};