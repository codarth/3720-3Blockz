#ifndef OPEQOVERLOADTOOLPROCESSOR_H_INCLUDED
#define OPEQOVERLOADTOOLPROCESSOR_H_INCLUDED

#include "TBToolProcessor.h"

/**
 * A tool processor which converts JSON inputs to a string of generated code.
 */
class OpEqOverloadToolProcessor : public TBToolProcessor
{
public:
    /**
     * Constructs a new tool processor.
     */
    OpEqOverloadToolProcessor();

    /**
     * Destructor.
     */
    virtual ~OpEqOverloadToolProcessor();

    /**
     * Generates operator equals overload code for the specified input.
     *
     * @param input A JSON encoded string of the input, which should contain
     *              a string attribute named "type_name" which is the name of
     *              the class type for which the overload function will use.
     *
     * @return A string of the generated code.
     *
     * @throw ParseException If we failed to parse the input in any way.
     */
    virtual string process(const string& input);
};

#endif // OPEQOVERLOADTOOLPROCESSOR_H_INCLUDED
