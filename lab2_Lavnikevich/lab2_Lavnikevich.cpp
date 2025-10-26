#include <iostream>
#include "utils.h"
#include "Pipe.h"

int main() {
    Pipe p;
    std::cout << "Труба создана: " << p.getName() << std::endl;
    p.toggleRepair();
    std::cout << "В ремонте: " << p.getUnderRepair() << std::endl;
    return 0;
}