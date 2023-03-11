//----------------------------------------------------------------------------
// This header file defines the Display option: view the library
// three categories of book
//----------------------------------------------------------------------------
#ifndef DISPLAY_H
#define DISPLAY_H
#include "book.h"
#include "bookFactory.h"
#include "bookInventory.h"
#include "action.h"
#include "patronInventory.h"
class Display : public Action {
public:
  Display();
  virtual ~Display();
  virtual bool action(BookInventory& books, PatronInventory& patrons);
};
#endif