#ifndef _LHS_TARRAY_
#define _LHS_TARRAY_
#endif

template <class elemType>
class TArray
{
public:
       explicit TArray(int sz)
       {
               _size = sz;
               ia = new elemType[_size];

       }

private:

        int _size;
        elemType *ia;


};
