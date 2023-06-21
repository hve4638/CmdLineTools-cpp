#pragma once
#include "typedef.h"

interface IArgs {
    virtual ~IArgs() {}

    virtual std::string next() abstract;
    virtual std::string previous() abstract;
    virtual bool hasNext() abstract;
    virtual bool hasPrevious() abstract;

    virtual int offset() abstract;
    virtual std::string current() abstract;
    virtual std::shared_ptr<IArgs> copy() abstract;
};