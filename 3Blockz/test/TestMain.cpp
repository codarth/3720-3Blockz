#include <iostream>
#include <gtest/gtest.h>
#include "../include/rapidjson/rapidjson.h"
#include "../include/rapidjson/document.h"

using rapidjson::Document;
using rapidjson::Value;

TEST(TestJson, TestWorking)
{
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";

    Document d;

    d.Parse(json);

    ASSERT_TRUE(d.HasMember("stars"));

    Value& s = d["stars"];

    ASSERT_EQ(s.GetInt(), 10);
}

int main(int argCount, char** args)
{
    ::testing::InitGoogleTest(&argCount, args);

    return RUN_ALL_TESTS();
}
