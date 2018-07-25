#ifndef TBTOOLHANDLER_H_INCLUDED
#define TBTOOLHANDLER_H_INCLUDED

#include <memory>
#include "TBToolProcessor.h"

using std::string;
using std::shared_ptr;

class TBToolHandler
{
public:
    virtual ~TBToolHandler() {}

    virtual shared_ptr<TBToolProcessor> getIOProcessor() = 0;

    virtual void execute(const string& input) = 0;

    virtual void showUI() = 0;
};

#endif // TBTOOLHANDLER_H_INCLUDED
