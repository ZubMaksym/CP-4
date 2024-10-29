
#ifndef CP_4_FUNCTIONS_H
#define CP_4_FUNCTIONS_H

#endif //CP_4_FUNCTIONS_H

#ifndef CP_3_FUNCTIONS_H
#define CP_3_FUNCTIONS_H
#endif //CP_3_FUNCTIONS_H
#include <math.h>

double calculate_taylor_sin(int n, double array_x[n], double array_sin_t[n], double epsilon, double array_sin_x_minus_sin_t[n], double array_sin_x[n]){
    for (int i = 0; i < n; i++) {
        double x = array_x[i];
        double sin_t = x;
        double delta = x;

        int term_num = 1;
        while (fabs(delta) > epsilon) {
            delta *= -x * x / ((term_num + 1) * (term_num + 2));
            sin_t += delta;
            term_num += 2;
        }
        array_sin_t[i] = sin_t;
    }

    for (int i = 0; i < n; i++) {
        array_sin_x_minus_sin_t[i] = array_sin_x[i] - array_sin_t[i];
    }


    printf("\n      ---dx---        ---sin_x---       ---sin_t---       ---sin_x-sin_t---\n");
    for (int i = 0; i < n; i++) {
        printf("    |%10.6lf       |%10.6lf      |%10.6lf      |%12.6e\n",
               array_x[i] * 180.0 / M_PI, array_sin_x[i], array_sin_t[i], array_sin_x_minus_sin_t[i]);
    }

    return 0;
}


double calculate_taylor_cos(int n, double array_x[n], double array_cos_t[n], double epsilon, double array_cos_x_minus_cos_t[n], double array_cos_x[n]) {
    for (int i = 0; i < n; i++) {
        double x = array_x[i];
        double cos_t = 1.0;
        double delta = 1.0;

        int term_num = 1;
        while (fabs(delta) > epsilon) {
            delta *= -x * x / ((2.0 * term_num - 1) * (2.0 * term_num));
            cos_t += delta;
            term_num += 1;
        }

        array_cos_t[i] = cos_t;
    }

    for (int i = 0; i < n; i++) {
        array_cos_x_minus_cos_t[i] = array_cos_x[i] - array_cos_t[i];
    }

    printf("\n      ---dx---        ---cos_x---       ---cos_t---       ---cos_x-cos_t---\n");
    for (int i = 0; i < n; i++) {
        printf("    |%10.6lf      |%10.6lf      |%10.6lf      |%12.6e\n",
               array_x[i] * 180.0 / M_PI, array_cos_x[i], array_cos_t[i], array_cos_x_minus_cos_t[i]);
    }

    return 0;
}

double choose_function(int n, int t,  int sin_or_cos, double x1, double x2, double dx, double validInput, double epsilon){
    printf("Enter what do you want to count:\n1-sin\n2-cos");
    validInput = 0;
    do{
        if (scanf("%u", &sin_or_cos) == 1){
            fflush(stdin);
            if (sin_or_cos == 1){
                double array_x[n];
                double array_sin_x[n];
                double array_sin_t[n];
                double array_sin_x_minus_sin_t[n];
                for (int i = 0; i < n; i++) {
                    array_x[i] = x1 + i * dx;
                }
                if (x1 < x2){
                    for (double i = x1; i <= x2; i += dx) {
                        array_sin_x[t] = sin(i);
                        t++;
                    }
                }else if(x1 > x2) {
                    for (double i = x1; i >= x2; i += dx) {
                        array_sin_x[t] = sin(i);
                        t++;
                    }
                }
                validInput = 1;
                calculate_taylor_sin(n, array_x, array_sin_t, epsilon, array_sin_x_minus_sin_t, array_sin_x);

            }else if(sin_or_cos == 2) {
                double array_x[n];
                double array_cos_x[n];
                double array_cos_t[n];
                double array_cos_x_minus_cos_t[n];
                for (int i = 0; i < n; i++) {
                    array_x[i] = x1 + i * dx;
                }
                if(x1 < x2){
                    for (double i = x1; i <= x2; i += dx) {
                        array_cos_x[t] = cos(i);
                        t++;
                    }
                }else if(x1 > x2){
                    for (double i = x1; i >= x2; i += dx) {
                        array_cos_x[t] = cos(i);
                        t++;
                    }
                }
                validInput = 1;

                calculate_taylor_cos(n, array_x, array_cos_t, epsilon, array_cos_x_minus_cos_t, array_cos_x);
            }else{
                fflush(stdin);
                printf("Wrong input. You should enter only numbers! Try again\n1-sin\n2-cos");
            }
        }else{
            fflush(stdin);
        }

    } while (validInput == 0);

    return 0;
}