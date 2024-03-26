#include <stdio.h>
#include "airline.h"
#define BRED "\e[1;31m"
#define BBLU "\e[1;34m"
#define BWHT "\e[1;37m"
#define BGRN "\e[1;32m"
#define YEL "\e[0;33m"
#define REDHB "\e[0;101m"
#define BLUHB "\e[0;104m"
#define HRED "\e[0;91m"
#define WHTHB "\e[0;107m"
#define reset "\e[0m"

int main() {
    int seats[10] = {0};
    int bookedSeats = 0;

    printf(REDHB"\t\t-------------------------------------\n"reset);
    printf("\t\t      *Welcome to MGM Airlines!*\n");
    printf(BLUHB"\t\t-------------------------------------\n\n\n"reset);
    displaySeats(seats, 10);

    while (bookedSeats < 10) {
        printf("\nPlease type 1 for 'first class'\n");
        printf("Please type 2 for 'economy class'\n");

        int seatType;
        printf("Enter Airline Class: ");
        scanf("%d", &seatType);
        

        int seatNum = assignSeat(seats, seatType);

        switch (seatNum) {
            case -1:
                printf(BGRN"\n-------------------------------------\n");
                switch (seatType) {
                    case 1:
                        printf("|         First class is full.      |\n");
                        break;
                    case 2:
                        printf("|        Economy class is full.     |\n");
                        break;
                }
                printf("-------------------------------------\n"reset);

                printf("TRANSFER TO ANOTHER CLASS? (1 for Yes, 2 for No) : ");
                int choice;
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        switch (seatType) {
                            case 1:
                                seatNum = assignSeat(seats, 2);
                                break;
                            case 2:
                                seatNum = assignSeat(seats, 1);
                                break;
                        }

                        if (seatNum != -1) {
                            printf("\n");
                            boardPass(seatNum);
                            bookedSeats++;
                        }
                        
                        break;
                    case 2:
                        exxit();
                        break;
                }
                break;
            default:
                printf("\n");
                bookedSeats++;                boardPass(seatNum);

                break;
        }

        displaySeats(seats, 10);
    }

    if (bookedSeats == 10) {
        printf(BRED"\n-------------------------------------\n");
        printf("| All seats are full.               |\n");
        printf("| Next flight leaves in 3 hours.    |\n");
        printf("| THANK YOU FOR FLYING WITH US!!.   |\n");
        printf("-------------------------------------\n"reset);
    }

    return 0;
}

