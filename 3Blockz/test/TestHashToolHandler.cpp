#include <gtest/gtest.h>
#include "TestHashToolHandler.h"

using std::make_shared;

TestHashToolHandler::TestHashToolHandler():_handler(make_shared<HashToolHandler>())
{
    SetUp();
}

TestHashToolHandler::~TestHashToolHandler()
{
    TearDown();
}

void TestHashToolHandler::SetUp()
{
    this->_handler = make_shared<HashToolHandler>();
}

void TestHashToolHandler::TearDown()
{
    this->_handler.reset();
}

TEST_F(TestHashToolHandler, TestProcessorValid)
{
    ASSERT_NE(this->_handler->getIOProcessor().get(), nullptr);
}

TEST_F(TestHashToolHandler, TestExecute)
{
    // TODO: Implement using mocking
}

TEST_F(TestHashToolHandler, TestShowUI)
{
    // TODO: Implement using mocking
}
