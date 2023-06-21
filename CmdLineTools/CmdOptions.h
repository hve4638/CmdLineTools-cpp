#pragma once
#pragma once
#include "Common/typedef.h"
#include "Common/ICmdOptions.h"
#include <map>
#include <set>


class CmdOptions : public ICmdOptions {
    map<char, string> m_options;

public:
    bool has(char option) override;
    string get(char option) override;
    void set(char option, string value);
};