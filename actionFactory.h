//----------------------------------------------------------------------------
// This header file defines the ActionFactory
// generates different kinds of action
//----------------------------------------------------------------------------
#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H
#include "action.h"
#include "checkout.h"
#include "display.h"
#include "history.h"
#include "book.h"
#include "return.h"
using namespace std;

class ActionFactory {
public:
  ActionFactory();
  ~ActionFactory();
  // generate different kinds of actions
  Action* createAction(char type, int id, Book*& book);
};
#endif