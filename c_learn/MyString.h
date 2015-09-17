#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#endif

#include <iostream>



namespace LHS
{

class String
{

public:
        String();
        String(const String&);
        String(const char*);

        ~String();

        bool operator==(const String&);
        bool operator==(const char*);

        String& operator=(const String&);
        String& operator=(const char*);

        char& operator[](int);

//just for fun

        friend String operator*(const String &a, const String &b);
/*
        {
              int aa = a._size;
              return String("this is just for fun!");
        }
*/
        inline int size();
        char* c_str();
private:
        int _size;
        char* _cstr;

};

}
