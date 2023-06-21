#include "CmdNode.h"

shared_ptr<CmdNode> CmdNode::make() {
    shared_ptr<CmdNode> node;
    new CmdNode(node);

    return node;
}

CmdNode::CmdNode(shared_ptr<CmdNode>& ptr) {
    ptr.reset(this);

    m_selfPtr = ptr;
}

inline bool CmdNode::contains(string key) {
    return (m_children.find(key) != m_children.end());
}

shared_ptr<CmdNode> CmdNode::findNodeForcefully(shared_ptr<IArgs> args) {
    if (args->hasNext()) {
        auto key = args->next();
        if (!contains(key)) {
            shared_ptr<CmdNode> node = CmdNode::make();

            m_children[key] = node;
        }

        return m_children[key]->findNodeForcefully(args);
    }
    else {
        return getPtr();
    }
}

BOOL CmdNode::run(vector<string> args, ArgsAdditional additional) {
    if (isRunnable()) {
        vector<string> targs;
        m_runnable->run(args, additional);
        return TRUE;
    }
    else {
        return FALSE;
    }
}

BOOL CmdNode::isRunnable() {
    return (m_runnable.use_count() > 0);
}

void CmdNode::setRunnable(shared_ptr<IRunnable> runnable) {
    m_runnable = runnable;
}

shared_ptr<CmdNode> CmdNode::findNode(shared_ptr<IArgs> args) {
    if (args->hasNext()) {
        auto key = args->next();
        if (contains(key)) {
            return m_children[key]->findNode(args);
        }
        else {
            args->previous();
        }
    }

    return getPtr();
}

shared_ptr<CmdNode> CmdNode::getPtr() {
    return m_selfPtr.lock();
}

void CmdNode::setPtr(weak_ptr<CmdNode> wkPtr) {
    m_selfPtr = wkPtr;
}