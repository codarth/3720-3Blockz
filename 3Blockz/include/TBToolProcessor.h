#ifndef TBTOOLPROCESSOR_H_INCLUDED
#define TBTOOLPROCESSOR_H_INCLUDED

#include <string>

using std::string;

class TBToolProcessor
{
public:
    virtual ~TBToolProcessor() {}

    virtual string process(const string& input) = 0;
};

#endif // TBTOOLPROCESSOR_H_INCLUDED
