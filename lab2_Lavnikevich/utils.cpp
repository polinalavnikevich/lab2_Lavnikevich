#include "utils.h"
#include <fstream>

void log(const std::string& action) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << action << std::endl;
        logFile.close();
    }
}
int inputIntInRange(const std::string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        log("¬вод: " + input);

        std::stringstream ss(input);
        if (ss >> value && value >= minValue && value <= maxValue) {
            return value;
        }
        std::cout << "¬ведите число от " << minValue << " до " << maxValue << ".\n";
    }
}