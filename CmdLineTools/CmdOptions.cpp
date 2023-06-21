#include "CmdOptions.h"


bool CmdOptions::has(char option) {
    return m_options.find(option) != m_options.end();
}
string CmdOptions::get(char option) {
    return has(option) ? m_options[option] : u8"";
}
void CmdOptions::set(char option, string value) {
    m_options.insert({ option, value });
}