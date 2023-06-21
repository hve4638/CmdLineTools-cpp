#pragma once
#include <string>

interface ICmdOptions {
    virtual ~ICmdOptions() {}
    virtual bool has(char option) abstract;
    virtual string get(char option) abstract;
};