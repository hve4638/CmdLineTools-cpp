#pragma once
#include <vector>
#include "Common/IArgs.h"

class StringArgs : public IArgs {
    vector<string> m_vector;
    size_t m_length = 0;
    int m_offset = -1;

    bool has(int);
    string get(int);
    void setOffset(int);
public:
    StringArgs(const string&);
    StringArgs(vector<string>);
    StringArgs(StringArgs&);

    string next() override;
    string previous() override;
    bool hasNext() override;
    bool hasPrevious() override;

    int offset() override;
    string current() override;
    shared_ptr<IArgs> copy() override;
};