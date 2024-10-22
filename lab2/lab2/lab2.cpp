#include <iostream>
#include <Windows.h>
using namespace std;

void print_steps(int N, int mid) {
    int count = -1, temp;
    temp = N;
    while (temp > 0) {
        count++;
        if (temp > 1) {
            if (temp % 2 == 0) {
                temp /= 2;
            }
            else {
                temp = (temp + 1) / 2;
            }
        }
        else {
            break;
        }
    }
    cout << "Максимальное количество шагов = " << count << endl;

    while (N > 0) {
        cout << N << endl;

        if (N > 1) {
            if (N % 2 == 0) {
                N /= 2;
            }
            else {
                N = (N + 1) / 2;
            }
        }
        else {
            break;
        }
    }
    cout << "Загаданное число = " << mid << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N, X, b, a;

    cout << "Введите N: ";
    cin >> N;

    while (N < 1) {
        cout << "N должно быть больше 1. Повторите попытку: ";
        cin >> N;
    }

    int down = 1; // нижняя граница для поиска
    int up = N; // верхняя граница для поиска

    do {

        X = (down + up) / 2;

        if (up == down) {
            break;
        }

        cout << "Загадано число от " << down << " до " << up << "\nВаше число: ";
        
        cout << X << endl;
        cout << "Ваш выбор(1-много, 2-мало или 3-угадал): ";
        cin >> a;
        while (a != 1 && a != 2 && a != 3) {
            cout << "Ошибка. Повторите попытку.";
            cout << "Ваш выбор(1-много, 2-мало или 3-угадал): ";
            cin >> a;
        }
        if (a == 1) {
            up = X - 1;
        }
        else if (a == 2) {
            down = X + 1;
        }
        
        if (X == up || X == down) {
            if (a == 1) {
                X = down;
                break;
            }
            else if (a == 2) {
                X = up;
                break;
            }
        }
    } while (a != 3);
    
    print_steps(N, X);

}
