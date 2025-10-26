#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <sstream>

void log(const std::string& action);

template <typename T>
T readPositive(const std::string& prompt, const std::string& errorMessage) {
    T value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        log("¬вод: " + input);

        std::stringstream ss(input);
        if (ss >> value && value > 0) {
            return value;
        }
        std::cout << errorMessage << std::endl;
    }
}

#endif