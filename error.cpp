


#include "error.h"

using namespace std;



Error::Error(const int row, const int col, const int id, ...)
: err_row(row), err_col(col), err_id(id)
{
    //sprintf(msg, msgdesc(id));
    const char* msg_desc = msgDecode(id);

    va_list args;
    va_start(args, msg_desc);
    vsnprintf(msg, sizeof(msg)-1, msg_desc, args);
    msg[sizeof(msg)-1] = '\0';
    va_end(args);
}

/**
 * Returns a pointer to the message description for the given message id.
 * Returns "Unknown error" if id was not recognized.
 */
const char* Error::msgDecode(const int id)
{
    switch (id)
    {
        // syntax errors
        case 1: return "Syntax error in part \"%s\"";
        case 2: return "Syntax error";
        case 3: return "Parentesis ) missing";
        case 4: return "Empty expression";
        case 5: return "Unexpected part \"%s\"";
        case 6: return "Unexpected end of expression";
        case 7: return "Value expected";

        // wrong or unknown operators, functions, variables
        case 101: return "Unknown operator %s";
        case 102: return "Unknown function %s";
        case 103: return "Unknown variable %s";

        // domain errors
        case 200: return "Too long expression, maximum number of characters exceeded";

        // error in assignments of variables
        case 300: return "Defining variable failed";

        // error in functions
        case 400: return "Integer value expected in function %s";
    }

    return "Unknown error";
}
