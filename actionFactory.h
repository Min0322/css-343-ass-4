//----------------------------------------------------------------------------
// This header file defines the ActionFactory
// generates different kinds of action
//----------------------------------------------------------------------------
#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H
#include "action.h"
class ActionFactory {
public:
  // generate different kinds of actions
  bool createAction(char a, Action *&act, ifstream &infile);
};
#endif