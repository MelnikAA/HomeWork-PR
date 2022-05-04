// try_catch.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;


class Complex
{
public:
	double Re;
	double Lm;
};

void enter(Complex& complex, bool& exit)
{
	cout << "Введите веществ часть: " ;
	cin >> complex.Re;
	if (cin.fail()) {
		throw 1;
	}
	cout << "\nВведите мним часть: " ;
	cin >> complex.Lm;
	if (cin.fail()) {
		throw "fail";
	}
	exit = false;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	bool exit = true;
	Complex complex;
	while (exit)
	{
		try
		{
			enter(complex, exit);
		}
		catch (int er)
		{
			cout << "\nВсе фигня, давай по новой\n" << endl;
			cin.clear();
			cin.ignore();
		}
		catch (const char* er)
		{
			cout << "\nОшибка типа char*" << endl;

			cin.clear();
			cin.ignore();
		}
		catch (...)
		{
			std::cout << "\nНекорректный ввод данных. Повторите попытку." << endl;

			cin.clear();
			cin.ignore();
		}
	}

	cout << "Вы ввели " << complex.Re << ' ' << complex.Lm << endl;

	system("pause");
}
