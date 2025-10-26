#include "Pipe.h"
#include "utils.h"

Pipe::Pipe() : name(""), length(0), diameter(0), underRepair(false) {}

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

    std::cout << "Введите длину трубы: ";
    in >> pipe.length;

    std::cout << "Введите диаметр трубы: ";
    in >> pipe.diameter;

    pipe.underRepair = false;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pipe& pipe) {
    out << "Труба: " << pipe.name << ", Длина: " << pipe.length;
    return out;
}