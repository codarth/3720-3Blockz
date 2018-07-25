#include <sdk.h>
#include <logmanager.h>
#include "../include/rapidjson/document.h"
#include "../include/OpEqOverloadToolHandler.h"
#include "../include/OpEqOverloadToolProcessor.h"
#include "../include/ToolProcessorNotFoundException.h"
#include "../include/EqOpOverloadUI.h"

OpEqOverloadToolHandler::OpEqOverloadToolHandler():_processor(std::make_shared<OpEqOverloadToolProcessor>())
{

}

OpEqOverloadToolHandler::~OpEqOverloadToolHandler()
{

}

shared_ptr<TBToolProcessor> OpEqOverloadToolHandler::getIOProcessor()
{
    return this->_processor;
}

void OpEqOverloadToolHandler::execute(const string& input)
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

void OpEqOverloadToolHandler::showUI()
{
    if (this->_ui.get() == nullptr)
    {
        this->_ui = std::make_shared<EqOpOverloadUI>();
    }

    this->_ui->Show(true);
}
