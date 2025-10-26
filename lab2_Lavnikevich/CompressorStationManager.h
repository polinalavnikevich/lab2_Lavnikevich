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
};

#endif
