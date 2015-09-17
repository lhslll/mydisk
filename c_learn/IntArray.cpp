#include "IntArray.h"
#include <iostream>

IntArray::IntArray(int sz)
{
        _size = sz;
        ia = new int[_size];
        for(int i; i< _size; i++)
        {

                *ia =0;
                std::cout << *ia << std::endl;
                std::cout << ia << std::endl;
                ia++;
        }
}

IntArray::~IntArray()
{
        delete [] ia;

}
