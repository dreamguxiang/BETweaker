#pragma once

#include <chrono>

namespace utils {
	time_t getTimeStamp();
	bool debounceCheck(std::string palyerName);
	void debounceUpdateTime(std::string palyerName);
}