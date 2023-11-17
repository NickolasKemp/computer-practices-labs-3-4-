// TASK 1

#include <stdio.h>
#include <string.h>
#include <math.h>

void clearInputBuffer() {
    while (getchar() != '\n') {
    }
}

int main() {
    double delta = 1;
    double y = 0;
    double ytemp = 1;
    double e;
    char restart;
    char input[7];

    do {
        int valid_input = 0;
        double k = 0, x = 0;

        do {printf("(max введення 5 символів) \n");
            printf("Введіть степінь кореня (k) : ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                if (sscanf(input, "%lf", &k) != 1) {
                    clearInputBuffer();
                    printf("Помилка: введіть правильне значення для k.\n");
                } else if (k == 0){
                    printf("Помилка: k не може = 0.\n");
                    continue;
                }
                    valid_input = 1;

            }
        } while (!valid_input);

        valid_input = 0;

        do {
            printf("Введіть число під коренем (x): ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                if (sscanf(input, "%lf", &x) != 1) {
                    clearInputBuffer();
                    printf("Помилка: введіть правильне значення для x.\n");
                } else if (((int)k % 2 == 0) && (x < 0) ){
                    printf("Помилка: x не може бути менше 0, коли k - парне число.\n");
                    continue;
                } else if (k < 0 && x == 0 ){
                    printf("Помилка: x не може = 0, якщо к < 0\n");
                    continue;
                } else if (k < 0 && x < 0 ){
                    printf("Помилка: x не може бути < 0, якщо к < 0\n");
                    continue;
                }
                else {
                    valid_input = 1;
                }
            }
        } while (!valid_input);

        valid_input = 0;

        do {
            printf("Введіть точність (e): ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                if (sscanf(input, "%lf", &e) != 1 || e >= 1 || e <= 0) {
                    clearInputBuffer();
                    printf("Помилка: введіть правильне значення для e.\n");
                }
                else {
                    valid_input = 1;
                }

            }

        } while (!valid_input);

        do {
            delta = (1.0 / k) * (x / (pow(ytemp, k - 1.0)) - ytemp);
            y = ytemp + delta;
            ytemp = y;
        } while (fabs(delta) > e);

        printf("Y = %.5lf\n", y);

        printf("Бажаєте продовжити (y/n)? ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, " %c", &restart) != 1) {
                clearInputBuffer();
                printf("Помилка: введіть правильне значення для продовження (y/n).\n");
            }
        }

    } while (restart == 'Y' || restart == 'y');
    return 0;
}



//#include <stdio.h>
//#include <math.h>
//
//char buffer[3];
//
//int main() {
//    double delta = 1;
//    double y = 0;
//    double i = 1;
//    double ytemp = 1;
//    double k, x, e;
//    char restart;
//    do {
//    printf("k:");
//    scanf("%lf", &k);
//    fflush(stdin);
//
//    if (k == 0){
//        printf("Помилка: k не може = 0.\n");
//        return 1; // Поверніть неуспішний код виходу
//    }
//
//    printf("x:");
//    scanf("%lf", &x);
//    fflush(stdin);
//
//    // Додайте перевірку на парність k та x < 0
//    if (((int)k % 2 == 0) && (x < 0) ){
//        printf("Помилка: x не може бути менше 0, коли k - парне число.\n");
//        return 1; // Поверніть неуспішний код виходу
//    }
////

//
//    printf("e:");
//    scanf("%lf", &e);
//        if (e> 1 || e < 0 ){
//            printf("Помилка: e знаходиться в межах від 0 до 1\n");
//            return 1; // Поверніть неуспішний код виходу
//        }
//    fflush(stdin);
//
//
//    do {
//        delta = (1 / k) * (x / (pow(ytemp, k - 1)) - ytemp);
//        y = ytemp + delta;
//        ytemp = y;
//        i = i + 1;
//    } while (fabs(delta) >= e);
//    printf("Y = %.10lf\n", y);
//        printf("Бажаєте продовжити (y/n)? ");
//        scanf(" %c", &restart);
//        fflush(stdin);
//
//    } while (restart == 'Y' || restart == 'y');
//
//    return 0;
//}