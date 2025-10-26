#ifndef PIPEMANAGER_H
#define PIPEMANAGER_H

#include <map>
#include <vector>
#include "Pipe.h"

class PipeManager {
private:
    std::map<int, Pipe> pipes;
    int nextId = 1;

public:
    void addPipe();
    void displayAllPipes() const;
    void editPipe();
    std::vector<int> searchByName(const std::string& name) const;
    std::vector<int> searchByRepairStatus(bool inRepair) const;
};

#endif