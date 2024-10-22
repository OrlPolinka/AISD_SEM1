#include <iostream>
#include <ctime> 

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	int N, tmp, step;
	int winners = 0; //Количество призёров
	int i, j, k;

	do
	{
		cout << "Введите количество участников: ";
		cin >> N;

		if (N > 10000 || N <= 0) {
			cout << "Некорректный ввод" << endl;
		}

	} while (N > 10000 || N <= 0);

	if (N < 3)
	{
		cout << "Количество призёров = " << N;
		return 0;
	}

	int size = N;//Размер массива или количество участников

	int* participantScores = new int[size]; //Баллы участников

	for (i = 0; i < size; i++)	//Заполнение массива
		participantScores[i] = (rand() % 100 + 1);


	// Сортировка выбором
	for (int i = 0; i < N - 1; i++) {
		int min = i;
		for (int j = i + 1; j < N; j++) {
			if (participantScores[j] < participantScores[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(participantScores[i], participantScores[min]);
		}
	}


	unsigned int top1 = participantScores[size - 1], top2 = participantScores[size - 1], top3 = participantScores[size - 1]; //Места победителей
	bool top2Check = true, top3Check = true; // Булевые переменные чтобы заполнить топ

	for (i = size - 1; i >= 0; i--)
	{
		if (top2 > participantScores[i] && top2Check && top2 >= top1)
		{
			top2 = participantScores[i];
			top2Check = false;
		}
		if (top3 > participantScores[i] && top3Check && participantScores[i] != top2)
		{
			top3 = participantScores[i];
			top3Check = false;
		}


	}

	// Цикл посчёта количества победителей 

	for (i = size - 1; i >= 0; i--)
		if (participantScores[i] == top1 || participantScores[i] == top2 || participantScores[i] == top3) {
			winners++;
		}

	cout << endl << endl;

	cout << "Начальные данные" << endl;
	for (i = 0; i < size; i++) {
		cout << participantScores[i] << ' ';
	}

	cout << endl << endl;

	cout << top1 << ' ' << top2 << ' ' << top3;


	cout << endl << endl;

	cout << "Количество призёров = " << winners << endl << endl;

	return 0;
}