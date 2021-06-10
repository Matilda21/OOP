#pragma once

#include <istream>
#include <memory>
#include <math.h>
#include <iostream>
#define PI 3.1415
#include <QDebug>

template <typename T>
class Point
{
    public:
        explicit Point() noexcept;
        explicit Point(const T &x, const T &y, const T &z) noexcept;
        Point(const Point &pt) noexcept;
        Point(const Point &&pt) noexcept;

        Point &operator = (const Point &pt) noexcept;
        bool operator == (const Point &pt) const noexcept;
        bool operator != (const Point &pt) const noexcept;

        Point &operator +=(const T &coord) noexcept;
        Point &operator +=(const Point &pt) noexcept;

        Point &operator -=(const T &coord) noexcept;
        Point &operator -=(const Point &pt) noexcept;
        Point &operator *=(const T &coord) noexcept;
        Point &operator *=(const Point &pt) noexcept;
        Point &operator /=(const T &coord) noexcept;
        Point &operator /=(const Point &pt) noexcept;

        void move (const T &dx, const T &dy, const T &dz);
        void scale(const Point<T> &cen, const T &kx, const T &ky, const T &kz);
        void turn (const Point<T> &cen, const T &ox, const T &oy, const T &oz);

        void turn_x(const T &ox);
        void turn_y(const T &oy);
        void turn_z(const T &oz);

        T getX() const noexcept;
        T getY() const noexcept;
        T getZ() const noexcept;
        void setX(const T &x) noexcept;
        void setY(const T &y) noexcept;
        void setZ(const T &z) noexcept;

        private:
        T _x;
        T _y;
        T _z;
};

template <typename T>
Point<T>::Point() noexcept
{
    _x = 0;
    _y = 0;
    _z = 0;
}

template <typename T>
Point<T>::Point(const T &x, const T &y, const T &z) noexcept
{
    _x = x;
    _y = y;
    _z = z;
}

template <typename T>
Point<T>::Point(const Point<T> &pt) noexcept
{
    _x = pt._x;
    _y = pt._y;
    _z = pt._z;
}

template <typename T>
Point<T>::Point(const Point<T> &&pt) noexcept
{
    _x = pt._x;
    _y = pt._y;
    _z = pt._z;
    pt.~Point();
}

template <typename T>
Point<T> &Point<T>::operator = (const Point<T> &pt) noexcept
{
    _x = pt._x;
    _y = pt._y;
    _z = pt._z;
    pt.~Point();
    return *this;    
}

template <typename T>
Point<T> &Point<T>::operator += (const Point<T> &pt) noexcept
{
    _x += pt._x;
    _y += pt._y;
    _z += pt._z;
    return *this;    
}

template <typename T>
Point<T> &Point<T>::operator += (const T &coord) noexcept
{
    _x += coord;
    _y += coord;
    _z += coord;
    return *this;    
}

template <typename T>
Point<T> &Point<T>::operator -= (const Point<T> &pt) noexcept
{
    _x -= pt._x;
    _y -= pt._y;
    _z -= pt._z;
    return *this;    
}

template <typename T>
Point<T> &Point<T>::operator -= (const T &coord) noexcept
{
    _x -= coord;
    _y -= coord;
    _z -= coord;
    return *this;    
}

template <typename T>
Point<T> &Point<T>::operator *= (const Point<T> &pt) noexcept
{
    _x *= pt._x;
    _y *= pt._y;
    _z *= pt._z;
    return *this;    
}

template <typename T>
Point<T> &Point<T>::operator *= (const T &coord) noexcept
{
    _x *= coord;
    _y *= coord;
    _z *= coord;
    return *this;    
}

template <typename T>
Point<T> &Point<T>::operator /= (const Point<T> &pt) noexcept
{
    _x /= pt._x;
    _y /= pt._y;
    _z /= pt._z;
    return *this;    
}

template <typename T>
Point<T> &Point<T>::operator /= (const T &coord) noexcept
{
    _x /= coord;
    _y /= coord;
    _z /= coord;
    return *this;    
}

template <typename T>
void Point<T>::move(const T &dx, const T &dy, const T &dz)
{
    qDebug() << "MOVE" << dx << dy << dz;
    (*this) += Point<T>(dx, dy, dz);
}

template <typename T>
void Point<T>::scale(const Point<T> &cen, const T &kx, const T &ky, const T &kz)
{
    qDebug() << "SCALE" << kx << ky << kz;
    //*this *= Point<T>(kx, ky, kz);
    this->setX((this->getX() - cen.getX()) * kx + cen.getX());
    this->setY((this->getY() - cen.getY()) * ky + cen.getY());
    this->setZ((this->getZ() - cen.getZ()) * kz + cen.getZ());
}

template <typename T>
void Point<T>::turn(const Point<T> &cen, const T &ox, const T &oy, const T &oz)
{
    (*this) -= cen;

    qDebug() << "TURN" << ox << oy << oz;
    this->turn_x(ox);
    this->turn_y(oy);
    this->turn_z(oz);

    (*this) += cen;
}

template <typename T>
void Point<T>::turn_x(const T &ox)
{
    const T temp_y = this->_y;
    this->_y = _y * cos(ox * PI / 180) + _z * sin(ox * PI / 180);
    this->_z = -temp_y * sin(ox * PI / 180) + _z * cos(ox * PI / 180);    
}

template <typename T>
void Point<T>::turn_y(const T &oy)
{
    const T temp_x = this->_x;
    this->_x = _x * cos(oy * PI / 180) + _z * sin(oy * PI / 180);
    this->_z = -temp_x * sin(oy * PI / 180) + _z * cos(oy * PI / 180);
}

template <typename T>
void Point<T>::turn_z(const T &oz)
{
    const T temp_x = this->_x;
    this->_x = _x * cos(oz * PI / 180) + _y * sin(oz * PI / 180);
    this->_y = -temp_x * sin(oz * PI / 180) + _y * cos(oz * PI / 180);
}

template <typename T>
bool Point<T>::operator == (const Point<T> &pt) const noexcept
{
    return _x == pt._x && _y == pt._y && _z == pt._z;
}

template <typename T>
bool Point<T>::operator != (const Point<T> &pt) const noexcept
{
    return !(this == pt);
}

template <typename T>
T Point<T>::getX() const noexcept
{
    return _x;
}

template <typename T>
T Point<T>::getY() const noexcept
{
    return _y;
}

template <typename T>
T Point<T>::getZ() const noexcept
{
    return _z;
}

template <typename T>
void Point<T>::setX(const T &x) noexcept
{
     _x = x;
}

template <typename T>
void Point<T>::setY(const T &y) noexcept
{
     _y = y;
}

template <typename T>
void Point<T>::setZ(const T &z) noexcept
{
     _z = z;
}

template <typename T>
std::istream &operator >> (std::istream &is, Point<T> &pt) //ввод точки из потока ввода
{
    T x, y, z;
    is >> x >> y >> z;
    pt.setX(x);
    pt.setY(y);
    pt.setZ(z);

    return is;
}

template<typename T>
std::ostream &operator << (std::ostream &os, const Point<T> &pt)  
{
    os << pt.getX() << " " << pt.getY() << " " << pt.getZ() << "\n";

    return os;
}






