#ifndef TESTOPEQOVERLOADTOOLPROCESSOR_H_INCLUDED
#define TESTOPEQOVERLOADTOOLPROCESSOR_H_INCLUDED

#include <gtest/gtest.h>
#include <memory>
#include "../include/OpEqOverloadToolProcessor.h"

using std::shared_ptr;

/**
 * Test fixture for testing OpEqOverloadToolProcessor.
 */
class TestOpEqOverloadToolProcessor : public ::testing::Test
{
public:
    /**
     * Constructs a new test fixture.
     */
    TestOpEqOverloadToolProcessor();

    /**
     * Destructor.
     */
    virtual ~TestOpEqOverloadToolProcessor();
protected:
    /**
     * Sets up the test fixture.
     */
    virtual void SetUp();

    /**
     * Tears down the test fixture.
     */
    virtual void TearDown();

    /**
     * The tool processor which we use in our test cases.
     */
    shared_ptr<OpEqOverloadToolProcessor> _processor;
};

#endif // TESTOPEQOVERLOADTOOLPROCESSOR_H_INCLUDED
