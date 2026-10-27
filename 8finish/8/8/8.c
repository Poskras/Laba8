#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

int Task0(int num, char symbol, char result[], int size);
long long Task1(int m, int n);
long long Task1A(long long m);
double Task2(double x);
long long TaskDZ(int n);

int main()
{
    int num;
    char symbol;
    char repeatedSymbols[10000];
    int symbolCount;

    int m;
    int n;
    long long sum;
    long long limit;
    long long power;
    int exponent;

    double step;
    double x;
    double y;
    long long dzResult;
    int N;

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".UTF8");

    printf("ЗАДАНИЕ 0. Повторение символа\n");
    printf("Введите количество повторений (1-9999): ");
    if (scanf_s("%d", &num) != 1 || num < 1 || num > 9999)
    {
        printf("Ошибка: количество должно быть от 1 до 9999.\n");
    }
    else
    {
        printf("Введите символ: ");
        if (scanf_s(" %c", &symbol, 1) != 1)
        {
            printf("Ошибка ввода символа.\n");
        }
        else
        {
            symbolCount = Task0(num, symbol, repeatedSymbols, 10000);
            if (symbolCount >= 0)
            {
                printf("%s\n", repeatedSymbols);
            }
            else
            {
                printf("Не удалось сформировать строку.\n");
            }
        }
    }

    printf("\nЗАДАНИЕ 1. Сумма чисел от m до n\n");
    printf("Введите m: ");
    if (scanf_s("%d", &m) != 1)
    {
        printf("Ошибка ввода m.\n");
    }
    else
    {
        printf("Введите n: ");
        if (scanf_s("%d", &n) != 1)
        {
            printf("Ошибка ввода n.\n");
        }
        else if (m < n)
        {
            printf("Ошибка: m должно быть не меньше n.\n");
        }
        else
        {
            sum = Task1(m, n);
            printf("Сумма: %lld\n", sum);
        }
    }

    printf("\nЗАДАНИЕ 1А. Степени двойки до m\n");
    printf("Введите целое число m: ");
    if (scanf_s("%lld", &limit) != 1 || limit < 1)
    {
        printf("Ошибка: введите положительное целое число.\n");
    }
    else
    {
        limit = Task1A(limit);
        power = 1;
        exponent = 0;
        printf("Степени двойки, не превышающие m:\n");
        while (power <= limit)
        {
            printf("2^%d = %lld\n", exponent, power);
            if (power > limit / 2)
            {
                break;
            }
            power *= 2;
            exponent++;
        }
        printf("Результат: %.1fK\n", limit / 1024.0);
    }

    printf("\nЗАДАНИЕ 2. Табулирование функции\n");
    printf("Функция: y = |e^x - 2| - x^2\n");
    printf("Введите шаг табуляции: ");
    if (scanf_s("%lf", &step) != 1 || step <= 0)
    {
        printf("Ошибка: шаг должен быть положительным числом.\n");
    }
    else
    {
        printf("\n      x      |     f(x)\n");
        printf("------------------------\n");

        for (x = 1.0; x <= 3.0 + 1e-9; x += step)
        {
            y = Task2(x);
            printf("%10.2f | %10.4f\n", x, y);
        }
    }

    printf("\nЗАДАНИЕ ДЗ. Сумма квадратов от N до 2N\n");
    printf("Введите целое число N (N >= 0): ");
    if (scanf_s("%d", &N) != 1 || N < 0)
    {
        printf("Ошибка: N должно быть неотрицательным целым числом.\n");
    }
    else
    {
        dzResult = TaskDZ(N);
        printf("Результат: %lld\n", dzResult);
    }
    return 0;
}

int Task0(int num, char symbol, char result[], int size)
{
    int i;

    if (num < 1 || num >= size)
    {
        return -1;
    }
    for (i = 0; i < num; i++)
    {
        result[i] = symbol;
    }
    result[num] = '\0';
    return num;
}

long long Task1(int m, int n)
{
    long long sum = 0;
    int i;

    for (i = m; i >= n; i--)
    {
        sum += i;
    }
    return sum;
}

long long Task1A(long long m)
{
    long long result = 1;

    while (result <= m / 2)
    {
        result *= 2;
    }

    return result;
}

double Task2(double x)
{
    return fabs(exp(x) - 2.0) - x * x;
}
long long TaskDZ(int n)
{
    long long sum = 0;
    int i;

    for (i = n; i <= 2 * n; i++)
    {
        sum += (long long)i * i;
    }
    return sum;
}
