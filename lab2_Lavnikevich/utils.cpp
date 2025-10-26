#include "utils.h"

void log(const string& action) {
    ofstream logFile("log.txt", ios::app);
    if (logFile.is_open()) {
        logFile << action << endl;
        logFile.close();
    }
}

int inputIntInRange(const string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);
        log("¬вод: " + input);

        stringstream ss(input);
        if (ss >> value && value >= minValue && value <= maxValue) {
            return value;
        }
        cout << "¬ведите число от " << minValue << " до " << maxValue << ".\n";
    }
}