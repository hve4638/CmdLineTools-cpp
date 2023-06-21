#include "BasicRunnable.h"
#include "CmdOptions.h"

BasicRunnable::BasicRunnable(CmdCallback call) {
    m_call = call;
}

BasicRunnable::BasicRunnable(CmdCallback call, string kvoption, string boptions) {
    m_call = call;
    this->options(kvoption);
    this->booleanOptions(boptions);
}

BasicRunnable& BasicRunnable::options(string optionCharacters) {
    for (const auto& c : optionCharacters) {
        m_option.insert(c);
    }

    return *this;
}

BasicRunnable& BasicRunnable::booleanOptions(string optionCharacters) {
    for (const auto& c : optionCharacters) {
        m_booleanOption.insert(c);
    }

    return *this;
}

BOOL BasicRunnable::run(vector<string> args, ArgsAdditional additional) {
    bool optionMode = false;
    string optionFullWord = "";
    char optionKey = '\0';

    vector<string> rargs;
    auto options = make_shared<CmdOptions>();
    auto boptions = make_shared<CmdOptions>();
    for (const string next : args) {
        if (optionMode) {
            options->set(optionKey, next);
            optionMode = false;
        }
        else if (!next.empty() && next.front() == '-') {
            char last = next[next.length() - 1];
            
            if ((m_option.find(last) != m_option.end())) {
                optionMode = true;
                optionFullWord = next;
                optionKey = last;
            }
            
            else if (m_booleanOption.find(last) != m_booleanOption.end()) {
                boptions->set(last, u8"");
            }
            else {
                rargs.push_back(next);
            }
        }
        else {
            rargs.push_back(next);
        }
    }

    additional.options = options;
    additional.booleanOptions = boptions;
    m_call(rargs, additional);
    return FALSE;
}

