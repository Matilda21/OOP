#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector.h"
#include "iterator.h"

template <typename T>
Vector<T>::Vector() 
{
    this->allocate_new(100);
    this->size = 0;

}

template <typename T>
Vector<T>::Vector(const T *arr, size_t _size)
{
    if (!arr)
    {

    }
    this->allocate_new(_size*2);
    for (size_t i = 0; i < _size; i++)
    {
        this->pushBack(*(arr+i));
    }
}

template <typename T>
Vector<T>::Vector(const T &elem, size_t _size)
{
    this->allocate_new(100);

    for (size_t i = 0; i < _size; i++)
    {
        this->pushBack(elem);
    }
}


template <typename T>
bool Vector<T>::isEmpty() const noexcept
{
    return this->size == 0;
}

template <typename T>
size_t Vector<T>::getSize() const noexcept
{
    return this->size;
}

template <typename T>
T &Vector<T>::at(size_t pos) const
{
    if (pos >= this->size)
    {
        //std::cout << "Index out of range";

    }

    return this->value[pos];
}

template <typename T>
Vector<T> &Vector<T>::pushBack(const T &elem)
{
    if (this->memo_allocated <= this->size)
    {
        this->allocate_new(size*2);
    }
    this->value[this->size] = elem;
    this->size ++;
    return *this;

}

template <typename T>
void Vector<T>::remove(size_t pos)
{
    
    if (pos >= this->size)
    {


    }

    for (size_t i = pos; i < this->size-1; i++)
    {
        this->value[i] = this->value[i+1];
    }
    
    this->size = this->size-1;
}

template <typename T>
void Vector<T>::remove(Iterator<T> iter)
{
    
    size_t pos = 0;
    for (Iterator<T> tmp_iter = this->begin(); tmp_iter != iter; tmp_iter++, pos++);

    this->remove(pos);
 
}

template <typename T>
Vector<T> &Vector<T>::operator += (const T &elem)
{
    return this->pushBack(elem);
}

template <typename T>
Iterator<T> Vector<T>::begin() const noexcept
{
    return Iterator<T>(*this);
}

template <typename T>
const Iterator<T> Vector<T>::cbegin() const noexcept
{
    return Iterator<T>(*this);
}

template <typename T>
Iterator<T> Vector<T>::end()const noexcept
{
    return Iterator<T>(*this) + this->size;
}

template <typename T>
const Iterator<T> Vector<T>::cend() const noexcept
{
    return Iterator<T>(*this) + this->size;    
}

template <typename T>
void Vector<T>::allocate_new(size_t new_size)//разобраться с памятью от tmp_value
{
   // std::shared_ptr<T[]> tmp_value = value;
    try
    {
        this->value.reset(new T[new_size]);
    }     
    catch (std::bad_alloc &exeption)
    {

    }
    this->memo_allocated = new_size;

   // if (this->size > 0)
   // {
     //   for (size_t i = 0; i < this->size; i++)
      //  {
      //      value[i] = tmp_value[i];
     //  }
   // }

}

template<typename T>
std::ostream &operator << (std::ostream &os, const Vector<T> &vec)  
{
    for (auto el : vec)
    {
        os << el << "\n";
    }
    return os;
}

#endif
