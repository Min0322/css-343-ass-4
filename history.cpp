#include "history.h"

// --------------------------------------------------------------------------------------
// input Constructor
// initializes customer for history transaction
// --------------------------------------------------------------------------------------
History::History(int id)
{
    this->id = id;
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
History::~History()
{
    
}

// --------------------------------------------------------------------------------------
// returns true if history was perfomred successfully
// --------------------------------------------------------------------------------------
bool History::action(BookInventory& books, PatronInventory& patrons)
{
    // check if cusomer exists
    if (!patrons.patronCheck(id))
    {
        cout << "ERROR: History Transaction Failed -- "
        << "Patron " << id << " does not exist" << endl;
        return false;
    }
    
    Patron* patron1 = patrons.getPatron(id);     // display customer's history
    patron1 -> displayHistory();
    return true;
}