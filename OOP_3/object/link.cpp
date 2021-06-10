#include "link.h"

Link::Link() noexcept
{
    first_ind = 0;
    second_ind = 0;
}

Link::Link(const size_t &fst_ind, const size_t &snd_ind) noexcept
{
    first_ind = fst_ind;
    second_ind = snd_ind;    
}

Link::Link(const Link &lnk) noexcept
{
    first_ind = lnk.first_ind;
    second_ind = lnk.second_ind;    
}

size_t Link::getFirst() const noexcept
{
    return first_ind;

}

size_t Link::getSecond()const noexcept
{
    return second_ind;

}

void Link::setFirst(const size_t &fst_ind) noexcept
{
    this->first_ind = fst_ind;
}

void Link::setSecond(const size_t &snd_ind) noexcept
{
    this->second_ind = snd_ind;
}

std::istream &operator>>(std::istream &is, Link &lnk) //не обязательно
{
    size_t fst_ind, snd_ind;
    is >> fst_ind >> snd_ind;
    lnk.setFirst(fst_ind);
    lnk.setSecond(snd_ind);

    return is;
}

Link &Link::operator = (const Link &lnk) noexcept
{
    this->first_ind = lnk.getFirst();
    this->second_ind = lnk.getSecond();
    return *this;
}

std::ostream &operator << (std::ostream &os, const Link &lnk)  
{
    os << lnk.getFirst() << " " << lnk.getSecond() << "\n";

    return os;
}

