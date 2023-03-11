//----------------------------------------------------------------------------
// This header file defines the Return action
// subclass of Action
//----------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H
#include "action.h"
#include "book.h"
#include "bookInventory.h"
#include "patronInventory.h"

class Return : public Action 
{
public:
  // action constructor for Return
  Return(int id, Book* book);
  virtual ~Return();
  virtual bool action(BookInventory& books, PatronInventory& patrons);

private:
  Book* book;
  int id;
};
#endif
