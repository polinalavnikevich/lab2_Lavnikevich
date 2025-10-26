#ifndef PIPE_H
#define PIPE_H

#include <iostream>
#include <string>

class Pipe {
private:
    std::string name;
    double length;
    int diameter;
    bool underRepair;

public:
    Pipe();

    // Базовые геттеры
    std::string getName() const;
    double getLength() const;
    int getDiameter() const;
    bool getUnderRepair() const;

    void toggleRepair();
};

#endif