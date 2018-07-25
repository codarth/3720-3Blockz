#ifndef HASHTOOLHANDLER_H
#define HASHTOOLHANDLER_H

#include <memory>
#include <wx/dialog.h>
#include "TBToolHandler.h"
#include "TBToolProcessor.h"

using std::shared_ptr;

class HashToolHandler : public TBToolHandler
{
public:
    HashToolHandler();

    virtual ~HashToolHandler();

    virtual shared_ptr<TBToolProcessor> getIOProcessor();

    virtual void execute(const string &input);

    virtual void showUI();
private:
    /**
    * @brief A shared pointer to the tool processor.
    */
    shared_ptr<TBToolProcessor> _processor;

    /**
     * @brief A shared pointer to the UI.
     */
    shared_ptr<wxDialog> _ui;
};

#endif /* HASHTOOLHANDLER_H */
