// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ItemStackRequestData {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMSTACKREQUESTDATA
public:
    class ItemStackRequestData& operator=(class ItemStackRequestData const &) = delete;
    ItemStackRequestData(class ItemStackRequestData const &) = delete;
    ItemStackRequestData() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ITEMSTACKREQUESTDATA
#endif
    MCAPI std::vector<std::unique_ptr<class ItemStackRequestAction>> const & getActions() const;
    MCAPI class TypedClientNetId<struct ItemStackRequestIdTag, int, 0> const & getRequestId() const;
    MCAPI std::vector<std::string> const & getStringsToFilter() const;
    MCAPI void postLoadItems(class BlockPalette &, bool);
    MCAPI class ItemStackRequestAction const * tryFindAction(enum ItemStackRequestActionType) const;
    MCAPI void write(class BinaryStream &) const;
    MCAPI ~ItemStackRequestData();
    MCAPI static std::unique_ptr<class ItemStackRequestData> read(class ReadOnlyBinaryStream &);

};