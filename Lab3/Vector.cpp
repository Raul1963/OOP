//
// Created by raulm on 3/24/2024.
//

#include "Vector.h"
#include <exception>

template<typename T>
Vector<T>::Vector(size_t cap)
{
    this->_capacity = cap;
    this->_elements = new T[cap];
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] this->_elements;
}

template<typename T>
void Vector<T>::_resize()
{
    _capacity = 2 * _size;
    T* tmp = new T[_capacity];

    for (size_t i = 0; i < _size; i++)
    {
        tmp[i] = _elements[i];
    }

    delete[] _elements;
    _elements = tmp;
}

template<typename T>
void Vector<T>::add(T i)
{
    if (_capacity == 0)
    {
        _resize();
        // *((unsigned int*)0) = 0xDEAD;
    }

    _capacity--;
    _elements[_size] = i;
    _size++;
}

template<typename T>
void Vector<T>::print()
{
//    for (size_t i = 0; i < _size; i++)
//    {
//        std::printf("%d ", _elements[i]);
//    }
//
//    std::printf("\n");
}

template<typename T>
std::string Vector<T>::getElem(int i) {
    auto elem=_elements[i];
    return elem;
}

template<typename T>
void Vector<T>::modifyElem(int index, T elem) {
    if(index>=_size){
        throw std::exception();
    }
    _elements[index]=elem;
}

template<typename T>
int Vector<T>::getIndex(T elem) {
    for(int i=0;i<_size;i++){
        if(_elements[i]==elem){
            return i;
        }
    }
    return -1;
}
//int main()
//{
//    {
//        Vector<std::string> v(2);
//        v.print();
//        v.add("1");
//        v.add("2");
//        v.add("3");
//        std::cout<<v.getElem(1);
////        v.print();
//    }
//
//    return 0;
//}