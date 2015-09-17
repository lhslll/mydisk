#include "MyString.h"
#include <cstring>

LHS::String::String()
{
        _size = 0;
        _cstr = 0;
}

LHS::String::String(const String& rhs)
{
        _size = rhs._size;
        _cstr = new char[_size+1];
        strcpy(_cstr, rhs._cstr);
}

LHS::String::String(const char* rhs)
{
        _size=strlen(rhs);
        _cstr = new char[_size+1];
        strcpy(_cstr, rhs);
}

inline int LHS::String::size()
{
        return _size;
}

inline char* LHS::String::c_str()
{
        return _cstr;
}
LHS::String& LHS::String::operator=(const char *rhs)
{
        if(_cstr)
        {
                delete [] _cstr;
        }

        _size = strlen(rhs);
        _cstr = new char[_size+1];
        strcpy(_cstr,rhs);
        return *this;
}

LHS::String& LHS::String::operator=(const LHS::String& rhs)
{
        if(this != &rhs)
        {
                if(_cstr)
                {
                        delete [] _cstr;
                }
                _size = rhs._size;
                _cstr = new char[_size+1];
                strcpy(_cstr, rhs._cstr);
        }
        return *this;
}

bool LHS::String::operator==(const char *rhs)
{
        return strcmp(_cstr, rhs) == 0 ? true:false;
}

bool LHS::String::operator==(const LHS::String &rhs)
{
        return strcmp(_cstr, rhs._cstr)==0?true:false;
}

char& LHS::String::operator[](int index)
{
        return *(_cstr+index);
}


LHS::String::~String()
{
        if(_cstr)
        {
                delete [] _cstr;
        }
}


namespace LHS
{

String operator*(const String &lhs, const String &rhs)
{
        return LHS::String("abc");
        //String tmp("this is just for fun");
        //*this = tmp;
        //return *this;
}

}
