#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>
#include "Box.h"
#include "Ship.h"

using namespace std;

Ship::Ship()//Конструктор заполняющий массивы знаком "-"
{
	for (int i(0); i < 9; i++)
		for (int j(0); j < 9; j++)
			SaveKletka_1[i][j] = GetCaseFirstPlayer(i, j);
	for (int i(0); i < 9; i++)
		for (int j(0); j < 9; j++)
			SaveKletka_2[i][j] = GetCaseSecondPlayer(i,j);
	FlagAuto = 0;
}

bool Ship::ProverkaUp(int i, int j) //Проверка вверх
{
	if (i == 0)//Проверка верхней границы
	{
					return 0;
	}
	else if (j == 0)//Проверка Левой границы
	{
		if (i == 9)//Проверка Нижне левого угла
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
				if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
						return 1;
		}
		if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
			if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
				if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
					return 1;
	}
	else if (i == 9) //Нижняя граница
	{
		if (j == 9) //Нижне правый угол
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
				if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
						return 1;
		}
		if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
			if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
				if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
						if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
							return 1;
	}
	else if (j == 9) //Проверка правой границы
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
			if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
				if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
					if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //Проверка снизу слева
						return 1;
	}
	else
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
			if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
				if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
						if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
							if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
								if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //Проверка снизу слева
									return 1;
	}
	return 0;

}


bool Ship::ProverkaDown(int i, int j)//Проверка нижней границы
{
	if (i == 9) //Нижняя граница
		return 0;
	else if (i == 0)//Проверка верхней границы
	{
		if (j == 0)//Проверка Левой границы
		{
			if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
				if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
					return 1;
		}
		else if (j == 9)  //Проверка Правой границы
		{
			if (GetCaseFirstPlayer(i + 1, j) == '-')
				if (GetCaseFirstPlayer(i, j - 1) == '-')
					return 1;
		}
		if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
			if (GetCaseFirstPlayer(i, j - 1) == '-') //Слева
				if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //Проверка снизу слева
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
						return 1;
	}
	else if (j == 0)// Левая граница
	{
		if (GetCaseFirstPlayer(i + 1, j) == '-') //Проверка снизу
			if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
				if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
					return 1;
	}
	else if (j == 9)//Правая граница
	{
		if (GetCaseFirstPlayer(i + 1, j) == '-') //Проверка снизу
			if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
				if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
					if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //Проверка снизу слева
						return 1;
	}
	else
	{
		if (GetCaseFirstPlayer(i + 1, j) == '-') //Проверка снизу
			if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
				if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
						if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
							if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
								if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //Проверка снизу слева
									return 1;
	}
	return 0;
}

bool Ship::ProverkaRight(int i, int j) //Проверка справа
{
	if (j == 9)//Проверка правой границы
		return 0;
	else if (i == 0)//В случае расположения у верхней границы
	{
		if (j == 0)//И Левой границы
		{
			if (GetCaseFirstPlayer(i + 1, j) == '-') //Проверка  снизу
				if (GetCaseFirstPlayer(i, j + 1) == '-') // Проверка справа
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
						return 1;
		}
		if (GetCaseFirstPlayer(i + 1, j) == '-') //Проверка  снизу
			if (GetCaseFirstPlayer(i, j + 1) == '-') // Проверка справа
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
						if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //Проверка снизу слева
							return 1;
	}
	else if (j == 0)//Если у левой границы
	{
		if (i == 9)//И нижней строки
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') // Проверка вверх
				if (GetCaseFirstPlayer(i, j + 1) == '-') // Проверка справа
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
					return 1;
		}//Только у левой границы
		if (GetCaseFirstPlayer(i + 1, j) == '-') // Проверка снизу
			if (GetCaseFirstPlayer(i - 1, j) == '-') // Проверка сверху
				if (GetCaseFirstPlayer(i, j + 1) == '-') // Проверка справа
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
						if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
							return 1;
	}
	else if (i == 9)//Только нижней строки
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') // Проверка сверху
			if (GetCaseFirstPlayer(i, j + 1) == '-') // Проверка справа
				if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
					return 1;
	}
	else //Центр
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
			if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
				if (GetCaseFirstPlayer(i + 1, j) == '-') // Проверка снизу
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
						if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
							if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
								if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //Проверка снизу слева
									return 1;
	}
	return 0;
}

bool Ship::ProverkaLeft(int i, int j)//Проверка слева
{
	if (j == 0)//Левая граница
		return 0;
	else if (j == 9)//Правая граница
	{
		if (i == 0)//Верхняя граница
		{
			if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
				if (GetCaseFirstPlayer(i + 1, j) == '-')//Проверка снизу 
					if (GetCaseFirstPlayer(i + 1, j - 1) == '-')//Проверка снизу слева
						return 1;
		}
		if (i == 9)//Нижняя строка
		{
			if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
				if (GetCaseFirstPlayer(i - 1, j) == '-')//Проверка сверху
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-')//Проверка сверха слева
						return 1;
		}
		if (GetCaseFirstPlayer(i + 1, j) == '-')//Проверка снизу
			if (GetCaseFirstPlayer(i, j - 1) == '-')//Проверка слева
				if (GetCaseFirstPlayer(i - 1 , j) == '-')//Проверка сверху
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-')//Проверка сверха слева
						if (GetCaseFirstPlayer(i + 1, j - 1) == '-')//Проверка снизу слева
							return 1;
	}
	else if (i == 0)//верхняя граница
	{
		if (GetCaseFirstPlayer(i, j - 1) == '-')//Проверка слева
			if (GetCaseFirstPlayer(i + 1, j - 1) == '-')//Проверка снизу слева
				if (GetCaseFirstPlayer(i + 1, j) == '-')//Проверка снизу
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-')//Проверка снизу справа
						return 1;
	}
	else if(i == 9)//Нижняя граница
	{
		if (GetCaseFirstPlayer(i, j - 1) == '-')//Проверка слева
			if (GetCaseFirstPlayer(i - 1, j - 1) == '-')//Проверка сверху слева
				if (GetCaseFirstPlayer(i - 1, j) == '-')//Проверка сверху
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-')//Проверка сверху справа
						return 1;
	}
	else//центр
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
			if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
				if (GetCaseFirstPlayer(i + 1, j) == '-') // Проверка снизу
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
						if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
							if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
								if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //Проверка снизу слева
									return 1;
	}
	return 0;
}

int Ship::SetUp(int i, int j, int Palub)
{
	setlocale(LC_ALL, "rus");
	ProverkaInPut(i, j);
	SetCaseFirstPlayer(i,j,'0');//Простановка первой палубы (База)
	if (FlagAuto == 0)
	PrintBox();//Печать поля
	//_getch();
	if (Palub == 1)
		return 1;
	else
	{
		int _TempForSwitch;
		if (FlagAuto == 0)
		{
			system("cls");//очистка экрана
			cout << "Выберети следующие значение: " << endl;
			cout << "1. Слева" << endl;
			cout << "2. Справа" << endl;
			cout << "3. Снизу" << endl;
			cout << "4. Сверху" << endl;
		}
		if (FlagAuto == 0)
		{
			do
			{
				cin >> _TempForSwitch;//Принятие варианта меню
			} while (_TempForSwitch < 1 || _TempForSwitch > 4);
		}
		else if (FlagAuto == 1)
		{
			do
			{
				_TempForSwitch = AutoChoose();
			} while (_TempForSwitch < 1 || _TempForSwitch > 4);
		}
		else
		{
			cout << "Error #2";
		}
		switch (_TempForSwitch)
		{
		case 1:
		{
			int Temp = Palub;//Переменная для хранения кол-ва уже расставленных палуб для последующего удаления
			int TempI[5] = { 0 }; //Переменная для хранения адреса уже расставленных палую
			for (int t(0); t < Palub; t++)
				if (ProverkaLeft(i, j - t))//Основное размещение с проверкой границ и соседник кораблей
				{
					Temp--;
					SetCaseFirstPlayer(i, j - t, '0');;
					TempI[t] = j - t;
					system("cls");
					//if (FlagAuto == 0)
					PrintBox();
					_getch();
				}
				else //Удаление в случае не хватки места
				{
					SetCaseFirstPlayer(i, j, '-');
					int k = 0;
					for (Temp; Temp < Palub; Temp++)
					{
						SetCaseFirstPlayer(i, TempI[k], '-');
						k++;
					}
					return 0;
				}
			break;
		}
		case 2:
		{
			int Temp = Palub;//Переменная для хранения кол-ва уже расставленных палуб для последующего удаления
			int TempI[5] = { 0 }; //Переменная для хранения адреса уже расставленных палую
			for (int t(0); t < Palub; t++)
				if (ProverkaRight(i, j + t))//Основное размещение с проверкой границ и соседник кораблей
				{
					Temp--;
					SetCaseFirstPlayer(i, j + t, '0');;
					TempI[t] = j + t;
					system("cls");
					//if (FlagAuto == 0)
					PrintBox();
					_getch();
				}
				else //Удаление в случае не хватки места
				{
					SetCaseFirstPlayer(i, j, '-');
					int k = 0;
					for (Temp; Temp < Palub; Temp++)
					{
						SetCaseFirstPlayer(i, TempI[k], '-');
						k++;
					}
					return 0;
				}
			break;
		}
		case 3:
		{
			int Temp = Palub;//Переменная для хранения кол-ва уже расставленных палуб для последующего удаления
			int TempI[5] = { 0 }; //Переменная для хранения адреса уже расставленных палую
			for (int t(0); t < Palub; t++)
				if (ProverkaDown(i + t, j))//Основное размещение с проверкой границ и соседник кораблей
				{
					Temp--;
					SetCaseFirstPlayer(i + t, j, '0');;
					TempI[t] = i + t;
					system("cls");
					//if (FlagAuto == 0)
					PrintBox();
					_getch();
				}
				else //Удаление в случае не хватки места
				{
					SetCaseFirstPlayer(i, j, '-');
					int k = 0;
					for (Temp; Temp < Palub; Temp++)
					{
						SetCaseFirstPlayer(TempI[k], j, '-');
						k++;
					}
					return 0;
				}
			break;
		}
		case 4:
		{
			int Temp = Palub;//Переменная для хранения кол-ва уже расставленных палуб для последующего удаления
			int TempI[5] = { 0 }; //Переменная для хранения адреса уже расставленных палую
			for (int t(0); t < Palub; t++)
				if (ProverkaUp(i - t, j))//Основное размещение с проверкой границ и соседник кораблей
				{
					Temp--;
					SetCaseFirstPlayer(i - t, j, '0');;
					TempI[t] = i - t;
					system("cls");
					//if (FlagAuto == 0)
					PrintBox();
					_getch();
				}
				else //Удаление в случае не хватки места
				{
					SetCaseFirstPlayer(i, j, '-');
					int k = 0;
					for (Temp; Temp < Palub; Temp++)
					{
						SetCaseFirstPlayer(TempI[k], j, '-');
						k++;
					}
					return 0;
				}
			break;
		}
		default:
			break;
		}
	}
		return 1;
	}

bool Ship::ProverkaInPut(int i, int j)
{
	if (i < 0 || i > 9 || j<0 || j>9)
	{
		return 0;
	}
	if (GetCaseFirstPlayer(i, j) != '-')
		return 0;
	if (i == 0)// Верхняя строка
	{
		if (j == 0)//Левый столбец
		{
			if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
				if (GetCaseFirstPlayer(i + 1, j) == '-')//Проверка снизу 
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-')//Проверка снизу справа
					return 1;
		}
		if (j == 9)
		{
			if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
				if (GetCaseFirstPlayer(i + 1, j) == '-')//Проверка снизу 
					if (GetCaseFirstPlayer(i + 1, j - 1) == '-')//Проверка снизу слева
					return 1;
		}
		if (GetCaseFirstPlayer(i + 1, j) == '-')
			if (GetCaseFirstPlayer(i, j + 1) == '-')
				if (GetCaseFirstPlayer(i, j - 1) == '-')
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-')
						if (GetCaseFirstPlayer(i + 1, j - 1) == '-')
				return 1;
	}
	else if (i == 9) //Нижний левый
	{
		if (j == 0) //Левый
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') // Проверка вверх
				if (GetCaseFirstPlayer(i, j + 1) == '-') // Проверка справа
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
						return 1;
		}
		else if( j == 9)
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
				if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
						return 1;
		}
		else
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
				if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка справа
					if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
						if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
							if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
								return 1;
		}
	}
	else if(j == 0)
	{
		if (GetCaseFirstPlayer(i + 1, j) == '-') // Проверка снизу
			if (GetCaseFirstPlayer(i - 1, j) == '-') // Проверка сверху
				if (GetCaseFirstPlayer(i, j + 1) == '-') // Проверка справа
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
						if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
							return 1;
	}
	else if (j == 9)
	{
		if (GetCaseFirstPlayer(i + 1, j) == '-')//Проверка снизу
			if (GetCaseFirstPlayer(i, j - 1) == '-')//Проверка слева
				if (GetCaseFirstPlayer(i - 1, j) == '-')//Проверка сверху
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-')//Проверка сверха слева
						if (GetCaseFirstPlayer(i + 1, j - 1) == '-')//Проверка снизу слева
							return 1;
	}
	else
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') //Проверка сверху
			if (GetCaseFirstPlayer(i, j - 1) == '-') //Проверка слева
				if (GetCaseFirstPlayer(i, j + 1) == '-') //Проверка слева
					if (GetCaseFirstPlayer(i + 1, j) == '-') // Проверка снизу
						if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //Проверка сверху слева
							if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //Проверка Сверху справа
								if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //Проверка снизу справа
									if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //Проверка снизу слева
										return 1;
	}
	return 0;
}

int Ship::InputAndConvert()
{
	char _Simvol;
	cin.ignore();
	cin.clear();
	cin >> _Simvol;
	if ((int)_Simvol < 97 || (int)_Simvol > 105)
	{
		system("cls");
		cout << "Неверный символ";
		return InputAndConvert();
	}
	switch ((int)_Simvol)
	{
	case 97:
	{
		return 0;
		break;
	}
	case 98:
	{
		return 1;
		break;
	}
	case 99:
	{
		return 2;
		break;
	}
	case 100:
	{
		return 3;
		break;
	}
	case 101:
	{
		return 4;
		break;
	}
	case 102:
	{
		return 5;
		break;
	}
	case 103:
	{
		return 6;
		break;
	}
	case 104:
	{
		return 7;
		break;
	}
	case 105:
	{
		return 8;
		break;
	}
	case 106:
	{
		return 9;
		break;
	}
	default:
		break;
	}
	return -1;
}

void Ship::Rastanovka(int _TempPalub)
{
	if (FlagAuto == 0)
	{
		system("cls");
		PrintBox();
		int _TempStroka;
		int _TempStolb;
		cout << "Введите строку для " << _TempPalub << "-палубного корабля: ";
		_TempStroka = InputAndConvert();
		cout << "Введите столбец для " << _TempPalub << "-палубного корабля: ";
		cin.ignore();
		cin >> _TempStolb;
		if (ProverkaInPut(_TempStroka, _TempStolb - 1))
		{
			if (SetUp(_TempStroka, _TempStolb - 1, _TempPalub) == 0)
				return Rastanovka(_TempPalub);
		}
		else
		{
			cout << "Не допустимое расположение!";
			return Rastanovka(_TempPalub);
		}
	}
	else if (FlagAuto == 1)
	{
		system("cls");	
		PrintBox();
		int _TempStroka;
		int _TempStolb;
		_TempStroka = AutoChoose();
		_TempStolb = AutoChoose();
		if (ProverkaInPut(_TempStroka, _TempStolb - 1))
		{
			if (SetUp(_TempStroka, _TempStolb - 1, _TempPalub) == 0)
				return Rastanovka(_TempPalub);
		}
		else
		{
			if (FlagAuto == 0)
			cout << "Не допустимое расположение!";
			return Rastanovka(_TempPalub);
		}
	}
	else
	{
		cout << "Error #1";
	}
}

void Ship::Ships()
{
	for (int i(0); i < 1; i++)
	{
		Rastanovka(4);
		if (FlagAuto == 1)
		{
			system("cls");
			PrintBox();
		}
	}
	for (int i(0); i < 2; i++)
	{
		Rastanovka(3);
		if (FlagAuto == 1)
		{
			system("cls");
			PrintBox();
		}
	}
	for (int i(0); i < 3; i++)
	{
		Rastanovka(2);
		if (FlagAuto == 1)
		{
			system("cls");
			PrintBox();
		}
	}
	for (int i(0); i < 4; i++)
	{
		Rastanovka(1);
		if (FlagAuto == 1)
		{
			system("cls");
			PrintBox();
		}
	}
}

void Ship::Copy()
{
	for (int i(0); i < 10; i++)
		for (int j(0); j < 10; j++)
			SaveKletka_1[i][j] = GetCaseFirstPlayer(i, j);
	for (int i(0); i < 10; i++)
		for (int j(0); j < 10; j++)
			SaveKletka_2[i][j] = GetCaseSecondPlayer(i, j);
}

int Ship::AutoChoose()
{
	return rand() % 9;
}

void Ship::Auto()
{
	srand(time(0));
	FlagAuto = 1;
	Ships();
}