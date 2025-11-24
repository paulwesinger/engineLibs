#ifndef ERROR_H
#define ERROR_H
#include <string>

class ErrorLogs
{
public:
    static void Warning(bool isExpressionTrue,const std::string message);
    static void Failed(bool isExpressionTrue,const std::string message, bool & errorflag );

private:

    ErrorLogs() {}
};

#endif // ERROR_H
