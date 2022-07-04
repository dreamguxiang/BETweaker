#if 0
#include "../Global.h"
#include <MC/BinaryStream.hpp>
#include <MC/MinecraftPackets.hpp>
namespace Module {

    std::unordered_map<string, string> elist;
    void readElistJsonData() {
        std::ifstream file(".\\plugins\\BETweaker\\EmoteData.json");
        if (!file.is_open()) {
            std::cout << "Can't open file " << ".\\plugins\\BETweaker\\EmoteData.json" << std::endl;
            return;
        }
        nlohmann::json json;
        file >> json;
        file.close();
        json.get_to(elist);
    }
    bool findEmote(string name) {
        for (auto& i : elist) {
            if (name.find(i.first) != name.npos) {
                return true;
            }
        }
        return false;
    }

    void PlayEmote(Player* a1, string name) {
        for (auto& i : elist) {
            if (name.find(i.first) != name.npos) {
                BinaryStream wp;
                wp.writeUnsignedVarInt64(a1->getRuntimeID());
                wp.writeString(i.second);
                wp.writeUnsignedChar(0);
                auto pkt = MinecraftPackets::createPacket(MinecraftPacketIds::Emote);
                pkt->read(wp);
                Level::sendPacketForAllPlayer(*pkt);
            }
        }
    }
}
#endif