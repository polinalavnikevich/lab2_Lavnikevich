#ifndef COMPRESSORSTATIONMANAGER_H
#define COMPRESSORSTATIONMANAGER_H

#include <map>
#include <vector>
#include "CompressorStation.h"

class CompressorStationManager {
private:
    std::map<int, CompressorStation> stations;
    int nextId = 1;

public:
    void addStation();
    void displayAllStations() const;
    void editStation();
    std::vector<int> searchByName(const std::string& name) const;
    std::vector<int> searchByUnusedPercent(double percent, char op) const;
    void deleteStation();
};

#endif
