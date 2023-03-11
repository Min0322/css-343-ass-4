#include "book.h"
#include "stdio.h"


Book :: Book()
{
    bookType = 'Z';
    format = 'H';
    author = "";
    title = "";
    month = 0;
    year = 0;
    copies = 0;
}

Book :: Book(char bookType, char format, string author, string title, int year, int copies)
{
    this->bookType = bookType;
    this->format = 'H';
    this->author = author;
    this->title = title;
    this->year = year;
    this->copies = 5;
}

Book :: Book(char bookType, char format, string title, int month, int year, int copies)
{
    this->bookType = bookType;
    this->format = 'H';
    this->title = title;
    this->month = month;
    this->year = year;
    this->copies = 5;
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
  // set the book author
string Book :: getAuthor() const
{
    return author;
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

// Book& Book :: operator = (Book& rhs)
// {

//     if(this != &rhs)
//     {
//     this->bookType = bookType;
//     this->author = author;
//     this->title = title;
//     this->month = month;
//     this->year = year;
//     }
//     return *this;
// }

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

bool Book :: addToCopies(int add) // add to stock
{
    copies += add;
    return true;
}                              
bool Book :: subtractFromCopies(int sub) // subtract from stock
{
    if (copies >= sub && copies > 0)
    {
        copies -= sub;
        return true;
    }
    else
        return false;
}               
     

void Book :: display() const    
{
    if(year != 0 && (bookType == 'C' || bookType == 'F'))
    {
        cout << getBookType() << setw(1) << getAuthor() << ", "
    << setw(1) << getTitle() << ", " << getYear() << endl;
    }
    else if(year != 0 && month != 0 && bookType == 'P')
    {
        cout << getBookType() << setw(1) << getTitle() << ", " <<
        getMonth() << setw(1) << getYear() << endl;
    }else if(bookType == 'Z')
    {
        cout << getBookType() << setw(1) << getTitle() << endl;
    }
    
}          

void Book::setCounted(bool checked)
{
    counted = checked;
}
