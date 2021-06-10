#include "loader.h"
#include <iostream>
#include "exceptions/load_exceptions.h"

void FileLoader::src_open(const std::string &srcname)
{
    this->file.open(srcname);

    if (!file)
    {
        qDebug() << "cant open file";
        throw file_open_exception();
    }
    qDebug() << "opened file";

}
void FileLoader::src_close()
{
    try
    {
         this->file.close();
    }
    catch (std::ifstream::failure &error)
    {
        error.what();

    }
}

void FileLoader::load_point(Point<double> &point)
{
    double x, y, z;

    if (!(this->file >> x >> y >> z))
        throw file_format_exception();

    point.setX(x);
    point.setY(y);
    point.setZ(z);
}
void FileLoader::load_link(Link &link)
{
    size_t ind_one, ind_two;

    if (!(this->file >> ind_one >> ind_two))
        throw file_format_exception();
    link.setFirst(ind_one);
    link.setSecond(ind_two);
}

size_t FileLoader::load_number()
{
    size_t num;

    if (!(this->file >> num))
            throw file_format_exception();
    return num;
}
