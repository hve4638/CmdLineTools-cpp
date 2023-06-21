#pragma once
#include "Common/typedef.h"
#include "Common/IRunnable.h"
#include "Common/IArgs.h"
#include "Common/ArgsAdditional.h"

interface ICmdNode {
    virtual ~ICmdNode() {};
    virtual BOOL run(vector<string>, ArgsAdditional) abstract;
    virtual BOOL isRunnable() abstract;
    virtual void setRunnable(shared_ptr<IRunnable> runnable) abstract;
    virtual shared_ptr<ICmdNode> findNodeForcefully(shared_ptr<IArgs>) abstract;
    virtual shared_ptr<ICmdNode> findNode(shared_ptr<IArgs>) abstract;
    virtual shared_ptr<ICmdNode> getPtr() abstract;
    virtual void setPtr(weak_ptr<ICmdNode>) abstract;
};

typedef shared_ptr<ICmdNode> ICmdNodePtr;