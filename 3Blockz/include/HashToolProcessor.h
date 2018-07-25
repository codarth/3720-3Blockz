#ifndef HASHTOOLPROCESSOR_H
#define HASHTOOLPROCESSOR_H

#include "TBToolProcessor.h"

class HashToolProcessor : public TBToolProcessor
{
public:
    HashToolProcessor();

    virtual ~HashToolProcessor();

    virtual string process(const string &input);
};

#endif /* HASHTOOLPROCESSOR_H */
