#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>  // for sleep function

// Function prototypes
void startTrain();
void stopTrain();
void stopTrain1();
void startTrain1();
void openDoors();
void closeDoors();
void emergencyStop();
void controlNormalSection(bool light, bool fan);
void controlVIPSection(bool ac, bool light);
void ticketChecker();
bool checkSafety();
void setSpeed(int speed);
void autopilotSystem();
void decelerateTrain();
void announce(const char* message);
void emergencyCommunication();
void maintenanceAlerts();
void energyConsumptionMonitoring();

int main() {
    autopilotSystem();
    return 0;
}

void startTrain() {
    printf("Train started from Dhaka station.\n");
}
void stopTrain() {
    printf("Train stopped at Jamtoil station.\n");
}
void startTrain1() {
    printf("Train started from Jamtoil station.\n");
}

void stopTrain1() {
    printf("Train stopped at Rajshahi station.\n");
}

void openDoors() {
    printf("Doors opened.\n");
}

void closeDoors() {
    printf("Doors closed.\n");
}

void emergencyStop() {
    printf("Emergency stop activated!\n");
    stopTrain();
}

void controlNormalSection(bool light, bool fan) {
    printf("Normal section - Light: %s, Fan: %s\n", light ? "ON" : "OFF", fan ? "ON" : "OFF");
}

void controlVIPSection(bool ac, bool light) {
    printf("VIP section - AC: %s, Light: %s\n", ac ? "ON" : "OFF", light ? "ON" : "OFF");
}

void ticketChecker() {
    printf("Ticket checker robot is checking tickets...\n");
}

bool checkSafety() {
    // Dummy safety check: always return true in this example
    return true;
}

void setSpeed(int speed) {
    printf("Train speed set to %d km/h\n", speed);
}

void decelerateTrain() {
    setSpeed(180);
    sleep(1);
    setSpeed(140);
    sleep(1); // Simulate real-time delay
    setSpeed(100);
    sleep(1); // Simulate real-time delay
    setSpeed(50);
    sleep(1); // Simulate real-time delay
    setSpeed(10);
    sleep(1); // Simulate real-time delay
    setSpeed(0);
    sleep(1); // Simulate real-time delay
    stopTrain();
}

void announce(const char* message) {
    printf("Automated Announcement: %s\n", message);
}

void emergencyCommunication() {
    printf("Emergency communication system activated.\n");
    // Simulate communication with emergency services or passengers
}

void maintenanceAlerts() {
    printf("Maintenance alerts: Regular maintenance check required.\n");
}

void energyConsumptionMonitoring() {
    // Simulate energy consumption monitoring
    printf("Energy consumption monitoring: Energy consumption within normal range.\n");
}

void autopilotSystem() {
    startTrain();

    // Simulate normal operations
    controlNormalSection(true, true);
    controlVIPSection(true, true);
    ticketChecker();

    // Accelerate the train
    setSpeed(0);
    sleep(1);

    setSpeed(10);
    sleep(1);

    setSpeed(50);
    sleep(1);

    setSpeed(100);
    sleep(1);

    setSpeed(140);
    sleep(1);

    setSpeed(180);
    sleep(1);

    // Main control loop
    for (int i = 0; i < 4; i++) {
        if (!checkSafety()) {
            emergencyStop();
            return;
        }

        // Perform additional features
        announce("Next station: Jamtoil. Break for 10 minutes.");
        emergencyCommunication();
        maintenanceAlerts();
        energyConsumptionMonitoring();

        // Simulate passenger counting
        printf("Passenger Count: %d\n", (i + 1) * 150);

        sleep(1);
    }

    // Decelerate and stop at a station
    decelerateTrain();
    openDoors();
    announce("Dear passengers we are currently at Jamtoil station.\nThe train will take a 10-minutes break here.");
    sleep(5); // Doors open for 10 minutes
    closeDoors();

    // Resuming journey
    startTrain1();
    announce("We are now departing from Jamtoil station towards Rajshahi station.");
    // Accelerate the train again
    setSpeed(0);
    sleep(1);

    setSpeed(10);
    sleep(1);

    setSpeed(50);
    sleep(1);

    setSpeed(100);
    sleep(1);

    setSpeed(140);
    sleep(1);

    setSpeed(180);
    sleep(1);

    for (int i = 0; i < 3; i++) {
        if (!checkSafety()) {
            emergencyStop();
            return;
        }

        announce("Next station: Rajshahi. Final destination.");
        emergencyCommunication();
        maintenanceAlerts();
        energyConsumptionMonitoring();

        // Simulate passenger counting
        printf("Passenger Count: %d\n", (i + 1) * 182);

        sleep(1);
    }

    // Final deceleration and stop
    decelerateTrain();
    announce("Dear passengers We have reached our final destination, Rajshahi station.");
    stopTrain1();
    openDoors();
}

