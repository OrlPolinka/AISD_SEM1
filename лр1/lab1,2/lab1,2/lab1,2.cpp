#include <iostream>
#include <ctime>
using namespace std;

unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    setlocale(LC_CTYPE, "RU");
    int N;
    cout << "Введите число N: ";
    cin >> N;

    if (N < 0) {
        do {
            cout << "Число N должно быть больше или равно 0." << endl;
            cout << "Введите число N: ";
            cin >> N;
        } while (N < 0);
    }
    clock_t start = clock();// Начало отсчета времени

    cout << N << "-ое число ряда Фибоначчи: " << fibonacci(N) << endl;
    
    clock_t stop = clock();// Конец отсчета времени
    int duration = static_cast<int>(floor(static_cast<double>(stop - start) / CLOCKS_PER_SEC));// Вычисление времени выполнения в секундах
    cout << "Расчетное время циклом " << duration / 60 << " минут " << duration % 60 << " секунд." << endl;// Вывод расчетного времени

    return 0;
}



