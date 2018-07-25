#ifndef PARSEEXCEPTION_H_INCLUDED
#define PARSEEXCEPTION_H_INCLUDED

#include <exception>

using std::exception;

class ParseException : public exception
{
public:
    explicit ParseException(const exception &other, const char* message):exception(other),
        _message(message) {}

    explicit ParseException(const char *message) : exception(), _message(message) {}

    virtual ~ParseException() {}

    virtual const char* what() const noexcept
    {
        return this->_message;
    }
private:
    const char* _message;
};

#endif // PARSEEXCEPTION_H_INCLUDED
