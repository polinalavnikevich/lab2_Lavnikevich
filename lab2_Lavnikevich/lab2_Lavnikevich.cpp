#include <iostream>
#include "utils.h"
#include "PipeManager.h"

int main() {

    PipeManager pm;

    pm.addPipe();
    pm.addPipe();

    pm.displayAllPipes();

    pm.editPipe();
    pm.displayAllPipes();

    return 0;
}