#include <sdk.h>
#include <logmanager.h>
#include "../include/HashToolHandler.h"
#include "../include/HashToolProcessor.h"
#include "../include/HashToolUI.h"
#include "../include/ToolProcessorNotFoundException.h"

using std::make_shared;

HashToolHandler::HashToolHandler():_processor(make_shared<HashToolProcessor>()),_ui(shared_ptr<wxDialog>(nullptr))
{

}

HashToolHandler::~HashToolHandler()
{
    this->_processor.reset();
}

shared_ptr<TBToolProcessor> HashToolHandler::getIOProcessor()
{
    return this->_processor;
}

void HashToolHandler::execute(const string &input)
{
    shared_ptr<TBToolProcessor> processor = getIOProcessor();
    if (processor.get() == nullptr)
    {
        throw ToolProcessorNotFoundException("No tool processor for OpEqOverloadToolHandler.");
    }

    string output = processor->process(input);

    wxString wxOutput(output.c_str(), wxConvUTF8);

    Manager::Get()->GetLogManager()->Log(wxOutput);
}

void HashToolHandler::showUI()
{
    if (this->_ui.get() == nullptr)
    {
        this->_ui = std::make_shared<HashToolUI>();
    }

    this->_ui->Show(true);
}
