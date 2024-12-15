#ifndef RSSWATCH_INCLUDE_COMMON_
#define RSSWATCH_INCLUDE_COMMON_

#include <string>

namespace common {
// return: 19700101 00:00:00
std::string getCurrentDateTime();

// return: 19700101
std::string getCurrentDate();

// return: 00:00:00
std::string getCurrentTime();

std::string getCurrentProcessName();

void stringTrim(std::string&);

void stringToLower(std::string&);

void stringToUpper(std::string&);
}  // namespace common

#endif  // RSSWATCH_INCLUDE_COMMON_
