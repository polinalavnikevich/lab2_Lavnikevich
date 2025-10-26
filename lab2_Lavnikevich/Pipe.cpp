#include "Pipe.h"
#include "utils.h"

Pipe::Pipe() : name(""), length(0.0), diameter(0), underRepair(false) {}

std::string Pipe::getName() const { return name; }
double Pipe::getLength() const { return length; }
int Pipe::getDiameter() const { return diameter; }
bool Pipe::getUnderRepair() const { return underRepair; }

void Pipe::toggleRepair() {
    underRepair = !underRepair;
    log("Статус ремонта трубы изменен");
}