#ifndef DATATYPEEXCEPTION_H_INCLUDED
#define DATATYPEEXCEPTION_H_INCLUDED

#include <stdexcept>

#include <iostream>
#include <string>

using std::runtime_error;

class DataTypeException :public runtime_error
{
    public:
        DataTypeException():runtime_error("Tipo de dato incorrecto"){};
}
;


#endif