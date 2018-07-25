#ifndef TESTHASHTOOLHANDLER_H
#define TESTHASHTOOLHANDLER_H

#include <gtest/gtest.h>
#include <memory>
#include "../include/HashToolHandler.h"

using std::shared_ptr;

/**
 * @brief Test fixture for testing HashToolHandler.
 */
class TestHashToolHandler : public ::testing::Test
{
public:
    /**
     * @brief Constructs a new test fixture.
     */
    TestHashToolHandler();

    /**
     * @brief Destroy the Test Hash Tool Handler object.
     */
    virtual ~TestHashToolHandler();
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
    shared_ptr<HashToolHandler> _handler;
};

#endif /* TESTHASHTOOLHANDLER_H */
