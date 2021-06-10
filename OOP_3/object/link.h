#ifndef LINK_H
#define LINK_H

#include <istream>
#include <memory>

class Link
{
    public:
        Link() noexcept;
        Link(const size_t &fst_ind, const size_t &snd_ind) noexcept;
        Link(const Link &lnk) noexcept;

        Link &operator = (const Link &lnk) noexcept;

        size_t getFirst() const noexcept;
        size_t getSecond() const noexcept;

        ~Link() = default;

        void setFirst(const size_t &fst_ind) noexcept;
        void setSecond(const size_t &snd_ind) noexcept;


    private:
        size_t first_ind;
        size_t second_ind;
};

#endif