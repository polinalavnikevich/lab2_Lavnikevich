#include "CompressorStationManager.h"
#include "utils.h"

void CompressorStationManager::addStation() {
    CompressorStation station;
    std::cin >> station;
    
    stations[nextId] = station;
    std::cout << "КС добавлена с ID: " << nextId << std::endl;
    log("Добавлена КС с ID: " + std::to_string(nextId));
    nextId++;
}

void CompressorStationManager::displayAllStations() const {
    if (stations.empty()) {
        std::cout << "КС не добавлены.\n";
        return;
    }
    
    std::cout << "Список всех КС:\n";
    for (const auto& pair : stations) {
        std::cout << "ID " << pair.first << ": " << pair.second << std::endl;
    }
    log("Показаны все КС");
}

void CompressorStationManager::editStation() {
    if (stations.empty()) {
        std::cout << "КС не добавлены.\n";
        return;
    }

    int id = readPositive<int>("Введите ID КС: ", "Неверный ID");
    auto it = stations.find(id);
    
    if (it != stations.end()) {
        std::cout << "1. Увеличить рабочие цехи\n";
        std::cout << "2. Уменьшить рабочие цехи\n";
        
        int choice = inputIntInRange("Выберите действие: ", 1, 2);
        int change = readPositive<int>("Введите количество: ", "Неверное количество");

        if (choice == 1) {
            it->second.changeWorkingShops(change);
        } else if (choice == 2) {
            it->second.changeWorkingShops(-change);
        }

        std::cout << "КС изменена.\n";
    } else {
        std::cout << "КС с ID " << id << " не найдена.\n";
    }
}

std::vector<int> CompressorStationManager::searchByName(const std::string& name) const {
    std::vector<int> foundIds;
    for (const auto& pair : stations) {
        if (pair.second.getName().find(name) != std::string::npos) {
            foundIds.push_back(pair.first);
        }
    }
    log("Поиск КС по имени '" + name + "': найдено " + std::to_string(foundIds.size()));
    return foundIds;
}

std::vector<int> CompressorStationManager::searchByUnusedPercent(double percent, char op) const {
    std::vector<int> foundIds;
    for (const auto& pair : stations) {
        double stationPercent = pair.second.getUnusedPercent();
        bool match = false;

        switch (op) {
        case '=': match = (stationPercent == percent); break;
        case '>': match = (stationPercent > percent); break;
        case '<': match = (stationPercent < percent); break;
        }

        if (match) {
            foundIds.push_back(pair.first);
        }
    }
    log("Поиск КС по проценту " + std::string(1, op) + " " + std::to_string(percent) + ": найдено " + std::to_string(foundIds.size()));
    return foundIds;
}