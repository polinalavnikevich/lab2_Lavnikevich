#include <iostream>
#include <string>
#include "PipeManager.h"
#include "CompressorStationManager.h"
#include "utils.h"

void displayMainMenu() {
    std::cout << "\n=== ГЛАВНОЕ МЕНЮ ===\n";
    std::cout << "1. Управление трубами\n";
    std::cout << "2. Управление КС\n";
    std::cout << "0. Выход\n";
}

void displayPipeMenu() {
    std::cout << "\n=== УПРАВЛЕНИЕ ТРУБАМИ ===\n";
    std::cout << "1. Добавить трубу\n";
    std::cout << "2. Показать все трубы\n";
    std::cout << "3. Редактировать трубу\n";
    std::cout << "4. Поиск труб\n";
    std::cout << "0. Назад\n";
}

void displayStationMenu() {
    std::cout << "\n=== УПРАВЛЕНИЕ КС ===\n";
    std::cout << "1. Добавить КС\n";
    std::cout << "2. Показать все КС\n";
    std::cout << "3. Редактировать КС\n";
    std::cout << "4. Поиск КС\n";
    std::cout << "0. Назад\n";
}
void displaySearchPipeMenu() {
    std::cout << "\n=== ПОИСК ТРУБ ===\n";
    std::cout << "1. По названию\n";
    std::cout << "2. По статусу ремонта\n";
    std::cout << "0. Назад\n";
}

void displaySearchStationMenu() {
    std::cout << "\n=== ПОИСК КС ===\n";
    std::cout << "1. По названию\n";
    std::cout << "2. По проценту незадействованных цехов\n";
    std::cout << "0. Назад\n";
}

void handlePipeSearch(PipeManager& pipeManager) {
    while (true) {
        displaySearchPipeMenu();
        int choice = inputIntInRange("Выберите действие: ", 0, 2);

        if (choice == 0) return;

        std::vector<int> foundIds;

        if (choice == 1) {
            std::string name;
            std::cout << "Введите название для поиска: ";
            std::getline(std::cin, name);
            foundIds = pipeManager.searchByName(name);
        }
        else if (choice == 2) {
            std::cout << "1. В ремонте\n";
            std::cout << "2. Работает\n";
            int statusChoice = inputIntInRange("Выберите статус: ", 1, 2);
            foundIds = pipeManager.searchByRepairStatus(statusChoice == 1);
        }

        std::cout << "Найдено труб: " << foundIds.size() << std::endl;
    }
}
void handlePipes(PipeManager& pipeManager) {
    while (true) {
        displayPipeMenu();
        int choice = inputIntInRange("Выберите действие: ", 0, 4);

        switch (choice) {
        case 1: pipeManager.addPipe(); break;
        case 2: pipeManager.displayAllPipes(); break;
        case 3: pipeManager.editPipe(); break;
        case 4: handlePipeSearch(pipeManager); break;
        case 0: return;
        }
    }
}
void handleStationSearch(CompressorStationManager& stationManager) {
    while (true) {
        displaySearchStationMenu();
        int choice = inputIntInRange("Выберите действие: ", 0, 2);

        if (choice == 0) return;

        std::vector<int> foundIds;

        if (choice == 1) {
            std::string name;
            std::cout << "Введите название для поиска: ";
            std::getline(std::cin, name);
            foundIds = stationManager.searchByName(name);
        }
        else if (choice == 2) {
            double percent = readPositive<double>("Введите процент: ", "Неверный процент");
            std::cout << "1. Больше (>)\n";
            std::cout << "2. Меньше (<)\n";
            std::cout << "3. Равно (=)\n";

            int opChoice = inputIntInRange("Выберите оператор: ", 1, 3);
            char op = '=';
            if (opChoice == 1) op = '>';
            else if (opChoice == 2) op = '<';

            foundIds = stationManager.searchByUnusedPercent(percent, op);
        }

        std::cout << "Найдено КС: " << foundIds.size() << std::endl;
    }
}

void handleStations(CompressorStationManager& stationManager) {
    while (true) {
        displayStationMenu();
        int choice = inputIntInRange("Выберите действие: ", 0, 4);

        switch (choice) {
        case 1: stationManager.addStation(); break;
        case 2: stationManager.displayAllStations(); break;
        case 3: stationManager.editStation(); break;
        case 4: handleStationSearch(stationManager); break;
        case 0: return;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    PipeManager pipeManager;
    CompressorStationManager stationManager;

    while (true) {
        displayMainMenu();
        int choice = inputIntInRange("Выберите действие: ", 0, 2);

        switch (choice) {
        case 1: handlePipes(pipeManager); break;
        case 2: handleStations(stationManager); break;
        case 0:
            return 0;
        }
    }
}