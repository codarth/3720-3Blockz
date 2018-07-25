#ifndef TESTHASHTOOLPROCESSOR_H
#define TESTHASHTOOLPROCESSOR_H

#include <gtest/gtest.h>
#include <memory>
#include "../include/HashToolProcessor.h"

using std::shared_ptr;

class TestHashToolProcessor : public ::testing::Test
{
public:
    TestHashToolProcessor();

    virtual ~TestHashToolProcessor();

    virtual void SetUp();

    virtual void TearDown();
protected:
    shared_ptr<HashToolProcessor> _processor;
};

#endif /* TESTHASHTOOLPROCESSOR_H */
