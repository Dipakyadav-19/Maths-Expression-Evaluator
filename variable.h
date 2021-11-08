

#ifndef USER_VARIABLES_H
#define USER_VARIABLES_H

#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>


using namespace std;

const int NAME_LEN_MAX = 30;
const int EXPR_LEN_MAX = 255;
const int ERR_LEN_MAX = 255;


void toupper(char upper[], const char str[]);


class Variablelist {
    public:
        bool exist(const char* name);
        bool add(const char* name, double value);
        bool del(const char* name);

        bool get_value(const char* name, double* value);
        bool get_value(const int id, double* value);
        int  get_id(const char* name);
        bool set_value(const char* name, const double value);

    private:
        struct VAR
        {
            char name[NAME_LEN_MAX+1];
            double value;
        };

        vector<VAR> var;
};



#endif
