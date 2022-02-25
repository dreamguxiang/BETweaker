#include "../Global.h"
#include <MC/SignBlockActor.hpp>
#include <MC/SignItem.hpp>
#include <MC/BlockActorDataPacket.hpp>
namespace Module {
    bool editSign(Player* pl, BlockInstance bi) {
        if (!pl->isSneaking()) return false;
        auto pos = bi.getPosition();
        auto BlockEntity = (SignBlockActor*)bi.getBlockEntity();
        if (BlockEntity)
        {
            string text = BlockEntity->getNbt()->getString("Text");
            Form::CustomForm form2(getI18n("betweaker.editsign.title"));
            auto out = Helper::split(text, "\n");
            auto num = out.size();
            for (auto i = 1; i <= 4; i++) {
                if (i <= num)
                    form2.addInput("signText" + toStr(i), toStr(i), "", out[i - 1]);
                else
                    form2.addInput("signText" + toStr(i), toStr(i), "", "");
            }
            form2.sendTo(pl, [BlockEntity](Player* player, auto result)
                {
                    if (result.empty())
                        return;
                    string signtext = "";
                    for (auto i = 1; i <= 4; i++) {
                        string str = result["signText" + toStr(i)]->getString();
                        if (i != 4)
                            signtext += str + "\n";
                        else
                            signtext += str;
                    }
                    if (BlockEntity) {
                        BlockEntity->setMessage(signtext, "");
                        BlockEntity->setChanged();
                        auto pkt = BlockEntity->_getUpdatePacket(*player->getBlockSource());
                        Level::sendPacketForAllPlayer(*pkt);
                    }
                });

        }
        return true;
    }
}