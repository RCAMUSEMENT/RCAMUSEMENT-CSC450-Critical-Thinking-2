/**
 * Student Name: Ryley Carlson
 * Course/Module: CSC450 Programming III - Module 2 CT Assignment
 * Program Context: Apollo 11 Historical Log Concatenation Interface
 * File Name: apollo11_string_app.cpp
 */

#include <iostream>
#include <string>

int main() {
    // Declaring strings using standard library managed classes
    std::string commandModuleString;
    std::string lunarModuleString;
    std::string flightTelemetryResult;

    std::cout << "==================================================\n";
    std::cout << "   NASA APOLLO 11 TELEMETRY CONCATENATION SYSTEM  \n";
    std::cout << "==================================================\n\n";

    // Loop exactly 3 times to grab entries across different milestones
    for (int missionPhase = 1; missionPhase <= 3; ++missionPhase) {

        // Clean checks to print labels for each phase
        if (missionPhase == 1) {
            std::cout << "--- PHASE 1: LAUNCH & TRANSLUNAR INJECTION (Short text) ---\n";
        } else if (missionPhase == 2) {
            std::cout << "--- PHASE 2: LUNAR DESCENT & SURFACE CODES (Medium text) ---\n";
        } else if (missionPhase == 3) {
            std::cout << "--- PHASE 3: TRANSEARTH RETURN & SPLASHDOWN (Long text) ---\n";
        }

        // Grab the uplink entry safely including any spaces
        std::cout << "Enter Mission Control uplink text: ";
        std::getline(std::cin, commandModuleString);

        // Grab the matching spacecraft downlink entry
        std::cout << "Enter Spacecraft downlink text:    ";
        std::getline(std::cin, lunarModuleString);

        // Concatenate using safe standard library operators
        flightTelemetryResult = commandModuleString + lunarModuleString;

        // Print results to the console window
        std::cout << "\nConsolidated Mission Log: [ " << flightTelemetryResult << " ]\n";
        std::cout << "Total Phase Telemetry Byte Count: " << flightTelemetryResult.length() << " bytes\n";
        std::cout << "--------------------------------------------------\n\n";
    }

    std::cout << "Apollo 11 data matrix verification complete. Press Enter to exit...";
    std::cin.get(); // Pause the screen before exiting

    return 0;
}