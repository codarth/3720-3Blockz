#include <gtest/gtest.h>
#include "TestOpEqOverloadToolProcessor.h"
#include "../include/ParseException.h"

TestOpEqOverloadToolProcessor::TestOpEqOverloadToolProcessor()
{

}

TestOpEqOverloadToolProcessor::~TestOpEqOverloadToolProcessor()
{
    TearDown();
}

void TestOpEqOverloadToolProcessor::SetUp()
{
    this->_processor = std::make_shared<OpEqOverloadToolProcessor>();
}

void TestOpEqOverloadToolProcessor::TearDown()
{
    this->_processor.reset();
}

TEST_F(TestOpEqOverloadToolProcessor, TestInvalidJSON)
{
    ASSERT_THROW(this->_processor->process(string("")), ParseException);
}

TEST_F(TestOpEqOverloadToolProcessor, TestJSONMissingAttributes)
{
    ASSERT_THROW(this->_processor->process(string("{}")), ParseException);
}

TEST_F(TestOpEqOverloadToolProcessor, TestJSONMissingBadAttributeType)
{
    ASSERT_THROW(this->_processor->process(string("{\"type_name\":0}")), ParseException);
}

TEST_F(TestOpEqOverloadToolProcessor, TestGoodInput)
{
    ASSERT_NO_THROW(this->_processor->process(string("{\"type_name\":\"Hello\"}")));
}

TEST_F(TestOpEqOverloadToolProcessor, TestCorrectOutput)
{
    string typeName = "Hello";

    string output = this->_processor->process(string("{\"type_name\":\"" + typeName + "\"}"));

    string expected = typeName + "& operator==(const " + typeName + "& o)\n{\n}";

    ASSERT_EQ(output, expected);
}
