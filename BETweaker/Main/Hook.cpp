#include "../Global.h"
#include "Module.h"
#include "setting.h"
#include <MC/player.hpp>
std::unordered_set<string> CanDispenserItem{
    "minecraft:bamboo",//bamboo
    "minecraft:sapling",//saplings
    "minecraft:azalea",
    "minecraft:flowering_azalea",
    "minecraft:crimson_fungus",
    "minecraft:warped_fungus",
    "minecraft:brown_mushroom",
    "minecraft:red_mushroom"
};

THook(void, "?updateSleepingPlayerList@ServerLevel@@UEAAXXZ", ServerLevel* self) {
    original(self);
    if(Settings::FastSleeping) 
        Module::FastSleep();
}

THook(void, "?transformOnFall@FarmBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@M@Z", void* __this, void* a2,
    void* a3, void* a4, float a5) {
    if (!Settings::NoFarmDestroy) 
        return original(__this, a2, a3, a4, a5);
    return;
}

#include <MC/DispenserBlock.hpp>
#include <MC/SeedItemComponentLegacy.hpp>
THook(void, "?ejectItem@DispenserBlock@@IEBAXAEAVBlockSource@@AEBVVec3@@EAEBVItemStack@@AEAVContainer@@H@Z", DispenserBlock* a1,
     BlockSource* a2, Vec3* a3, FaceID a4,ItemStack* a5, Container* a6,unsigned int a7) {
    auto pos = a3->toBlockPos();
    if (!Settings::DispenserCrops)
        return original(a1, a2, a3, a4, a5, a6, a7);
    else if (a5->getItem()->isSeed()) {
        if (a2->getBlock(pos.add(0, -1, 0)).getTypeName() == VanillaBlocks::mFarmland->getTypeName() &&
            a2->getBlock(pos).getTypeName() == "minecraft:air") {
            auto out = dAccess<Block*, 8>(dAccess<SeedItemComponentLegacy*, 488>(a5->getItem()));
            Level::setBlock(pos, a2->getDimensionId(), out);
            a5->remove(1);
            return ;
        }
    }
    else if(CanDispenserItem.count(a5->getTypeName()) !=0)
    {
        //Level::broadcastText(std::to_string(a5->getBlock()->mayPlaceOn(*a2, pos.add(0, -1, 0))), TextType::RAW);
        if (a5->getBlock()->mayPlaceOn(*a2, pos.add(0, -1, 0)) &&
            a2->getBlock(pos).getTypeName() == "minecraft:air")
        {
            Block* sapbl = const_cast<Block*>(a5->getBlock());
            Level::setBlock(pos, a2->getDimensionId(), sapbl);
            a5->remove(1);
            return;
        }
    }
    return original(a1, a2, a3, a4, a5, a6, a7);
}




//#include <MC/ReadOnlyBinaryStream.hpp>
//#include <MC/Packet.hpp>
// TClasslessInstanceHook(
//    void,
//    "?_sendInternal@NetworkHandler@@AEAAXAEBVNetworkIdentifier@@AEBVPacket@@AEBV?$basic_string@DU?$char_traits@D@std@@"
//    "V?$allocator@D@2@@std@@@Z",
//    NetworkIdentifier const& id, Packet const& pkt, std::string& data) {
//
//    auto stream  = ReadOnlyBinaryStream(data, 0i64);
//    auto pktid   = stream.getUnsignedVarInt();
//    auto pkthash = do_hash(data.c_str());
//    auto pkttime = _time64(0);
//    //std::cout << "[Network][O][" << pkttime << "]\tLength:" << data.length() << "\tPktID:" << pktid << "[" << pkt.getName() << "]\tHash:" << pkthash << "\n";
//        //__debugbreak();
//    switch ((int)pkt.getId()) {
//    case 21:
//    case 25:
//        case 39:
//        case 40:
//        case 58:
//        case 111:
//        case 121:
//        case 123:
//        case 136:
//        case 172:
//        case 174:
//            return original(this, id, pkt, data);
//        default:
//            break;
//    }
//
//    logger.info("[Network][O][{}]\tLength:{}\tPkt:{}({})", pkttime, data.length(), pkt.getName(), pkt.getId());
//    original(this, id, pkt, data);
//}
//
//#include <MC/NetworkPeer.hpp>
//THook(
//    NetworkPeer::DataStatus,
//    "?receivePacket@Connection@NetworkHandler@@QEAA?AW4DataStatus@NetworkPeer@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV2@AEBV?$shared_ptr@V?$time_point@Usteady_clock@chrono@std@@V?$duration@_JU?$ratio@$00$0DLJKMKAA@@std@@@23@@chrono@std@@@6@@Z",
//    __int64 _this, std::string& data) {
//    auto status = original(_this, data);
//
//    if (status == NetworkPeer::DataStatus::OK) {
//        auto    stream  = ReadOnlyBinaryStream(data, 0i64);
//        auto    pktid   = stream.getUnsignedVarInt();
//        auto    pkthash = do_hash(data.c_str());
//        auto    pkttime = _time64(0);
//        Packet* pkt;
//        SymCall(
//            "?createPacket@MinecraftPackets@@SA?AV?$shared_ptr@VPacket@@@std@@W4MinecraftPacketIds@@@Z",
//            void*, Packet**, int)(&pkt, pktid);
//        switch ((int)pkt->getId()) {
//            case 135:
//            case 144:
//            case 175:
//                return status;
//            default:
//                break;
//        }
//        logger.info("[Network][I][{}]\tLength:{}\tPkt:{}({})", pkttime, data.length(), pkt->getName(), pkt->getId());
//    }
//    return status;
//}