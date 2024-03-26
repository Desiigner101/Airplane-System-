#include <stdio.h>
#include "airline.h"
#define BRED "\e[1;31m"
#define BBLU "\e[1;34m"
#define BWHT "\e[1;37m"
#define YEL "\e[0;33m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define HRED "\e[0;91m"
#define REDHB "\e[0;101m"
#define UGRN "\e[4;32m"
#define YEL "\e[0;33m"
#define reset "\e[0m"

void initSeats(int seats[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        seats[i] = 0;
    }
}

void displaySeats(int seats[], int size) {
	int i;
    printf(CYN"First Class Section: "reset);
    for (i = 0; i < size / 2; i++) {
        printf(CYN"[%d] "reset, seats[i]);
    }
    printf(YEL"\nEconomy Class Section: "reset);
    for (i = size / 2; i < size; i++) {
        printf(YEL"[%d] "reset, seats[i]);
    }
    printf("\n");
}

int assignSeat(int seats[], int seatType) {
    if (seatType == 1) {
        return assignFirstClass(seats, 5);
    } else if (seatType == 2) {
        return assignEconomy(seats, 10);
    } else {
        return -1;
    }
}

int assignFirstClass(int seats[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        if (seats[i] == 0) {
            seats[i] = 1;
            return i + 1;
        }
    }
    return -1;
}

int assignEconomy(int seats[], int size) {
	int i;
    for (i = 5; i < size; i++) {
        if (seats[i] == 0) {
            seats[i] = 1;
            return i + 1;
        }
    }
    return -1;
}

void boardPass(int seat) {
    printf("Boarding Pass\n");
    printf(UGRN"Seat #%d\n"reset, seat);
}

void exxit(void) {
    printf(BRED"Next flight leaves in 3 hours...\n"reset);
}

