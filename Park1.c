
#include <stdio.h>
#include <stdbool.h>

#define MAX_CAPACITY 10

// Structure for parking lot
struct ParkingLot {
    int spots[MAX_CAPACITY];
    int numOfOccupiedSpots;
};

// Function to initialize parking lot
void initializeParkingLot(struct ParkingLot* parkingLot)
{
    for (int i = 0; i < MAX_CAPACITY; i++) {
        parkingLot->spots[i] = 0; // 0 represents an empty spot
    }
    parkingLot->numOfOccupiedSpots = 0;
}

// Function to check if parking lot is full
bool isFull(struct ParkingLot* parkingLot)
{
    return parkingLot->numOfOccupiedSpots == MAX_CAPACITY;
}

// Function to check if parking lot is empty
bool isEmpty(struct ParkingLot* parkingLot)
{
    return parkingLot->numOfOccupiedSpots == 0;
}

// Function to park a vehicle
void parkVehicle(struct ParkingLot* parkingLot, int spotNumber)
{
    if (parkingLot->spots[spotNumber - 1] == 0) {
        parkingLot->spots[spotNumber - 1] = 1; // 1 represents an occupied spot
        parkingLot->numOfOccupiedSpots++;
        printf("Vehicle parked at spot number %d\n", spotNumber);
    }
    else {
        printf("Spot number %d is already occupied\n", spotNumber);
    }
}

// Function to remove a vehicle from parking lot
void removeVehicle(struct ParkingLot* parkingLot, int spotNumber)
{
    if (parkingLot->spots[spotNumber - 1] == 1) {
        parkingLot->spots[spotNumber - 1] = 0;
        parkingLot->numOfOccupiedSpots--;
        printf("Vehicle removed from spot number %d\n", spotNumber);
    }
    else {
        printf("No vehicle found at spot number %d\n", spotNumber);
    }
}

// Function to display the status of parking lot
void displayParkingLotStatus(struct ParkingLot* parkingLot)
{
    printf("Parking Lot Status:\n");
    for (int i = 0; i < MAX_CAPACITY; i++) {
        if (parkingLot->spots[i] == 0) {
            printf("Spot number %d: Empty\n", i + 1);
        }
        else {
            printf("Spot number %d: Occupied\n", i + 1);
        }
    }
}

int main()
{
    struct ParkingLot parkingLot;
    initializeParkingLot(&parkingLot);

    // Park vehicles in some spots
    parkVehicle(&parkingLot, 1);
    parkVehicle(&parkingLot, 3);
    parkVehicle(&parkingLot, 5);

    // Display parking lot status
    displayParkingLotStatus(&parkingLot);

    // Remove a vehicle from parking lot
    removeVehicle(&parkingLot, 3);

    // Display updated parking lot status
    displayParkingLotStatus(&parkingLot);

    return 0;
}
