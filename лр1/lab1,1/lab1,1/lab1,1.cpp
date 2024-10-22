#include <iostream> 
#include <ctime> 
using namespace std;

void main() {
	setlocale(LC_ALL, "ru");
	long long N;

	cout << "Введите число N: ";
	cin >> N;

	while (N < 0) {
		cout << "Число N должно быть больше или равно 0." << endl;
		cout << "Введите число N: ";
		cin >> N;
	}

	clock_t start = clock();
	unsigned long long* F = new unsigned long long[N + 1];
	F[0] = 0;
	F[1] = 1;

	if (N == 0) {
		cout << N << "-ое число ряда Фибоначчи: " << F[0] << endl;
	}
	else {
		for (long long i = 2; i <= N; i++) {
			F[i] = F[i - 2] + F[i - 1];
		}
		cout << N << "-ое число ряда Фибоначчи: " << F[N] << endl;

		delete[] F;
	}

	clock_t stop = clock();
	long long duration = static_cast<int>(floor(static_cast<double>(stop - start) / CLOCKS_PER_SEC));

	cout << "Расчетное время циклом " << duration / 60 << " минут " << duration % 60 << " секунд." << endl;
}