#include <stdio.h>
#include <stdbool.h>

// Constants for acceptable ranges
const float TEMPERATURE_MIN = 0;
const float TEMPERATURE_MAX = 45;
const float SOC_MIN = 20;
const float SOC_MAX = 80;
const float CHARGE_RATE_MAX = 0.8;

// Function declarations
bool isOutOfRange(float value, float min, float max);
void printOutOfRangeError(const char *parameter, bool isHigh);

// Check if value is out of range
bool isOutOfRange(float value, float min, float max) {
    return (value < min || value > max);
}

// Print out of range error message
void printOutOfRangeError(const char *parameter, bool isHigh) {
    printf("%s %s out of range!\n", parameter, isHigh ? "high" : "low");
}

// Main function to check battery status
bool batteryIsOk(float temperature, float soc, float chargeRate) {
    if (isOutOfRange(temperature, TEMPERATURE_MIN, TEMPERATURE_MAX)) {
        printOutOfRangeError("Temperature", temperature > TEMPERATURE_MAX);
        return false;
    }
    
    if (isOutOfRange(soc, SOC_MIN, SOC_MAX)) {
        printOutOfRangeError("State of Charge", soc > SOC_MAX);
        return false;
    }
    
    if (chargeRate > CHARGE_RATE_MAX) {
        printOutOfRangeError("Charge Rate", true);
        return false;
    }

    return true;
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

