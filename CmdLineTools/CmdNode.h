#pragma once
#include "ICmdNode.h"
#include "Common/IArgs.h"
#include <map>

class CmdNode {
    map<string, shared_ptr<CmdNode>> m_children;
    shared_ptr<IRunnable> m_runnable = NULL;
    string m_nodeName = u8"";
    weak_ptr<CmdNode> m_selfPtr;

    void setPtr(weak_ptr<CmdNode>);
    bool contains(string);
public:
    static shared_ptr<CmdNode> make();

    CmdNode(shared_ptr<CmdNode>&);
    BOOL run(vector<string>, ArgsAdditional);
    BOOL isRunnable();
    void setRunnable(shared_ptr<IRunnable> runnable);
    shared_ptr<CmdNode> findNodeForcefully(shared_ptr<IArgs>);
    shared_ptr<CmdNode> findNode(shared_ptr<IArgs>);
    shared_ptr<CmdNode> getPtr();
};