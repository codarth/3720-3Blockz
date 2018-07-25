#ifndef TESTOPEQOVERLOADTOOLHANDLER_H_INCLUDED
#define TESTOPEQOVERLOADTOOLHANDLER_H_INCLUDED

#include <gtest/gtest.h>
#include <memory>
#include "../include/OpEqOverloadToolHandler.h"

using std::shared_ptr;

/**
 * Test fixture for testing OpEqOverloadToolHandler.
 */
class TestOpEqOverloadToolHandler : public ::testing::Test
{
public:
    /**
     * Constructs a new test fixture.
     */
    TestOpEqOverloadToolHandler();

    /**
     * Destructor.
     */
    virtual ~TestOpEqOverloadToolHandler();
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
    shared_ptr<OpEqOverloadToolHandler> _handler;
};

#endif // TESTOPEQOVERLOADTOOLHANDLER_H_INCLUDED
