#include "TArray.h"

template <class elemType>
TArray<elemType>::TArray(int sz)
{
        _size = sz;
        ia = new elemType[_size];

        for(int i=0;i<_size;i++)
        {

        }

}
