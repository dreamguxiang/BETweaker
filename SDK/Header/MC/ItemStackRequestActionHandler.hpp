// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ItemStackRequestActionHandler {

#define AFTER_EXTRA
// Add Member There
public:
enum RemoveType;
struct RequestSlotIdAssignment {
    RequestSlotIdAssignment() = delete;
    RequestSlotIdAssignment(RequestSlotIdAssignment const&) = delete;
    RequestSlotIdAssignment(RequestSlotIdAssignment const&&) = delete;
};
struct ScreenData {
    ScreenData() = delete;
    ScreenData(ScreenData const&) = delete;
    ScreenData(ScreenData const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMSTACKREQUESTACTIONHANDLER
public:
    class ItemStackRequestActionHandler& operator=(class ItemStackRequestActionHandler const &) = delete;
    ItemStackRequestActionHandler(class ItemStackRequestActionHandler const &) = delete;
    ItemStackRequestActionHandler() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ITEMSTACKREQUESTACTIONHANDLER
#endif
    MCAPI ItemStackRequestActionHandler(class ItemStackNetManagerServer &, class Player &);
    MCAPI void _addResponseSlotInfo(struct ItemStackRequestHandlerSlotInfo const &, class ItemStack const &);
    MCAPI void _cacheLegacySlotIdAssignment(enum ContainerEnumName, unsigned char, class TypedClientNetId<struct ItemStackLegacyRequestIdTag, int, 0> const &, class TypedServerNetId<struct ItemStackNetIdTag, int, 0> const &);
    MCAPI void _cacheSlotIdAssigment(class TypedRuntimeId<struct ContainerRuntimeIdTag, unsigned int, 0> const &, unsigned char, unsigned char, class TypedServerNetId<struct ItemStackNetIdTag, int, 0> const &);
    MCAPI class std::shared_ptr<class SimpleSparseContainer> _getOrInitSparseContainer(enum ContainerEnumName);
    MCAPI enum ItemStackNetResult _handleRemove(class ItemStackRequestActionTransferBase const &, class ItemStack &, enum ItemStackRequestActionHandler::RemoveType);
    MCAPI void _initScreen(class ItemStackNetManagerScreen &);
    MCAPI struct ItemStackRequestHandlerSlotInfo _validateRequestSlot(struct ItemStackRequestSlotInfo const &, bool, bool);
    MCAPI void addFilteredStrings(class TypedClientNetId<struct ItemStackRequestIdTag, int, 0>, std::vector<std::string>);
    MCAPI void beginRequest(class TypedClientNetId<struct ItemStackRequestIdTag, int, 0> const &, class ItemStackNetManagerScreen &);
    MCAPI class std::tuple<enum ItemStackNetResult, std::vector<struct ItemStackResponseContainerInfo>> endRequest(enum ItemStackNetResult);
    MCAPI void endRequestBatch();
    MCAPI std::vector<std::string> const & getFilteredStrings(class TypedClientNetId<struct ItemStackRequestIdTag, int, 0>) const;
    MCAPI class TypedClientNetId<struct ItemStackRequestIdTag, int, 0> const & getRequestId() const;
    MCAPI class ContainerScreenContext const & getScreenContext() const;
    MCAPI enum ItemStackNetResult handleRequestAction(class ItemStackRequestAction const &);
    MCAPI bool hasFilteredStrings(class TypedClientNetId<struct ItemStackRequestIdTag, int, 0>) const;
    MCAPI bool isValidationCraftingImplemented();
    MCAPI void normalTick();
    MCAPI std::vector<class ItemInstance> tryCraft(std::unique_ptr<struct ContainerValidationCraftInputs>);
    MCAPI ~ItemStackRequestActionHandler();

//private:
    MCAPI enum ItemStackNetResult _handleDestroy(class ItemStackRequestActionDestroy const &);
    MCAPI enum ItemStackNetResult _handlePlaceInItemContainer(class ItemStackRequestActionPlaceInItemContainer const &);
    MCAPI enum ItemStackNetResult _handleTakeFromItemContainer(class ItemStackRequestActionTakeFromItemContainer const &);
    MCAPI enum ItemStackNetResult _handleTransfer(class ItemStackRequestActionTransferBase const &, bool, bool, bool);
    MCAPI class std::optional<struct ItemStackRequestActionHandler::RequestSlotIdAssignment> _resolveSlotIdAssignment(struct ItemStackRequestSlotInfo const &, class TypedRuntimeId<struct ContainerRuntimeIdTag, unsigned int, 0> const &);
    MCAPI struct ItemStackRequestActionHandler::ScreenData * _tryGetCurrentScreenData() const;

private:

};