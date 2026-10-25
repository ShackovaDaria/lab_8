#include <stdio.h>
#include <math.h>
#include <locale.h>

int z_0(int s, char c1, char c2);
int z_1(int m, int n);
void z_1a(int n, int m);
void z_2(double h);

int main() {
    setlocale(LC_ALL, "ru");

    // Задание 0
    printf("---Задание 0 ---\n");
    int s;
    char c1, c2;
    puts("введите количество звезд: ");
    scanf("%d", &s);
    puts("введите 2 символа через пробел: ");
    scanf(" %c %c", &c1, &c2);
    z_0(s, c1, c2);

    // Задание 1
    printf("\n\n---Задание 1 ---\n");
    int m, n;
    puts("введите числа m и n (m>n): ");
    scanf("%d %d", &m, &n);
    int sum = z_1(m, n);
    printf("сумма чисел от %d до %d равна %d\n", m, n, sum);

    // Задание 1a
    printf("\n\n--- Задание 1a ---\n");
    puts("введите степень n: ");
    scanf("%d", &n);
    puts("введите максимальное значение: ");
    scanf("%d", &m);
    z_1a(n, m);

    // Задание 2
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

int z_1(int m, int n) {
    int sum = 0;
    for (int i = m; i >= n; i--) {
        sum += i;
    }
    return sum;  
}

void z_1a(int n, int m) {
    for (int i = 0; i <= n && pow(2, i) <= m; i++) {
        double val = pow(2, i);
        if ((int)(val / 1024) == 0) {
            printf("2^%d = %.1f\n", i, val);
        } else {
            int res = (int)(val / 1024);
            printf("2^%d = %dK\n", i, res);
        }
}}

void z_2(double h) {
    if (h <= 0) {
        printf("Ошибка: шаг табуляции должен быть больше 0\n");
        return;
    }

    double x, y;
    printf("____________\n");
    printf("|  x | f(x) |\n");
    printf("------------\n");

    for (x = 1.0; x <= 3.0 + 1e-9; x += h) {  // +epsilon чтобы захватить 3.0 при округлении
        y = x * x * x - 4.0 * x * x + 2.0;
        printf("|%4.2g |%4.2g |\n", x, y);
        printf("------------\n");
    }
}
