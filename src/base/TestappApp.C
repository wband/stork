#include "TestappApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<TestappApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

TestappApp::TestappApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  TestappApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  TestappApp::associateSyntax(_syntax, _action_factory);
}

TestappApp::~TestappApp()
{
}

// External entry point for dynamic application loading
extern "C" void TestappApp__registerApps() { TestappApp::registerApps(); }
void
TestappApp::registerApps()
{
  registerApp(TestappApp);
}

// External entry point for dynamic object registration
extern "C" void TestappApp__registerObjects(Factory & factory) { TestappApp::registerObjects(factory); }
void
TestappApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void TestappApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { TestappApp::associateSyntax(syntax, action_factory); }
void
TestappApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
