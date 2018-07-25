#include "../include/rapidjson/document.h"
#include "../include/HashToolProcessor.h"
#include "../include/ParseException.h"

using rapidjson::Document;
using rapidjson::ParseResult;

HashToolProcessor::HashToolProcessor()
{

}

HashToolProcessor::~HashToolProcessor()
{

}

string HashToolProcessor::process(const string &input)
{
    // The input format is expected to be an encoded json string
    Document doc;

    ParseResult parseResult = doc.Parse(input.c_str());
    if (!parseResult)
    {
        throw ParseException("Could not parse the input JSON encoded string.");
    }

    if (!doc.HasMember("struct_name"))
    {
        throw ParseException("Document does not contain member 'struct_name.'");
    }

    if (!doc["struct_name"].IsString())
    {
        throw ParseException("Document member 'struct_name' must be a string.");
    }

    if (!doc.HasMember("type_name"))
    {
        throw ParseException("Document does not contain member 'type_name.'");
    }

    if (!doc["type_name"].IsString())
    {
        throw ParseException("Document member 'type_name' must be a string.");
    }

    string structName(doc["struct_name"].GetString());
    string typeName(doc["type_name"].GetString());

    string output = string("struct ") + structName + "\n{\n\tstd::size_t operator()("
        + typeName + " const &o) const noexcept\n\t{" + "\n\t\treturn 0;" + "\n\t}\n};";

    return output;
}