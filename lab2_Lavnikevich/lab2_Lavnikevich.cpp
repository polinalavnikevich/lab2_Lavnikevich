#include <iostream>
#include "utils.h"
#include "Pipe.h"

int main() {
    Pipe p;
    std::cout << "Введите данные трубы:\n";
    std::cin >> p;
    std::cout << p << std::endl;

    return 0;
}