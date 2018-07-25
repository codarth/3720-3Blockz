#ifndef TOOLPROCESSORNOTFOUNDEXCEPTION_H_INCLUDED
#define TOOLPROCESSORNOTFOUNDEXCEPTION_H_INCLUDED

#include <exception>

using std::exception;

class ToolProcessorNotFoundException : public exception
{
public:
    ToolProcessorNotFoundException(const exception& other, const char* message):exception(other),
        _message(message) {}

    ToolProcessorNotFoundException(const char* message):_message(message) {}

    virtual ~ToolProcessorNotFoundException() {}

    const char* what() const noexcept
    {
        return this->_message;
    }
private:
    const char* _message;
};

#endif // TOOLPROCESSORNOTFOUNDEXCEPTION_H_INCLUDED
