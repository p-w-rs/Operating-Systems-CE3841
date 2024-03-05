#ifndef __park_h__
#define __park_h__

#define NUM_CARS 4
#define NUM_DRIVERS 4

#define NUM_SEATS 3
#define NUM_VISITORS (NUM_SEATS * 20)

#define MAX_IN_PARK 20
#define MAX_TICKETS (NUM_CARS * NUM_SEATS)

#define MAX_IN_MUSEUM 5
#define MAX_IN_GIFTSHOP 2

#define ParkDebug(s) printf("\n%s: %s", "Debug", s);

volatile int begin;

typedef struct car
{
    int location;   // location of car in park
    int passengers; // # of passengers in car
} CAR;

typedef struct jpark
{
    int numOutsidePark;       // # outside of park
    int numInPark;            // # in park (P=#)
    int numTicketsAvailable;  // # left to sell (T=#)
    int numRidesTaken;        // # of tour rides taken (S=#)
    int numExitedPark;        // # who have exited the park
    int numInTicketLine;      // # in ticket line
    int numInMuseumLine;      // # in museum line
    int numInMuseum;          // # in museum
    int numInCarLine;         // # in tour car line
    int numInCars;            // # in tour cars
    int numInGiftLine;        // # in gift shop line
    int numInGiftShop;        // # in gift shop
    int drivers[NUM_DRIVERS]; // driver state (-1=T, 0=z, 1=A, 2=B, etc.)
    CAR cars[NUM_CARS];       // cars in park
} JPARK;

void *jurassicTask(void *args);
void *jurassicDisplayTask(void *args);
void *lostVisitorTask(void *args);
int makeMove(int car);
void drawPark(JPARK *park);

#endif
