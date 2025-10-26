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

    std::string getName() const;
    double getLength() const;
    int getDiameter() const;
    bool getUnderRepair() const;

    void toggleRepair();

    friend std::istream& operator>>(std::istream& in, Pipe& pipe);
    friend std::ostream& operator<<(std::ostream& out, const Pipe& pipe);
    void load(const std::string& data);
    std::string save() const;
};

#endif