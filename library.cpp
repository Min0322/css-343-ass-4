#include "library.h"

Library::Library()
{

}

Library::~Library()
{
    
}

void Library::readPatronFile(ifstream& input)
{
    int id;
    string firstName, lastName;
    string line;
    getline(input, line);

    while (!input.eof())
    {
        // read string as input
        stringstream readLine(line);
        readLine >> id;
        readLine >> lastName;
        readLine >> firstName;

        // add new patron to the patron hash table
        patronTable.addPatron(id, firstName, lastName);

        // read next line
        getline(input, line);
    }
}

// --------------------------------------------------------------------------------------
// reads specified file and creates books from it
// --------------------------------------------------------------------------------------

void Library::readBookFile (ifstream& input)
{
    char bookType = 'W';
    int copies = 0;
    int month = 0;
    int year = 0;
    string title, author;
    
    // read file by line
    string line;
    getline(input, line);
    
    while(!input.eof())
    {
        stringstream readLine(line);
        string temp;
        
        readLine >> temp;                           // temporary string including commas
        bookType = temp[0];                            // get first character as genre
        readLine >> copies;
        readLine >> temp;                           // read over the ','
        title = readStringStream(readLine);         // read title until next ','
        
        // Periodicals
        if (bookType == 'P')
        {
            readLine >> title >> temp;
            title = title + " " + temp;
            readLine >> temp;
            istringstream(temp) >> month;
        }
        readLine >> year;                           // read year
        
        // Create books and add to the bookTree
        Book* newBook = bookFactory.createBook(bookType, author, title, month, year);
        if(!bookTree.addBook(newBook))
            delete newBook;
        
        title = "";
        author = "";
        bookType = 'W';
        copies = 0;
        year = 0;
        month = 0;
    
        getline(input,line);                        // read next line
    }
}

// read transactions from the action file and execute them
void Library::readActionFile(ifstream& input)
{
    char actionType, bookType, format;
    int id = 0, month = 0, year = 0;
    string author, title, temp;
    Book* book = NULL;
    Action* newAction = NULL;

    string line;
    getline(input, line);

    while(!input.eof())
    {
        stringstream readLine(line);
        readLine >> actionType;
        if(actionType == 'H' || actionType == 'B' || actionType == 'R' || actionType == 'D')
        {
            readLine >> id;

            // continue reading for checkout and return transactions
            if(actionType != 'H' && actionType != 'D')
            {
                readLine >> format;
                if (format != 'H') // invalid book format
                    cout << "ERROR: " << format << " Invalid book format. Try Again." << endl;
                else
                {
                    readLine >> bookType;
                    switch (bookType)
                    {
                        case 'C':
                            title = readStringStream(readLine);
                            readLine >> year;
                            break;
                            
                        case 'F':
                            author = readStringStream(readLine);
                            title = readStringStream(readLine);
                            break;
                            
                        case 'P':
                            readLine >> title >> temp;
                            readLine >> month >> year;
                            title = title + " " + temp;
                            break;
                            
                    }
                    book = bookFactory.createBook(bookType, title, author, month, year);
                }
            }
        }

        newAction = actionFactory.create(actionType, id, book);
        performAction(newAction);
        delete newAction;

        title = "";
        author = "";
        bookType = 'W';
        year = 0;
        month = 0;
        newAction = NULL;
        book = NULL;

        getline(input,line);
    }
}

// execute transaction
bool Library::performAction(Action* a) {
    if (a != NULL) {
        return a->execute(bookTree, patronTable);
    }
    return false;
}

// --------------------------------------------------------------------------------------
// read part of the string stream and return group of words that are separated by comma
// --------------------------------------------------------------------------------------
string Library::readStringStream (stringstream& input)
{
    string words, temp;
    input >> words;
    
    // read string stream until last character is a comma
    while (input.peek() != ',')
    {
        input >> temp;
        words = words + " " + temp;
    }
    
    // remove comma from the end of the words
    words = words.substr(0, words.length() - 1);
    
    return words;
}
