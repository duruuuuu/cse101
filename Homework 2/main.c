/*
   CSE101 ASSIGNMENT 2
   27 November 2022
   Name: SELIN DURU DERINDAG
   Student No. 200104004801
   Demo Youtube Link: https://youtu.be/9c_n0rkpefY

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <getopt.h>

#include "arduino-serial-lib.c"
#include "arduino-serial-lib.h"

/* Function delaration */
void print_menu();

int main()
{
    int myport = serialport_init("/dev/ttyUSB0", 9600);
    print_menu();
    return 0;
}

void print_menu()
{
    int myPort = serialport_init("/dev/ttyUSB0", 9600);
    int go = 1;
    char input;

    printf("##  WELCOME TO GTU ARDUINO LAB             ##\n");
    printf("##  STUDENT NAME: SELN DURU DERINDAG       ##\n");

    while (go)
    {

        printf("##  PLEASE SELECT FROM THE FOLLOWING MENU: ##\n");
        printf("(1) TURN ON LED ON ARDUINO \n");
        printf("(2) TURN OFF LED ON ARDUINO\n");
        printf("(3) FLASH ARDUINO LED 3 TIMES\n");
        printf("(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n");
        printf("(5) BUTTON PRESS COUNTER\n");
        printf("(0) EXIT\n");
        scanf(" %c", &input);

        while (getchar() != '\n')
            ;

        switch (input)
        {
        case '1':;
            const char *choose1 = "1";
            serialport_write(myport, choose1);

            break;

        case '2':;
            const char *chose2 = "2";
            serialport_write(myport, chose2);

            break;

        case '3':
        {
            const char *choose3 = "3";
            serialport_write(myport, choose3);

            break;
        }
        case '4':;

            char num[1];
            char arr[1024];
            const char *choose4 = "4";
            serialport_write(myport, choose4);
            printf("\t\tPlease, enter a integer:\n");
            scanf("%c", &num[0]);

            serialport_write(myport, num);
            serialport_read_until(myport, arr, '*', 1024, 2000);
            printf("\n");
            fflush(stdin);

            break;

        case '5':
        {
            fflush(stdin);
            char arr2[1024];
            int a = 0;
            const char *choose5 = "5";
            const char *end = "2";
            serialport_write(myport, choose5);

            printf("when you want to stop pressing press 1 ");
            while (a == 0)
            {
                scanf("%d", &a);
                serialport_read_until(myport, arr2, '*', 1024, 2000);
                printf("\n");
            }
            serialport_write(myport, "2");
        }

        break;

        case '0':
        {
            printf("\n\n \t\t Exiting... \n");
            const char *choose0 = "0";
            serialport_write(myport, choose0);
            serialport_close(myport);
            go = 0;
            break;
        }
        default:
            printf("\nPlease enter a number between 1 and 7 \n");

            break;
        }
    }
}
