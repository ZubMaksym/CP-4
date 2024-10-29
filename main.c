#include <stdio.h>
#include <math.h>
#include "functions.h"
#define PI 3.14159265358979323846

int main(void) {
    double x1 = 0;
    double x2 = 0;
    double dx = 0;
    double epsilon = 0;
    int n = 0;
    int t = 0;
    int validInput = 0;
    char newInput = 'y';
    int sin_or_cos = 0;

    do {
        printf("This program calculates sin(x) using 'Taylor row'\n");

        printf("Enter x1:");
        do {
            if (scanf("%lf", &x1) == 1 && x1 <= 2000) {
                fflush(stdin);
                validInput = 1;
            } else {
                printf("Wrong input! Try again\n");
                printf("Enter x1:");
                fflush(stdin);
            }
        } while (validInput == 0);

        validInput = 0;

        printf("Enter x2:");
        do {
            if (scanf("%lf", &x2) == 1 && x2 <= 2000) {
                fflush(stdin);
                validInput = 1;
            } else {
                printf("Wrong input! Try again\n");
                printf("Enter x2:");
                fflush(stdin);
            }
        } while (validInput == 0);

        validInput = 0;

        do{
            if (x2 < x1){
                printf("Enter step dx (dx < 0):");
                if (scanf("%lf", &dx) == 1 && dx != 0 && dx < 0) {
                    if ((int)((x1 - x2) / dx) + 1 < 300){
                        for (double i = x1; i > x2; i += dx) {
                            n++;
                        }
                        fflush(stdin);
                        validInput = 1;
                    }else{
                        printf("Too many points or dx is too small. Increase dx or reduce the interval.\n");
                        fflush(stdin);
                    }

                }else{
                    printf("Wrong input! Try again\n");
                    printf("Enter step dx:");
                    fflush(stdin);
                }
            }else if(x2 > x1){
                printf("Enter step dx (dx > 0):");
                if (scanf("%lf", &dx) == 1 && dx != 0 && dx > 0) {
                    if ((int)((x2 - x1) / dx) + 1 < 300 && dx >= 1e-5){
                        for (double i = x1; i < x2; i += dx) {
                            n++;
                        }
                        fflush(stdin);
                        validInput = 1;
                    }else{
                        printf("Too many points or dx is too small. Increase dx or reduce the interval.\n");
                        fflush(stdin);
                    }

                }else{
                    printf("Wrong input! Try again\n");
                    printf("Enter step dx: ");
                    fflush(stdin);
                }
            }else if(x2 == x1) {
                printf("Enter step dx (dx = 0):");
                if (scanf("%lf", &dx) == 1 && dx == 0) {
                    dx = 0;
                    fflush(stdin);
                    validInput = 1;
                    for (double i = x1; i == x2; i += 1) {
                        n++;
                    }
                }else{
                    printf("Wrong input! Try again\n");
                    printf("Enter step dx: ");
                    fflush(stdin);
                }
            }
        }while (validInput == 0);

        validInput = 0;

        printf("Enter epsilon (from 1e-15 to 1e-1):");
        do{
            if (scanf("%lf", &epsilon) == 1 && epsilon >= 1e-15 && epsilon <=1e-1){
                fflush(stdin);
                validInput = 1;
            }else {
                printf("Wrong input! Try again\n");
                printf("Enter epsilon (from 1e-15 to 1e-1):");
                fflush(stdin);
            }
        }while (validInput == 0);

        x1 = x1 * M_PI / 180.0;
        x2 = x2 * M_PI / 180.0;
        dx = dx * M_PI / 180.0;

        choose_function(n, t, sin_or_cos, x1, x2, dx, validInput, epsilon);

        printf("\n\nWant to enter new numbers? (y-yes) or press any other key to exit \n");
        n = 0;
        newInput = getchar();

    }while (newInput == 'y');

    return 0;
}