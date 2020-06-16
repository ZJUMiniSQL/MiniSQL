#ifndef error_h
#define error_h

#include <string>
#include <vector>
static std::vector<std::string> ErrorInfo = {
    "database storage failed",                       //0
    "database does not exist",                       //1
    "table does not exist",                          //2
    "table already exists",                          //3
    "database already exists",                       //4
    "More than 32 attributes",                       //5
    "Out of char range(1~255)",                      //6
    "More than 2 primary keys",                      //7
    "Already have index or attribute is not unique", //8
    "Has no index",                                  //9
    "Has no attribute",                              //10
    "Unknown kind Fault",                            //11
    "Cann't +-*/ string",                            //12
    "Invalid where clause",                          //13
    "Invalid operation",                             //14
    "Attribute not exists",                          //15
    "Duplicated index value",                        //16
    "Unexist value",                                 //17
    "SQL syntax error",                              //18
    "Unknown error",                                 //19
    "Exit",                                          //20
    "Attribute number error"                         //21
};
class Exit
{
};
class Error
{
public:
    int error_number;
    Error(int number)
    {
        error_number = number;
        error_content = "";
    }
    Error(int number, std::string content)
    {
        error_number = number;
        error_content = content;
    }
    void print_error()
    {
        std::cout << ErrorInfo[error_number] << ":" << error_content << std::endl;
    }

private:
    std::string error_content;
};
#endif