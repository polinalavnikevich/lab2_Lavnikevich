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