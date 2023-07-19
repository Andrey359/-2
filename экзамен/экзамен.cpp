#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

class AppUI {
public:
	int len;
	void getLen() {
		cout << "Введите длину массива: ";
		cin >> this->len;
	}

	template<typename T>
	void getAB(T a, T b) {
		cout << "Введите начало случайных чисел: ";
		cin >> a;

		cout << "Введите конец случайных чисел: ";
		cin >> b;
	}

	void show() {
		int mod;
			cout << "целчисленный - 0\n";
			cout << "дробный  от 0.0f до 1.0f - 1\n";
			cout << "дробный  - 2\n";
			cout << "Выберите режим работы: ";
			cin >> mod;
			switch (mod)
			{
				case 0: 
				{
					getLen();
					int* arr = new int[len];

					int a, b;
					getAB<int>(a, b);

					for (int i = 0; i < len; i++)
					{
						arr[i] = rand() % (b - a + 1) + a;
						cout << arr[i] << endl;
					}
					delete[] arr;
					break;
				}
				case 1: 
				{
					getLen();
					double* arr = new double[len];

					for (int i = 0; i < len; i++)
					{
						arr[i] = rand() / (float)RAND_MAX;
						cout << arr[i] << endl;
					}
					delete[] arr;
					break;
				}
				default: 
				{
					double* arr = new double[len];

					for (int i = 0; i < len; i++)
					{
						arr[i] = (rand() / (float)RAND_MAX) * (a - b + 1) + a;
						cout << arr[i] << endl;
					}
					delete[] arr;

					break; 
				}
			}

		}
	};

int main()
{
	srand(time(0));
	AppUI a;

	AppUI b;
	//a.random();


}


/*
 Настраиваемый генератор массивов случайных чисел. Требуются
возможности:
a. Настройка диапазона (от а до б).
b. Выбор длины массива.
c. Режим дробных чисел.
*/