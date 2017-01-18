#ifndef TESTAPPAPP_H
#define TESTAPPAPP_H

#include "MooseApp.h"

class TestappApp;

template<>
InputParameters validParams<TestappApp>();

class TestappApp : public MooseApp
{
public:
  TestappApp(InputParameters parameters);
  virtual ~TestappApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* TESTAPPAPP_H */
