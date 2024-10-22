#include <iostream>
#include <list>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;

struct User {
    int phone_number;
    string full_name;
};

struct HashTable {//хеш-таблица
    size_t table_size;
    list<User>* table;

    HashTable(size_t size) : table_size(size) {
        table = new list<User>[table_size];// Выделение памяти под массив списков
    }

    ~HashTable() {
        delete[] table;
    }

    size_t hash_function(int key) {// Функция хеширования
        return key % table_size;
    }

    void add_element(int phone_number, const string& full_name) {// добавления элемента 
        size_t index = hash_function(phone_number);
        table[index].push_back({ phone_number, full_name });
    }

    void remove_element(int phone_number) {//  удаления элемента 
        size_t index = hash_function(phone_number);
        auto& chain = table[index];//ссылку на цепочку элементов
        for (auto it = chain.begin(); it != chain.end(); it++) {
            if (it->phone_number == phone_number) {
                chain.erase(it);
                return;
            }
        }
    }

    string search_element(int phone_number) {//поиск
        size_t index = hash_function(phone_number);
        for (const auto& user : table[index]) {//объявление переменной user, которая будет использоваться для хранения элементов, полученных из списка table[index]
            if (user.phone_number == phone_number) {
                return user.full_name;
            }
        }
        return "Не найдено";
    }

    void print_table() {//вывод
        for (size_t i = 0; i < table_size; i++) {
            cout << "Индекс " << i << ": ";
            for (const auto& user : table[i]) {
                cout << user.phone_number << ", " << user.full_name << "\t\t";
            }
            cout << endl;
        }
    }
};

void main() {
    setlocale(LC_ALL, "ru");

    int size[] = { 16, 32, 64, 128 };
    int size_choice, error = 0;
    cout << "\nВыберите размер хеш-таблицы : " << endl;
    cout << "0. 16" << endl;
    cout << "1. 32" << endl;
    cout << "2. 64" << endl;
    cout << "3. 128" << endl;
    do
    {
        error = 0;
        cin >> size_choice;
        if (size_choice < 0 || size_choice > 3) {
            error = 1;
            cout << "Ошибка. Повторите попытку: ";
        }
    } while (error);

    HashTable hash_table(size[size_choice]);// Создание объекта хеш-таблицы с выбранным размером

    int choice; int phone_number;
    string full_name; bool err = 0;

    do {
        cout << "\n1. Добавление элемента\n";
        cout << "2. Удаление элемента\n";
        cout << "3. Поиск элемента\n";
        cout << "4. Вывод таблицы\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            do
            {
                err = 0;
                cout << "Введите номер телефона: ";
                cin >> phone_number;
                if (cin.fail()) {
                    cin.ignore(cin.rdbuf()->in_avail());// Очистка буфера ввода
                    cin.clear();// Сброс флагов ошибок ввода
                    cout << "Ошибка" << endl;
                    err = 1;
                }
            } while (err);
            cout << "Введите полное имя: "; getchar();
            getline(cin, full_name);
            hash_table.add_element(phone_number, full_name);
            break;
        case 2:
            do
            {
                err = 0;
                cout << "Введите номер телефона: ";
                cin >> phone_number;
                if (cin.fail()) {
                    cin.ignore(cin.rdbuf()->in_avail());
                    cin.clear();
                    cout << "Ошибка" << endl;
                    err = 1;
                }
            } while (err);
            hash_table.remove_element(phone_number);
            break;
        case 3:
        {
            do
            {
                err = 0;
                cout << "Введите номер телефона: ";
                cin >> phone_number;
                if (cin.fail()) {
                    cin.ignore(cin.rdbuf()->in_avail());
                    cin.clear();
                    cout << "Ошибка" << endl;
                    err = 1;
                }
            } while (err);

            auto start = chrono::high_resolution_clock::now();
            //clock_t start1 = clock();
            string search_number = hash_table.search_element(phone_number);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;
            //clock_t stop1 = clock();
            //long long duration1 = static_cast<int>(floor(static_cast<double>(stop1 - start1) * 1000000 / CLOCKS_PER_SEC));
            cout << "Результат: " << search_number << " за " << duration.count() << " милисекунд" << endl;
            break;
        }
        case 4:
            hash_table.print_table();
            break;
        case 0:
            cout << "Выход." << endl;
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    } while (choice != 0);
}