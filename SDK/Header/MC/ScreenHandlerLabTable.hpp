// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScreenHandlerLabTable {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCREENHANDLERLABTABLE
public:
    class ScreenHandlerLabTable& operator=(class ScreenHandlerLabTable const &) = delete;
    ScreenHandlerLabTable(class ScreenHandlerLabTable const &) = delete;
    ScreenHandlerLabTable() = delete;
#endif


public:
    /*0*/ virtual ~ScreenHandlerLabTable();
    /*1*/ virtual enum ItemStackNetResult handleAction(class ItemStackRequestAction const &);
    /*2*/ virtual enum ItemStackNetResult endRequest();
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual void postRequest(bool);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SCREENHANDLERLABTABLE
#endif
    MCAPI ScreenHandlerLabTable(class ContainerScreenContext const &, class ItemStackRequestActionHandler &);

//private:
    MCAPI enum ItemStackNetResult _handleLabTableCombine(class ItemStackRequestActionDataless<9> const &);


private:


};