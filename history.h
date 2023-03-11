//----------------------------------------------------------------------------
// This header file defines the History action: view history
// of a patron
// subclass of Action
//----------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H
#include "book.h"
#include "bookFactory.h"
#include "bookInventory.h"
#include "action.h"
#include "patronInventory.h"
class History : public Action {
public:
  History(int id);
  virtual ~History();
  virtual bool action(BookInventory& books, PatronInventory& patrons);

private:
  // patron id
  int id;
};
#endif