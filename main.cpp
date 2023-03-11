//----------------------------------------------------------------------------
// This cpp file defines the driver main
//----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "library.h"
using namespace std;

int main()
{
    ifstream patronFile("data4patrons.txt");
    ifstream bookFile("data4books.txt");
    ifstream actionFile("data4commands.txt");
    
    if (!patronFile)                // repeat for movieFile and transactionFile
        cout << "Customer file cannot be oppened" << endl;
    if (!bookFile)                   // repeat for movieFile and transactionFile
        cout << "Movie file cannot be oppened" << endl;
    if (!actionFile)             // repeat for movieFile and transactionFile
        cout << "Transaction file cannot be oppened" << endl;
    
    Library library;                                   //create a store
    library.readPatronFile(patronFile);          //create customer profiles from file
    library.readBookFile(bookFile);                //create movie inventory from file
    library.readActionFile(actionFile);    //process transactions from file
    
    return 0;
}