#include "actionFactory.h"

// --------------------------------------------------------------------------------------
// default constructor
// --------------------------------------------------------------------------------------
ActionFactory::ActionFactory()
{
    
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
ActionFactory::~ActionFactory()
{
    
}

// --------------------------------------------------------------------------------------
// creates new transaction object based on type passed in
// --------------------------------------------------------------------------------------
Action* ActionFactory::create(char type, int customerID, Book*& m)
{
    Action* action = NULL;
    switch(type)
    {
        case 'C':
            action = new CheckOut(customerID, m);
            return action;
            break;
        case 'R':
            action = new Return(customerID, m);
            return action;
            break;
        case 'D':
            action = new Display();
            return action;
            break;
        case 'H': 
            action = new History(customerID);
            return action;
            break;
        default:
            cout << "ERROR: " << type << " Invalid Transaction Type. Try Again." << endl;
            return action;
            break;
    }
}