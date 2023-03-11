#include "periodicals.h"

using namespace std;

Periodicals::Periodicals(char bookType, char format, string title,int month , int year, int copies)
    : Book(bookType, 'H', title,month, year, 1)
{
}

Periodicals::~Periodicals()
{

}

bool Periodicals::operator==(const Book &rhs) const
{
    if (getAuthor() == rhs.getAuthor() && getTitle() == rhs.getTitle())
        return true;
    else
        return false;
}

bool Periodicals::operator!=(const Book &rhs) const
{
    return !(*this == rhs);
}

bool Periodicals::operator>(const Book &rhs) const
{
    if (getYear() > rhs.getYear())
        return true;
    else if (getYear() == rhs.getYear() && getMonth() > rhs.getMonth())
        return true;
    else if (getYear() == rhs.getYear() && getMonth() == rhs.getMonth() &&
            getTitle() > rhs.getTitle())
        return true;
    else
        return false;
}

bool Periodicals::operator<(const Book &rhs) const
{
    return !(*this > rhs);
}