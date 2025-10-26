#include "CompressorStation.h"
#include "utils.h"

CompressorStation::CompressorStation() : name(""), totalShops(0), workingShops(0), efficiency(0) {}

std::string CompressorStation::getName() const { return name; }

double CompressorStation::getUnusedPercent() const {
    if (totalShops == 0) return 0;
    return ((totalShops - workingShops) / (double)totalShops) * 100;
}

void CompressorStation::changeWorkingShops(int change) {
    workingShops += change;
    if (workingShops < 0) workingShops = 0;
    if (workingShops > totalShops) workingShops = totalShops;
    log("Изменено рабочих цехов на: " + std::to_string(change));
}

std::istream& operator>>(std::istream& in, CompressorStation& cs) {
    std::cout << "Введите название КС: ";
    std::getline(in, cs.name);
    log("Введено название КС: " + cs.name);

    cs.totalShops = readPositive<int>("Введите количество цехов: ", "Неверное количество цехов");
    log("Введено цехов: " + std::to_string(cs.totalShops));

    cs.workingShops = readPositive<int>("Введите количество рабочих цехов: ", "Неверное количество рабочих цехов");
    log("Введено рабочих цехов: " + std::to_string(cs.workingShops));

    cs.efficiency = readPositive<int>("Введите эффективность (%): ", "Неверная эффективность");
    log("Введена эффективность: " + std::to_string(cs.efficiency));

    return in;
}

std::ostream& operator<<(std::ostream& out, const CompressorStation& cs) {
    double unusedPercent = cs.getUnusedPercent();
    out << "КС: " << cs.name
        << ", Цехов: " << cs.workingShops << "/" << cs.totalShops
        << ", Незадействовано: " << unusedPercent << "%"
        << ", Эффективность: " << cs.efficiency << "%";
    return out;
}