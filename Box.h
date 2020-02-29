#ifndef BOX_H
#define BOX_H

class Box //Класс поля
{
private:
	char Kletka_1[9][9];//Строки/столбцы первого поля
	char Kletka_2[9][9];//Строки/столбцы второго поля
public:
	Box(); //Конструктор, очень желательно его не трогать
	void PrintBox(); //Распечатать нынешнее состояние полей
	void SetCaseFirstPlayer(int _Stroka, int _Stolb, char _Simvol);//Изменить значение клетки на первом поле на определенный символ
	char GetCaseFirstPlayer(int _Stroka, int _Stolb);//Получить значение клетки на первом поле
	void SetCaseSecondPlayer(int _Stroka, int _Stolb, char _Simvol);//Изменить значение клетки на втором поле на определенный символ
	char GetCaseSecondPlayer(int _Stroka, int _Stolb);//Получить значение клетки на втором поле
};
#endif
