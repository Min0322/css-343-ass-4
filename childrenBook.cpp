#include "childrenBook.h"
using namespace std;

ChildrenBook::ChildrenBook(char bookType, char format, string author, string title, int year, int copies)
    : Book(bookType, 'H', author, title, year, 5)
{

}
    
ChildrenBook::~ChildrenBook()
{

}

bool ChildrenBook::operator==(const Book& book) const
{
    if (getAuthor() == book.getAuthor() && getTitle() == book.getTitle())
        return true;
    else
        return false;
}

bool ChildrenBook::operator!=(const Book& book) const
{
    return !(*this == book);
}

bool ChildrenBook::operator>(const Book& book) const
{
    if (getTitle() > book.getTitle())
        return true;
    else if (getTitle() == book.getTitle() && getAuthor() > book.getAuthor())
        return true;
    else
        return false;
}

bool ChildrenBook::operator<(const Book& book) const
{
    return !(*this > book);
}
