#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator.h"

template <typename T>
Iterator<T>::Iterator(const Vector<T> &vec)
{
    this->ptr = vec.value;
    this->vec_size = vec.getSize();
    this->cur_index = 0;
}

template <typename T>
Iterator<T>::Iterator(const Iterator<T> &iter)
{
    this->ptr = iter.ptr.lock();
    this->vec_size = iter.vec_size;
    this->cur_index = iter.cur_index;
}

template <typename T>
Iterator<T> &Iterator<T>::operator = (const Iterator<T> &iter)
{
    this->ptr = iter.ptr.lock();
    this->vec_size = iter.vec_size;
    this->cur_index = iter.cur_index;
    return *this;    
}

template <typename T>
T &Iterator<T>::operator *()
{
    return *(this->get_cur());
   
}

template <typename T>
const T &Iterator<T>::operator *() const
{
    return *(this->get_cur());
}

template <typename T>
T *Iterator<T>::operator ->()
{
    return this->get_cur();    
}

template <typename T>
const T *Iterator<T>::operator ->() const
{
    return *(this->get_cur());   
}

template <typename T>
Iterator<T>::operator bool() const
{
    return (!(this->ptr.expired()) && this->ptr.lock() != nullptr && this->cur_index < this->vec_size && this->vec_size);
}

template <typename T>
bool Iterator<T>::operator ==  (const Iterator<T> &iter) const
{
    return (this->cur_index == iter.cur_index);

}

template <typename T>
bool Iterator<T>::operator !=  (const Iterator<T> &iter) const
{
    return this->cur_index != iter.cur_index;
}

template <typename T>
Iterator<T> &Iterator<T>::operator += (size_t num)
{
    this->cur_index += num;
    return *this;
}

template <typename T>
Iterator<T> &Iterator<T>::operator + (size_t num)
{
    this->cur_index += num;
    return *this;    
}

template <typename T>
Iterator<T> &Iterator<T>::operator ++ ()
{
    this->cur_index ++;
    return *this;
}

template <typename T>
Iterator<T> &Iterator<T>::operator ++ (int)
{
    Iterator tmp_iter(*this);
    this->cur_index ++;
    return tmp_iter;
}

template <typename T>
T *Iterator<T>::get_cur() const
{
    return (this->ptr.lock().get())+(this->cur_index);
}

#endif