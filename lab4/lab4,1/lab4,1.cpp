#include <iostream>
#include <cstdlib> // Для функции rand()
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int N;
	cout << "Введите количество товаров: ";
	cin >> N;
	while (N > 10000 || N <= 0) {
		cout << "Ошибка. Повторите попытку:";
		cin >> N;
	}

	int* A = new int[N];
	cout << "\nЦены товаров:" << endl;
	srand(time(0)); // Инициализация генератора случайных чисел
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 100; // Генерация случайных чисел от 0 до 99
		cout << A[i] << " ";
	}
	cout << endl;

	// Сортировка выбором
	for (int i = 0; i < N - 1; i++) {
		int min = i;
		for (int j = i + 1; j < N; j++) {
			if (A[j] < A[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(A[i], A[min]);
		}
	}

	int* B = new int[N];
	int left = 0, right = N - 1;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			B[i] = A[right--];
		}
		else {
			B[i] = A[left++];
		}
	}

	cout << "Порядок пробивания на кассе: " << endl;
	for (int i = 0; i < N; i++) {
		cout << B[i] << " ";
	}
	cout << endl;

	int s = 0;

	cout << "Максимальная сумма чека: ";
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			s += B[i];
		}
	}
	cout << s << endl;

	delete[] A;
	delete[] B;

	return 0;
}