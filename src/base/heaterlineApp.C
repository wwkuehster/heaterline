#include "heaterlineApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<heaterlineApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

heaterlineApp::heaterlineApp(InputParameters parameters) : MooseApp(parameters)
{
  heaterlineApp::registerAll(_factory, _action_factory, _syntax);
}

heaterlineApp::~heaterlineApp() {}

void
heaterlineApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"heaterlineApp"});
  Registry::registerActionsTo(af, {"heaterlineApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
heaterlineApp::registerApps()
{
  registerApp(heaterlineApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
heaterlineApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  heaterlineApp::registerAll(f, af, s);
}
extern "C" void
heaterlineApp__registerApps()
{
  heaterlineApp::registerApps();
}
