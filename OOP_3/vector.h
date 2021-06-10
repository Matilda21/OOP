#ifndef VECTOR_H
#define VECTOR_H
//Romanov
#include <istream>
#include <memory>

#include "iterator.h"

class baseVector
{
    public:
        virtual size_t getSize() const noexcept= 0;
        virtual bool isEmpty() const noexcept= 0;
        virtual ~baseVector() = default;
    
    protected: 
        size_t size;
};

template <typename T>
class Vector : public baseVector
{

    friend class Iterator<T>;

    public:
        Vector();
        Vector(const T *arr, size_t _size);
        Vector(const T &elem, size_t _size);

        virtual ~Vector() = default;
        virtual bool isEmpty() const noexcept override;
        virtual size_t getSize() const noexcept override;

        T &at(size_t pos) const;

        Vector<T> &pushBack(const T &elem);

        void remove(size_t pos);
        void remove(Iterator<T> iter);//РЕАЛИЗОВАТЬ

        Vector<T> &operator += (const T &elem);

        Iterator<T> begin() const noexcept;
        const Iterator<T> cbegin() const noexcept;

        Iterator<T> end() const noexcept;
        const Iterator<T> cend() const noexcept;

    private:
        std::shared_ptr<T[]> value;
        size_t memo_allocated;
        void allocate_new(size_t new_size);//РАЗОБРАТЬСЯ С ПАМЯТЬЮ
};

#include "vector.hpp"

#endif

