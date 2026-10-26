#include <stdio.h>
#include <math.h>
#include <locale.h>

int z_0(int s, char c1, char c2);
int z_1(int m, int n);
int z_1a(int n, int m, double *results);
double z_2_calc(double x);
void z_2(double h);

int main() {
    setlocale(LC_ALL, "ru");
//задание 0
    printf("---Задание 0 ---\n");
    int s;
    char c1, c2;
    printf("введите количество звезд: ");
    scanf("%d", &s);
    printf("введите 2 символа через пробел: ");
    scanf(" %c %c", &c1, &c2);
    z_0(s, c1, c2);
    printf("\n");
//задание 1
    printf("\n---Задание 1 ---\n");
    int m, n;
    printf("введите числа m и n (m>n): ");
    scanf("%d %d", &m, &n);
    int sum = z_1(m, n);
    printf("сумма чисел от %d до %d равна %d\n", m, n, sum);

    printf("\n--- Задание 1a ---\n");
    printf("введите степень n: ");
    scanf("%d", &n);
    printf("введите максимальное значение: ");
    scanf("%d", &m);
    
    double results[50];
    int count = z_1a(n, m, results);
    
    for (int i = 0; i < count; i++) {
        double val = results[i];
        if ((int)(val / 1024) == 0) {
            printf("2^%d = %.1f\n", i, val);
        } else {
            int res = (int)(val / 1024);
            printf("2^%d = %dK\n", i, res);
        }
    }

    printf("\n--- Задание 2 ---\n");
    double h;
    printf("вычисляемая функция: y=x^3-4*x^2+2\nотрезок: [1,3]\n");
    printf("введите шаг табуляции: ");
    scanf("%lf", &h);

    z_2(h);

    return 0;
}

int z_0(int s, char c1, char c2) {
    putchar('+');
    for (int start = 1; start <= s; start++) {
        char cur = (start <= s / 2) ? c1 : c2;
        putchar(cur);
        putchar('!');
    }
    putchar('+');
    return 0;
}

int z_1(int m, int n) {
    int sum = 0;
    for (int i = m; i >= n; i--) {
        sum += i;
    }
    return sum;
}

int z_1a(int n, int m, double *results) {
    int count = 0;
    for (int i = 0; i <= n && pow(2, i) <= m; i++) {
        results[count] = pow(2, i);
        count++;
    }
    return count;
}

double z_2_calc(double x) {
    return x * x * x - 4.0 * x * x + 2.0;
}

void z_2(double h) {
    if (h <= 0) {
        printf("Ошибка: шаг должен быть больше 0\n");
        return;
    }

    double x, y;
    printf("____________\n");
    printf("|  x | f(x) |\n");
    printf("------------\n");

    for (x = 1.0; x <= 3.0 + 1e-9; x += h) {
        y = z_2_calc(x);
        printf("|%4.2g |%4.2g |\n", x, y);
        printf("------------\n");
    }
}
