#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>
#include <memory>


template <typename T>
class Vector;

template <typename T>
class Point;

template <typename T>
class Iterator : public std::iterator<std::input_iterator_tag, T>
{
    public:
    Iterator() = default;
    Iterator(const Vector<T> &vec);
    Iterator(const Iterator<T> &iter);

    Iterator<T> &operator = (const Iterator<T> &iter);

    T &operator *();
    const T &operator *() const;

    T *operator ->();
    const T *operator ->() const;

    operator bool() const;//ANOTHER

    bool operator ==  (const Iterator<T> &iter) const;
    bool operator !=  (const Iterator<T> &iter) const;

    Iterator<T> &operator += (size_t num);
    Iterator<T> &operator + (size_t num);

    Iterator<T> &operator ++ ();
    Iterator<T> &operator ++ (int);//ANOTHER

    private:
        std::weak_ptr<T[]> ptr;
        size_t cur_index;
        size_t vec_size;
        T *get_cur() const;

};

#include "iterator.hpp"

#endif
