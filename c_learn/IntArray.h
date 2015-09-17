#ifndef _LHS_INTARRAY_
#define _LHS_INTARRAY_
#endif

class IntArray
{
public:
        explicit IntArray(int sz);
        IntArray(int *array, int array_size);
        IntArray(const IntArray &rhs);

        bool operator==(const IntArray&) const;
        bool operator!=(const IntArray&) const;
        IntArray& operator=(const IntArray&);
        int& operator[](int index);

        int size() const;
        void sort();

        int min() const;
        int max() const;

        int find(int value) const;

        ~IntArray();
private:

        //static int DefaultSize = 10;
        int _size;
        int *ia;
};
