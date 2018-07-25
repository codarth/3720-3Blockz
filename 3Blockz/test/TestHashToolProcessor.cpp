#include "TestHashToolProcessor.h"
#include "../include/ParseException.h"

using std::make_shared;

TestHashToolProcessor::TestHashToolProcessor():_processor(make_shared<HashToolProcessor>())
{
    SetUp();
}

TestHashToolProcessor::~TestHashToolProcessor()
{
    TearDown();
}

void TestHashToolProcessor::SetUp()
{
    this->_processor = make_shared<HashToolProcessor>();
}

void TestHashToolProcessor::TearDown()
{
    this->_processor.reset();
}

TEST_F(TestHashToolProcessor, TestInvalidJSON)
{
    ASSERT_THROW(this->_processor->process(string("")), ParseException);
}

TEST_F(TestHashToolProcessor, TestJSONMissingAttributes)
{
    EXPECT_THROW(this->_processor->process(string("{}")), ParseException);
    EXPECT_THROW(this->_processor->process(string("{\"type_name\":\"A\"}")), ParseException);
    EXPECT_THROW(this->_processor->process(string("{\"struct_name\":\"B\"}")), ParseException);
}

TEST_F(TestHashToolProcessor, TestJSONBadAttributeTypes)
{
    EXPECT_THROW(this->_processor->process(string("{\"type_name\":0,\"struct_name\":0}")), ParseException);
    EXPECT_THROW(this->_processor->process(string("{\"type_name\":\"A\",\"struct_name\":0}")), ParseException);
    EXPECT_THROW(this->_processor->process(string("{\"type_name\":0,\"struct_name\":\"B\"}")), ParseException);

    EXPECT_THROW(this->_processor->process(string("{\"type_name\":0}")), ParseException);
    EXPECT_THROW(this->_processor->process(string("{\"struct_name\":0}")), ParseException);
}

TEST_F(TestHashToolProcessor, TestGoodInput)
{
    ASSERT_NO_THROW(this->_processor->process(string("{\"type_name\":\"Hello\",\"struct_name\":\"Hi\"}")));
}

TEST_F(TestHashToolProcessor, TestCorrectOutput)
{
    string typeName = "Dog";
    string structName = "Cat";

    string output = this->_processor->process(string("{\"type_name\":\"" + typeName + "\",\"struct_name\":\"" + structName + "\"""}"));

    string expected = string("struct ") + structName + "\n{\n\tstd::size_t operator()("
                      + typeName + " const &o) const noexcept\n\t{" + "\n\t\treturn 0;" + "\n\t}\n};";

    ASSERT_EQ(output, expected);
}
