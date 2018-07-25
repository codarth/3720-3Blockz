#include "../include/rapidjson/document.h"
#include "../include/OpEqOverloadToolProcessor.h"
#include "../include/ParseException.h"

using rapidjson::Document;
using rapidjson::ParseResult;

OpEqOverloadToolProcessor::OpEqOverloadToolProcessor()
{

}

OpEqOverloadToolProcessor::~OpEqOverloadToolProcessor()
{

}

string OpEqOverloadToolProcessor::process(const string& input)
{
    // The input format is expected to be an encoded json string
    Document doc;

    ParseResult parseResult = doc.Parse(input.c_str());
    if (!parseResult)
    {
        throw ParseException("Could not parse the input JSON encoded string.");
    }

    if (!doc.HasMember("type_name"))
    {
        throw ParseException("Document does not contain member 'type_name.'");
    }

    if (!doc["type_name"].IsString())
    {
        throw ParseException("Document member 'type_name' must be a string.");
    }

    string typeName(doc["type_name"].GetString());

    string output = typeName + "& operator==(const " + typeName + "& o)\n{\n}";

    return output;
}
