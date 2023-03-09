//----------------------------------------------------------------------------
// This header file defines the Action object
//----------------------------------------------------------------------------
#ifndef ACTION_H
#define ACTION_H
#include "patronInventory.h"
#include "book.h"
#include "bookInventory.h"


using namespace std;

class Action {
public:
    Action();
    virtual ~Action();
    virtual bool perform(bookInventory& book, patronInventory& patron);

private:
    char actionType;
};
#endif