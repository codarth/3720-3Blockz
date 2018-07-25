#include <gtest/gtest.h>
#include "TestOpEqOverloadToolHandler.h"

TestOpEqOverloadToolHandler::TestOpEqOverloadToolHandler()
{
    SetUp();
}

TestOpEqOverloadToolHandler::~TestOpEqOverloadToolHandler()
{
    TearDown();
}

void TestOpEqOverloadToolHandler::SetUp()
{
    this->_handler = std::make_shared<OpEqOverloadToolHandler>();
}

void TestOpEqOverloadToolHandler::TearDown()
{
    this->_handler.reset();
}

TEST_F(TestOpEqOverloadToolHandler, TestProcessorValid)
{
    ASSERT_NE(this->_handler->getIOProcessor().get(), nullptr);
}

TEST_F(TestOpEqOverloadToolHandler, TestExecute)
{
    // TODO: Implement using mocking
}

TEST_F(TestOpEqOverloadToolHandler, TestShowUI)
{
    // TODO: Implement using mocking
}
