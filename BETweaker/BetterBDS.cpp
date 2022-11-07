#include "Global.h"
#include <mc/NetworkItemStackDescriptor.hpp>
#include <mc/ServerNetworkHandler.hpp>
THook(void, "?fireEventBlockBroken@MinecraftEventing@@SAXPEAVPlayer@@AEBVBlock@@W4BlockPlacementMethod@1@H@Z",
    void* a1, __int64 a2, unsigned int a3, int a4)
{
    return;
}
