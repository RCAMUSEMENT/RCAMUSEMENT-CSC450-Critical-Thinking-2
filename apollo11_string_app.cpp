/**
 * Student Name: Ryley Carlson
 * Course/Module: CSC450 Programming III - Module 2 CT Assignment
 * Program Context: Apollo 11 Historical Log Concatenation Interface
 * File Name: apollo11_string_app.cpp
 */

#include <iostream>
#include <string>
#include <cctype>

// This scrub loop strips out non-printable ASCII junk before memory moves happen
void sanitizeString(std::string& inputStr) {
    std::string cleanStr = "";

    for (char character : inputStr) {
        // Keeps only safe printable characters from space up to the tilde
        if (character >= 32 && character <= 126) {
            cleanStr += character;
        }
    }

    // Pass the clean text back into the original variable pipeline
    inputStr = cleanStr;
}

int main() {
    std::string commandModuleString;
    std::string lunarModuleString;
    std::string flightTelemetryResult;

    std::cout << "==================================================\n";
    std::cout << "   NASA APOLLO 11 TELEMETRY CONCATENATION SYSTEM  \n";
    std::cout << "==================================================\n\n";

    // Loop three times so the user can test different input lengths easily
    for (int missionPhase = 1; missionPhase <= 3; ++missionPhase) {

        // Print the right historical phase banner for this step
        if (missionPhase == 1) {
            std::cout << "--- PHASE 1: LAUNCH & TRANSLUNAR INJECTION (Short text) ---\n";
        } else if (missionPhase == 2) {
            std::cout << "--- PHASE 2: LUNAR DESCENT & SURFACE CODES (Medium text) ---\n";
        } else if (missionPhase == 3) {
            std::cout << "--- PHASE 3: TRANSEARTH RETURN & SPLASHDOWN (Long text) ---\n";
        }

        std::cout << "Enter Mission Control uplink text: ";

        // Passing std::ws drops any initial shell arguments passed by the VS Code debugger
        if (missionPhase == 1) {
            std::getline(std::cin >> std::ws, commandModuleString);
        } else {
            std::getline(std::cin, commandModuleString);
        }

        std::cout << "Enter Spacecraft downlink text:    ";
        std::getline(std::cin, lunarModuleString);

        // Run the sanitization checks right here at runtime
        sanitizeString(commandModuleString);
        sanitizeString(lunarModuleString);

        // Combine both lines safely using standard operators
        flightTelemetryResult = commandModuleString + lunarModuleString;

        std::cout << "\nConsolidated Mission Log: [ " << flightTelemetryResult << " ]\n";
        std::cout << "Total Phase Telemetry Byte Count: " << flightTelemetryResult.length() << " bytes\n";
        std::cout << "--------------------------------------------------\n\n";
    }

    std::cout << "Apollo 11 data matrix verification complete. Press Enter to exit...";
    std::cin.get(); // Freeze screen so the terminal window doesn't immediately vanish

    return 0;
}