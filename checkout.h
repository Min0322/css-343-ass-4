//----------------------------------------------------------------------------
// This header file defines the Checkout action
// subclass of Action
//----------------------------------------------------------------------------
#ifndef CHECKOUT_H
#define CHECKOUT_H
#include "action.h"
#include "book.h"
#include "bookFactory.h"
#include "bookInventory.h"
#include "patronInventory.h"

using namespace std;

class CheckOut : public Action 
{
public:
  // action constructor for Checkout
  CheckOut(int id, Book* book);
  virtual ~CheckOut();
  virtual bool action(BookInventory& books, PatronInventory& patrons);

private:
  Book* book;
  int id;
};
#endif