#include "CharArgs.h"

CharArgs::CharArgs(int argc, const char** argv) {
    m_argc = argc;
    m_argv = argv;
    setOffset(-1);
}

CharArgs::CharArgs(CharArgs& source) {
    m_argc = source.m_argc;
    m_argv = source.m_argv;
    setOffset(source.offset());
}

bool CharArgs::has(int index) {
    return (0 <= index && index < m_argc);
}
string CharArgs::get(int index) {
    return has(index) ? m_argv[index] : u8"";
}
void CharArgs::setOffset(int offset) {
    m_offset = offset;
}


string CharArgs::next() {
    setOffset(offset() + 1);
    return current();
}
bool CharArgs::hasNext() {
    return has(offset() + 1);
}
string CharArgs::previous() {
    setOffset(offset() - 1);
    return current();
}
bool CharArgs::hasPrevious() {
    return has(offset() - 1);
}

int CharArgs::offset() {
    return m_offset;
}
string CharArgs::current() {
    return get(offset());
}
shared_ptr<IArgs> CharArgs::copy() {
    return make_shared<CharArgs>(*this);
}