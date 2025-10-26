#include "PipeManager.h"
#include "utils.h"
#include <iostream>

void PipeManager::addPipe() {
    Pipe pipe;
    std::cin >> pipe;

    pipes[nextId] = pipe;
    std::cout << "Труба добавлена с ID: " << nextId << std::endl;
    log("Добавлена труба с ID: " + std::to_string(nextId));
    nextId++;
}

void PipeManager::displayAllPipes() const {
    if (pipes.empty()) {
        std::cout << "Трубы не добавлены.\n";
        return;
    }

    std::cout << "Список всех труб:\n";
    for (const auto& pair : pipes) {
        std::cout << "ID " << pair.first << ": " << pair.second << std::endl;
    }
    log("Показаны все трубы");
}

void PipeManager::editPipe() {
    if (pipes.empty()) {
        std::cout << "Трубы не добавлены.\n";
        return;
    }

    int id = readPositive<int>("Введите ID трубы: ", "Неверный ID");
    auto it = pipes.find(id);

    if (it != pipes.end()) {
        it->second.toggleRepair();
        std::cout << "Статус трубы изменен.\n";
    }
    else {
        std::cout << "Труба с ID " << id << " не найдена.\n";
    }
}
std::vector<int> PipeManager::searchByName(const std::string& name) const {
    std::vector<int> foundIds;
    for (const auto& pair : pipes) {
        if (pair.second.getName().find(name) != std::string::npos) {
            foundIds.push_back(pair.first);
        }
    }
    log("Поиск труб по имени '" + name + "': найдено " + std::to_string(foundIds.size()));
    return foundIds;
}

std::vector<int> PipeManager::searchByRepairStatus(bool inRepair) const {
    std::vector<int> foundIds;
    for (const auto& pair : pipes) {
        if (pair.second.getUnderRepair() == inRepair) {
            foundIds.push_back(pair.first);
        }
    }
    log("Поиск труб по статусу ремонта: найдено " + std::to_string(foundIds.size()));
    return foundIds;
}