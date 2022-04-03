#include <iostream>

using namespace std;

template <class T> class ShiftedList {
    T* array;
    int offset, size;
    public:
        ShiftedList(int sz) : offset(0), size(sz) {
            array = new T[size];
        }

        ~ShiftedList() {
            delete [] array;
        }

        void shiftBy(int n) {
            offset = (offset + n) % size;
        }

        T getAt(int i) {
            return array[convertIndex(i)];
        }

        
        void setAt(T item, int i) {
            array[convertIndex(i)] = item;
        }
    
    private:
        int convertIndex(int i) {
            int index = (i - offset) % size;
            while(index < 0) index += size;
            return index;
        }
};