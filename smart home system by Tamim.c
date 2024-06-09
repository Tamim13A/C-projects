   #include <stdio.h>
    #include <stdbool.h>

    // Define device states
    typedef enum {
        OFF,
        ON
    } State;

    // Define devices
    typedef struct {
        State light;
        State fan;
        State ac;
    } Bedroom;

    typedef struct {
        State light;
        State fan;
    } DrawingRoom;

    typedef struct {
        State light;
    } Kitchen;

    typedef struct {
        State light;
    } Washroom;

    typedef struct {
        State roomDoor;
        State mainGate;
        State garageGate;
    } Doors;

    typedef struct {
        State light;
    } Garage;

    typedef struct {
        State light;
        State fan;
    } DiningRoom;

    // Function prototypes
    void controlBedroomLight(Bedroom *bedroom, State lightState);
    void controlBedroomFan(Bedroom *bedroom, State fanState);
    void controlBedroomAC(Bedroom *bedroom, State acState);

    void controlDrawingRoomLight(DrawingRoom *drawingRoom, State lightState);
    void controlDrawingRoomFan(DrawingRoom *drawingRoom, State fanState);

    void controlKitchenLight(Kitchen *kitchen, State lightState);

    void controlWashroomLight(Washroom *washroom, State lightState);

    void controlRoomDoor(Doors *doors, State roomDoorState);
    void controlMainGate(Doors *doors, State mainGateState);
    void controlGarageGate(Doors *doors, State garageGateState);

    void controlGarageLight(Garage *garage, State lightState);

    void controlDiningRoomLight(DiningRoom *diningRoom, State lightState);
    void controlDiningRoomFan(DiningRoom *diningRoom, State fanState);

    int main() {
        // Initialize devices
        Bedroom bedroom = {OFF, OFF, OFF};
        DrawingRoom drawingRoom = {OFF, OFF};
        Kitchen kitchen = {OFF};
        Washroom washroom = {OFF};
        Doors doors = {OFF, OFF, OFF};
        Garage garage = {OFF};
        DiningRoom diningRoom = {OFF};

        // Main loop
        int choice;
        do {
            // Display menu
            printf("[=====Smart Home Management System=====]");
            printf("\n\n\|=====> by Tamim <=====|\n\n");
            printf("1. Bedroom Light Control\n");
            printf("2. Bedroom Fan Control\n");
            printf("3. Bedroom AC Control\n");
            printf("4. Drawing Room Light Control\n");
            printf("5. Drawing Room Fan Control\n");
            printf("6. Kitchen Light Control\n");
            printf("7. Washroom Light Control\n");
            printf("8. Room Door Control\n");
            printf("9. Main GateControl\n");
           printf("10. Garage Gate Control\n");
           printf("11. Garage Light Control\n");
           printf("12. Dining Room Light Control\n");
           printf("13. Dining Room Fan Control\n");
            printf("0. Exit\n");
            printf("\n\tEnter your choice: ");
            scanf("%d", &choice);

            // Perform actions based on user choice
            switch(choice) {
                case 1:
                    controlBedroomLight(&bedroom, bedroom.light == OFF ? ON : OFF);
                    printf("Bedroom light is now %s.\n", bedroom.light == ON ? "on" : "off");
                    break;
                case 2:
                    controlBedroomFan(&bedroom, bedroom.fan == OFF ? ON : OFF);
                    printf("Bedroom fan is now %s.\n", bedroom.fan == ON ? "on" : "off");
                    break;
                case 3:
                    controlBedroomAC(&bedroom, bedroom.ac == OFF ? ON : OFF);
                    printf("Bedroom AC is now %s.\n", bedroom.ac == ON ? "on" : "off");
                    break;
                case 4:
                    controlDrawingRoomLight(&drawingRoom, drawingRoom.light == OFF ? ON : OFF);
                    printf("Drawing room light is now %s.\n", drawingRoom.light == ON ? "on" : "off");
                    break;
                case 5:
                    controlDrawingRoomFan(&drawingRoom, drawingRoom.fan == OFF ? ON : OFF);
                    printf("Drawing room fan is now %s.\n", drawingRoom.fan == ON ? "on" : "off");
                    break;
                case 6:
                    controlKitchenLight(&kitchen, kitchen.light == OFF ? ON : OFF);
                    printf("Kitchen light is now %s.\n", kitchen.light == ON ? "on" : "off");
                    break;
                case 7:
                    controlWashroomLight(&washroom, washroom.light == OFF ? ON : OFF);
                    printf("Washroom light is now %s.\n", washroom.light == ON ? "on" : "off");
                    break;
                case 8:
                    controlRoomDoor(&doors, doors.roomDoor == OFF ? ON : OFF);
                    printf("Room door is now %s.\n", doors.roomDoor == ON ? "closed" : "open");
                    break;
                case 9:
                       controlMainGate(&doors, doors.mainGate == OFF ? ON : OFF);
                 printf("Main gate is now %s.\n", doors.mainGate == ON ? "closed" : "open");
                    break;
                case 10:
                    controlGarageGate(&doors, doors.garageGate == OFF ? ON : OFF);
                    printf("Garage gate is now %s.\n", doors.garageGate == ON ? "closed" : "open");
                    break;
                case 11:
             controlGarageLight(&garage, garage.light == OFF ? ON : OFF);
                    printf("Garage light is now %s.\n", garage.light == ON ? "on" : "off");               break;
                case 12:
                    controlDiningRoomLight(&diningRoom, diningRoom.light == OFF ? ON : OFF);
                    printf("Dining room light is now %s.\n", diningRoom.light == ON ? "on" : "off");
                    break;
                    case 13:
        controlDiningRoomFan(&diningRoom, diningRoom.fan == OFF ? ON : OFF);
        printf("Dining room fan is now %s.\n", diningRoom.fan == ON ? "on" : "off");
        break;
                case 0:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while(choice != 0);

        return 0;
    }

    // Implement control functions
    void controlBedroomLight(Bedroom *bedroom, State lightState) {
        bedroom->light = lightState;
    }

    void controlBedroomFan(Bedroom *bedroom, State fanState) {
        bedroom->fan = fanState;
    }

    void controlBedroomAC(Bedroom *bedroom, State acState) {
        bedroom->ac = acState;
    }

    void controlDrawingRoomLight(DrawingRoom *drawingRoom, State lightState) {
        drawingRoom->light = lightState;
    }

    void controlDrawingRoomFan(DrawingRoom *drawingRoom, State fanState) {
        drawingRoom->fan = fanState;
    }

    void controlKitchenLight(Kitchen *kitchen, State lightState) {
        kitchen->light = lightState;
    }

    void controlWashroomLight(Washroom *washroom, State lightState) {
        washroom->light = lightState;
    }

    void controlRoomDoor(Doors *doors, State roomDoorState) {
        doors->roomDoor = roomDoorState;
    }

    void controlMainGate(Doors *doors, State mainGateState) {
        doors->mainGate = mainGateState;
    }

    void controlGarageGate(Doors *doors, State garageGateState) {
        doors->garageGate = garageGateState;
    }

    void controlGarageLight(Garage *garage, State lightState) {
        garage->light = lightState;
    }

    void controlDiningRoomLight(DiningRoom *diningRoom, State lightState) {
        diningRoom->light = lightState;
    }
    void controlDiningRoomFan(DiningRoom *diningRoom, State fanState) {
        diningRoom->fan = fanState;
    }











































