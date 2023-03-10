#include "childrenBook.h"
using namespace std;

ChildrenBook::ChildrenBook(char bookType, string author, string title, int year)
: Book(bookType, author, title, year)
{

}
    
ChildrenBook::~ChildrenBook()
{

}

bool ChildrenBook::operator==(const Book& book) const
{
    if (this->author == book.getAuthor() && this->title == book.getTitle())
        return true;
    else
        return false;
}

bool ChildrenBook::operator>(const Book& book) const
{
    if (author > book.getAuthor())
        return true;
    else if (author == book.getAuthor() && title > book.getTitle())
        return true;
    else
        return false;
}

bool ChildrenBook::operator<(const Book& book) const
{
    if (author < book.getAuthor())
        return true;
    else if (author == book.getAuthor() && title < book.getTitle())
        return true;
    else
        return false;
}

bool ChildrenBook::operator!=(const Book& book) const
{
    return !(*this == book);
}
