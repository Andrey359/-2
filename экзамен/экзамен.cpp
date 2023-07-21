#include <iostream>
#include <time.h>

using namespace std;

class AppUI {
public:
	long long len, a, b; 
	bool l = 0;
	void getLen() {
		while (true)
		{
			if (l) {
				len = rand() % 100 + 1;
				break;
			}

			else {
				cout << "Введите длину массива: ";
				cin >> len;

				if (len > 0) {
					break;
				}
				if (len == 0) {
					cerr << "Вы ввели нулевое значение, повторите попытку .." << endl;
				}
				if (len < 0) {
					cerr << "Вы ввели отрицательное значение, повторите попытку .." << endl;
				}
				if (len > INT_MAX) {
					cerr << "Вы ввели слишком большое значение, повторите попытку .." << endl;
				}
			}
		}
	}

	void getAB() {
		if (l) {
			a = rand() % 100 + 1;
			b = rand() % 100 + 1;
		}
		else {
			cout << "Введите начало случайных чисел: ";
			cin >> a;

			cout << "Введите конец случайных чисел: ";
			cin >> b;
		}
		if (a > b) {
			int c = a;
			a = b;
			b = c;
		}
	}

	void show() {
		int mod;
			cout << "целчисленный - 0\n";
			cout << "дробный  от 0.0f до 1.0f - 1\n";
			cout << "дробный  - 2\n";
			cout << "я не знаю  - любое число\n" << endl;
			cout << "Выберите режим работы: ";
			cin >> mod;
			if (mod > 2) {
				mod = rand() % 3;
				l = 1;
			}
			switch (mod)
			{
				case 0: 
				{
					getLen();
					int* arr = new int[len];
					getAB();

					for (int i = 0; i < len; i++)
					{
						arr[i] = rand() % (b - a + 1) + a;
						cout <<"[" << i << "] = " << arr[i] << endl;
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
						arr[i] = rand() / (double)RAND_MAX;
						cout << "[" << i << "] = " << arr[i] << endl;
					}
					delete[] arr;
					break;
				}
				case 2: 
				{
					getLen();
					double* arr = new double[len];
					getAB();
					for (int i = 0; i < len; i++)
					{
						arr[i] = (rand() / (double)RAND_MAX) * (b - a + 1) + a;
						cout << "[" << i << "] = " << arr[i] << endl;
					}
					delete[] arr;
					break; 
				}
			}
		}
	};

int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));

	AppUI a;
	a.show();
	return 0;
}
