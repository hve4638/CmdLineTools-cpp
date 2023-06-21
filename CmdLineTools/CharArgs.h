#pragma once
#include "Common/IArgs.h"

class CharArgs : public IArgs {
    const char** m_argv = NULL;
    int m_argc = 0;
    int m_offset = -1;

    bool has(int);
    string get(int);
    void setOffset(int);
public:
    CharArgs(int argc, const char** argv);
    CharArgs(CharArgs&);

    string next() override;
    bool hasNext() override;
    string previous() override;
    bool hasPrevious() override;

    int offset() override;
    string current() override;
    shared_ptr<IArgs> copy() override;
};