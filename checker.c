#include <stdio.h>
#include <stdbool.h>

// Function declarations
bool isTemperatureValid(float temperature);
bool isSocValid(float soc);
bool isChargeRateValid(float chargeRate);
void printOutOfRangeError(const char *parameter, bool isHigh);

// Check if temperature is within acceptable range
bool isTemperatureValid(float temperature) {
    if (temperature < 0) {
        printOutOfRangeError("Temperature", false);
        return false;
    } else if (temperature > 45) {
        printOutOfRangeError("Temperature", true);
        return false;
    }
    return true;
}

// Check if state of charge (soc) is within acceptable range
bool isSocValid(float soc) {
    if (soc < 20) {
        printOutOfRangeError("State of Charge", false);
        return false;
    } else if (soc > 80) {
        printOutOfRangeError("State of Charge", true);
        return false;
    }
    return true;
}

// Check if charge rate is within acceptable range
bool isChargeRateValid(float chargeRate) {
    if (chargeRate > 0.8) {
        printOutOfRangeError("Charge Rate", true);
        return false;
    }
    return true;
}

// Print out of range error message
void printOutOfRangeError(const char *parameter, bool isHigh) {
    printf("%s %s out of range!\n", parameter, isHigh ? "high" : "low");
}

// Main function to check battery status
bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool isTemperatureOk = isTemperatureValid(temperature);
    bool isSocOk = isSocValid(soc);
    bool isChargeRateOk = isChargeRateValid(chargeRate);

    return isTemperatureOk && isSocOk && isChargeRateOk;
}

int main() {
    // Test cases
    printf("Test Case 1:\n");
    if (batteryIsOk(25, 70, 0.7)) {
        printf("Battery is OK.\n");
    }
    
    printf("\nTest Case 2:\n");
    if (!batteryIsOk(50, 85, 0)) {
        printf("Battery is NOT OK.\n");
    }

    printf("\nTest Case 3:\n");
    if (!batteryIsOk(-5, 50, 0.9)) {
        printf("Battery is NOT OK.\n");
    }

    return 0;
}
