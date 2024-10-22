#include <iostream>
#include <cstdlib> // Для функции rand()
#include <ctime>   // Для функции time()
using namespace std;

void sort(int* E, int first, int last) {
	int mid;
	int f = first, l = last;
	mid = E[(f + l) / 2];
	do {
		while (E[f] < mid) {
			f++;
		}
		while (E[l] > mid) {
			l--;
		}
		if (f <= l) {
			swap(E[f], E[l]);
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) {
		sort(E, first, l);
	}
	if (f < last) {
		sort(E, f, last);
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int N;
	cout << "Введите N: ";
	cin >> N;
	while (N < 1) {
		cout << "Ошибка. N должно быть больше нуля. Попробуйте снова: ";
		cin >> N;
	}

	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];
	int* D = new int[N];
	int* E = new int[N];

	cout << "\nИсходный массив A:" << endl;
	srand(time(0)); // Инициализация генератора случайных чисел
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 100; // Генерация случайных чисел от 0 до 99
		cout << A[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}

	//пузырьковая сортировка
	clock_t start1 = clock();

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (B[j] > B[j + 1]) {
				swap(B[j], B[j + 1]);
			}
		}
	}

	clock_t stop1 = clock();
	long long duration1 = static_cast<int>(floor(static_cast<double>(stop1 - start1) * 1000 / CLOCKS_PER_SEC));
	cout << "\nРасчетное время пузырьковой сортировки " << duration1 << " милисекунд." << endl;

	cout << "Массив B: " << endl;
	for (int i = 0; i < N; i++) {
		cout << B[i] << " ";
	}
	cout << endl;

	//сортировка вставкой
	clock_t start2 = clock();

	for (int i = 1; i < N; i++) {
		int buff = C[i];
		int j = i - 1;
		while (j >= 0 && C[j] > buff) {
			C[j + 1] = C[j];
			j--;
		}
		C[j + 1] = buff;
	}
	
	clock_t stop2 = clock();
	long long duration2 = static_cast<int>(floor(static_cast<double>(stop2 - start2) * 1000 / CLOCKS_PER_SEC));
	cout << "\nРасчетное время сортировки вставкой " << duration2 << " милисекунд." << endl;

	cout << "Массив C: " << endl;
	for (int i = 0; i < N; i++) {
		cout << C[i] << " ";
	}
	cout << endl;

	//сортировка выбором
	clock_t start3 = clock();

	for (int i = 0; i < N; i++) {
		int min = i;
		for (int j = i + 1; j < N; j++) {
			min = (D[j] < D[min]) ? j : min;
		}
		if (i != min) {
			swap(D[i], D[min]);
		}
	}

	clock_t stop3 = clock();
	long long duration3 = static_cast<int>(floor(static_cast<double>(stop3 - start3) * 1000 / CLOCKS_PER_SEC));
	cout << "\nРасчетное время сортировки выбором " << duration3 << " милисекунд." << endl;

	cout << "Массив D: " << endl;
	for (int i = 0; i < N; i++) {
		cout << D[i] << " ";
	}
	cout << endl;

	//быстрая сортировка
	clock_t start4 = clock();

	sort(E, 0, N-1);

	clock_t stop4 = clock();
	long long duration4 = static_cast<int>(floor(static_cast<double>(stop4 - start4) * 1000 / CLOCKS_PER_SEC));
	cout << "\nРасчетное время быстрой сортировки " << duration4 << " милисекунд." << endl;

	cout << "Массив E  : " << endl;
	for (int i = 0; i < N; i++) {
		cout << E[i] << " ";
	}
	cout << endl;

	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;

	return 0;
}