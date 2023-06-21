#include "CmdLineParser.h"
#include "CmdNode.h"
#include "StringArgs.h"
#include "CharArgs.h"
#include "BasicRunnable.h"

CmdLineParser::CmdLineParser() {
    m_root = CmdNode::make();
}

void CmdLineParser::run(shared_ptr<IArgs> args) {
    auto original = args->copy();
    auto node = m_root->findNode(args);

    if (node->isRunnable()) {
        vector<string> rawArgs;
        vector<string> cmd;

        while (original->offset() < args->offset()) {
            cmd.push_back(original->next());
        }
        while (args->hasNext()) {
            rawArgs.push_back(args->next());
        }

        ArgsAdditional additional;
        additional.cmd = cmd;
        node->run(rawArgs, additional);
    }
}

void CmdLineParser::run(string str) {
    run(make_shared<StringArgs>(str));
}

void CmdLineParser::run(int args, const char** argv) {
    run(make_shared<CharArgs>(args, argv));
}

void CmdLineParser::add(shared_ptr<IArgs> cmd, shared_ptr<IRunnable> runnable) {
    auto node = m_root->findNodeForcefully(cmd);

    if (!node->isRunnable()) {
        node->setRunnable(runnable);
    }
}

void CmdLineParser::add(
    string cmd,
    CmdCallback callback,
    string options,
    string boptions
) {
    auto args = make_shared<StringArgs>(cmd);
    auto runnable = make_shared<BasicRunnable>(callback, options, boptions);

    add(args, runnable);
}