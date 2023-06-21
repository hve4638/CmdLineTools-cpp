#include <iostream>
#include <sstream>
#include <vector>
#include "StringArgs.h"

StringArgs::StringArgs(const string& line) {
    vector<string> tokens;
    string token;

    for (const auto& ch : line) {
        if (ch != ' ') {
            token += ch;
        }
        else if (!token.empty()) {
            tokens.push_back(token);
            token.clear();
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
        token.clear();
    }

    m_vector = tokens;
    m_length = m_vector.size();
    setOffset(-1);
}
StringArgs::StringArgs(vector<string> vec) {
    m_vector = vec;
    m_length = vec.size();
    setOffset(-1);
}
StringArgs::StringArgs(StringArgs& copy) {
    m_vector = copy.m_vector;
    m_length = copy.m_length;
    setOffset(copy.offset());
}

bool StringArgs::has(int index) {
    return (0 <= index && index < m_length);
}
string StringArgs::get(int index) {
    return has(index) ? m_vector.at(index) : u8"";
}
void StringArgs::setOffset(int offset) {
    m_offset = offset;
}


string StringArgs::next() {
    setOffset(offset() + 1);
    return current();
}
bool StringArgs::hasNext() {
    return has(offset() + 1);
}
string StringArgs::previous() {
    setOffset(offset() - 1);
    return current();
}
bool StringArgs::hasPrevious() {
    return has(offset() - 1);
}


int StringArgs::offset() {
    return m_offset;
}
string StringArgs::current() {
    return get(offset());
}
shared_ptr<IArgs> StringArgs::copy() {
    return make_shared<StringArgs>(*this);
}

