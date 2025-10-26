#include "Pipe.h"
#include "utils.h"
#include <iostream>

Pipe::Pipe() : name(""), length(0.0), diameter(0), underRepair(false) {}

std::string Pipe::getName() const { return name; }
double Pipe::getLength() const { return length; }
int Pipe::getDiameter() const { return diameter; }
bool Pipe::getUnderRepair() const { return underRepair; }

void Pipe::toggleRepair() {
    underRepair = !underRepair;
    log("Статус ремонта трубы изменен");
}

std::istream& operator>>(std::istream& in, Pipe& pipe) {
    std::cout << "Введите название трубы: ";
    std::getline(in, pipe.name);
    log("Введено название трубы: " + pipe.name);

    pipe.length = readPositive<double>("Введите длину трубы (км): ", "Неверная длина");
    pipe.diameter = readPositive<int>("Введите диаметр трубы (мм): ", "Неверный диаметр");

    pipe.underRepair = false;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pipe& pipe) {
    out << "Труба: " << pipe.name
        << ", Длина: " << pipe.length << " км"
        << ", Диаметр: " << pipe.diameter << " мм"
        << ", В ремонте: " << (pipe.underRepair ? "Да" : "Нет");
    return out;
}

void Pipe::load(const std::string& data) {
    std::stringstream ss(data);
    std::string token;

    std::getline(ss, name, ';');
    std::getline(ss, token, ';');
    length = std::stod(token);
    std::getline(ss, token, ';');
    diameter = std::stoi(token);
    std::getline(ss, token, ';');
    underRepair = (token == "1");
}

std::string Pipe::save() const {
    return name + ";" + std::to_string(length) + ";" + std::to_string(diameter) + ";" + (underRepair ? "1" : "0");
}