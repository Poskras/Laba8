#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

void Task0();
void Task1();
void Task1A();
void Task2();
void TaskDZ();

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, ".UTF8");

	Task0();
	Task1();
	Task1A();
	Task2();
	TaskDZ();

	return 0;
}

void Task0 () {
	int num;
	char symbol;

	printf("введите число сколько раз будет выводится символ: ");
	scanf_s ("%d", &num);

	printf("введите символ:");
	scanf_s (" %c", &symbol);

	for (int start = 1; start <= num; start++)
		putchar(symbol);
}

void Task1() {
	int m, n;
	int s = 0;
	int k = 1;

	printf("\n\nвведите m: ");
	scanf_s("%d", &m);

	printf("введите n: ");
	scanf_s("%d", &n);

	for (int i = m; i >= n; i--) {
		s += i;
		printf("Выполнено %d раз\n", k++);
	}

	printf("Результат: %d\n", s);
}

void Task1A() {
	long long m;
	long long result = 1;

	printf("\n\nвведите целое число m: ");
	scanf_s("%lld", &m);

	if (m < 1) {
		printf("введите число больше нуля.\n");
		return;
	}
	for (int i = 0; result <= m; i++) {
		printf("2^%2d = %10lld\n", i, result);

		if (result > m / 2) {
			break;
		}
		result *= 2;
	}

	printf("результат: %.1fK\n", m / 1024.0);
}

void Task2() {
	//вариант8 20-12
	double x;
	double y;
	double step;

	printf("\n\nфункция: y = |e^x - 2| - x^2\n");
	printf("введите шаг табуляции: ");
	scanf_s("%lf", &step);

	if (step <= 0) {
		printf("щаг должен быть больше нуля\n");
		return;
	}

	printf("\n      x      |     f(x)\n");
	printf("------------------------\n");

	for (x = 1.0; x <= 3.0 + 1e-9; x += step) {
		y = fabs(exp(x) - 2) - x * x;
		printf("%10.2f | %10.4f\n", x, y);
	}
}

void TaskDZ() {
	//вариант21
	int N;
	double sum = 0;

	printf("\n\nвведите целое число N: ");
	scanf_s("%d", &N);

	for (int i = N; i <= 2 * N; i++) {
		sum += (double)i * i;
	}

	printf("результат: %.2f\n", sum);
}