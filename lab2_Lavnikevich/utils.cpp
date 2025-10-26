#include "utils.h"
#include <fstream>

void log(const std::string& action) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << action << std::endl;
    }
}