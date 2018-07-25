#ifndef OPEQOVERLOADTOOL_H_INCLUDED
#define OPEQOVERLOADTOOL_H_INCLUDED

#include <wx/dialog.h>
#include "TBToolHandler.h"

/**
 * A tool handler which generates operator equals overloading code.
 */
class OpEqOverloadToolHandler : public TBToolHandler
{
public:
    /**
     * Constructs a new handler.
     */
    OpEqOverloadToolHandler();

    /**
     * Destructor.
     */
    virtual ~OpEqOverloadToolHandler();

    /**
     * Gets the processor which converts input parameters to a string of code.
     *
     * @return A shared pointer to the tool processor.
     */
    virtual shared_ptr<TBToolProcessor> getIOProcessor();

    /**
     * Executes the code generation process with the given input. Prints the generated
     * code to the log.
     */
    virtual void execute(const string& input);

    /**
     * Shows the UI which will call the execute function if the user presses "OK."
     */
    virtual void showUI();
private:
    /**
     * A shared pointer to the tool processor.
     */
    shared_ptr<TBToolProcessor> _processor;

    /**
     * A shared pointer to the UI.
     */
    shared_ptr<wxDialog> _ui;
};

#endif // OPEQOVERLOADTOOL_H_INCLUDED
