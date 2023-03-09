#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "patron.h"

using namespace std;

Patron :: Patron() 
{
    firstName = "";
    lastName = "";
    id = 0;
}

Patron :: Patron(string firstName, string lastName, int id)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
}

Patron :: ~Patron() {}

string Patron :: getFirstName() const
{
    return firstName;
}

string Patron :: getLastName() const
{
    return lastName;
}

int Patron :: getId() const
{
    return id;
}

void Patron :: setFirstName(string fName)
{
    firstName = fName;
}

void Patron :: setLastName(string lName)
{
    lastName = lName;
}

void Patron :: setId(int num)
{
    id = num;
}

void Patron :: setHistory(vector<string> h)
{
    history.clear();
    for(int i = 0; i < h.size(); i++)
    {
        history.push_back(h[i]);
    }
}

void Patron :: addHistory(string s)
{
    history.push_back(s);
}

void Patron :: displayHistory()
{
    for (int i = 0; i < history.size(); i++)
    {
        cout << history[i] << endl;
    }
}