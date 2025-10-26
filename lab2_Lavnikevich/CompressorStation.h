#ifndef COMPRESSORSTATION_H
#define COMPRESSORSTATION_H

#include <iostream>
#include <string>

class CompressorStation {
private:
    std::string name;
    int totalShops;
    int workingShops;
    int efficiency;

public:
    CompressorStation();

    std::string getName() const;
    double getUnusedPercent() const;
    void changeWorkingShops(int change);

    friend std::istream& operator>>(std::istream& in, CompressorStation& cs);
    friend std::ostream& operator<<(std::ostream& out, const CompressorStation& cs);
};

#endif
