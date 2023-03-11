#include "fictionBook.h"

using namespace std;

FictionBook::FictionBook(char bookType, char format, string author, string title, int year, int copies)
    : Book(bookType, 'H', author, title, year, 5)
{
}

bool FictionBook::operator==(const Book &rhs) const
{
    if (getAuthor() == rhs.getAuthor() && getTitle() == rhs.getTitle())
        return true;
    else
        return false;
}

bool FictionBook::operator!=(const Book &rhs) const
{
    return !(*this == rhs);
}

bool FictionBook::operator>(const Book &rhs) const
{
    if (getAuthor() > rhs.getAuthor())
        return true;
    else if (getAuthor() == rhs.getAuthor() && getTitle() > rhs.getTitle())
        return true;
    else
        return false;
}

bool FictionBook::operator<(const Book &rhs) const
{
    return !(*this > rhs);
}
