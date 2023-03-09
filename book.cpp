#include "book.h"
#include "stdio.h"


Book :: Book()
{

}

Book :: Book(char bookType, string author, string title, int year)
{
    this->bookType = bookType;
    this->author = author;
    this->title = title;
    this->year = year;
}

Book :: Book(char bookType, string author, string title, int month, int year)
{
    this->bookType = bookType;
    this->author = author;
    this->title = title;
    this->month = month;
    this->year = year;
}

Book :: ~Book()
{

}

  // set the book type: children, fiction, or periodicals
char Book :: getBookType() const
{
    return bookType;
}
  // set the book title
string Book :: getTitle() const
{
    return title;
}
  // set the year published
int Book :: getYear() const
{   
    return year;
}
// set the month published (only periodicals)
int Book :: getMonth() const
{
    return month;
}
// set the number of copies in stock
int Book :: getCopies() const
{
    return copies;
}

Book& Book :: operator = (Book& rhs)
{
    if(this != &rhs)
    {
    this->bookType = bookType;
    this->author = author;
    this->title = title;
    this->month = month;
    this->year = year;
    }
    return *this;
}

bool Book :: operator == (const Book &rhs) const
{
    if(this->title == rhs.title && this->author == rhs.author && this-> year == rhs.year)
    {
        return true;
    }else{
        return false;
    }
}

bool Book :: operator != (const Book &rhs) const
{
    return !(*this == rhs);
}

bool Book :: operator > (const Book &rhs) const
{
    return (this->year > rhs.year);
}

bool Book :: operator < (const Book &rhs) const
{
    return !(this->year < rhs.year);
}