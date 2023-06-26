#include <utils/time.h>
#include <map>

namespace utils {
    static std::map<std::string, time_t> playerLastTickTimes; // 每个玩家的时间戳
    static const time_t debounceDelay(100); // 防抖延迟，设为100毫秒

    time_t getTimeStamp()
    {
        std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
        auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
        std::time_t timestamp = tmp.count();
        return timestamp;
    }

    bool debounceCheck(std::string palyerName) {
        auto lastTickTime = playerLastTickTimes.count(palyerName) ? playerLastTickTimes[palyerName] : 0;
        auto now = utils::getTimeStamp();
        auto elapsed = now - lastTickTime;
        if (elapsed < debounceDelay) {
            // 如果距离上一次触发的时间小于防抖延迟，那么就不执行函数
            return false;
        }
        return true;
    }

    void debounceUpdateTime(std::string palyerName) {
        // 更新当前玩家的时间戳
        playerLastTickTimes[palyerName] = utils::getTimeStamp();
        playerLastTickTimes.insert(std::map<std::string, time_t> ::value_type(palyerName, utils::getTimeStamp()));
    }
}