#include <iostream>
#include "Box.h"

using namespace std;

Box::Box()
{
	for (int i(0); i < 10; i++)
		for (int j(0); j < 10; j++)
			Kletka_1[i][j] = '-';
	for (int i(0); i < 10; i++)
		for (int j(0); j < 10; j++)
			Kletka_2[i][j] = '-';
}

void Box::PrintBox()
{
	setlocale(LC_ALL, "rus");
	cout << "\t\t\t\t      ћорской Ѕой" << endl;
	cout << " |-1-|-2-|-3-|-4-|-5-|-6-|-7-|-8-|-9-|10-|\t\t |-1-|-2-|-3-|-4-|-5-|-6-|-7-|-8-|-9-|10-|" << endl;
	cout << "a|-" << Kletka_1[0][0] << "-|-" << Kletka_1[0][1] << "-|-" << Kletka_1[0][2] << "-|-" << Kletka_1[0][3] << "-|-" << Kletka_1[0][4] << "-|-" << Kletka_1[0][5] << "-|-" << Kletka_1[0][6] << "-|-" << Kletka_1[0][7] << "-|-" << Kletka_1[0][8] << "-|-" << Kletka_1[0][9] << "-|\t\ta|-" << Kletka_2[0][0] << "-|-" << Kletka_2[0][1] << "-|-" << Kletka_2[0][2] << "-|-" << Kletka_2[0][3] << "-|-" << Kletka_2[0][4] << "-|-" << Kletka_2[0][5] << "-|-" << Kletka_2[0][6] << "-|-" << Kletka_2[0][7] << "-|-" << Kletka_2[0][8] << "-|-" << Kletka_2[0][9] << "-|" << endl;
	cout << "b|-" << Kletka_1[1][0] << "-|-" << Kletka_1[1][1] << "-|-" << Kletka_1[1][2] << "-|-" << Kletka_1[1][3] << "-|-" << Kletka_1[1][4] << "-|-" << Kletka_1[1][5] << "-|-" << Kletka_1[1][6] << "-|-" << Kletka_1[1][7] << "-|-" << Kletka_1[1][8] << "-|-" << Kletka_1[1][9] << "-|\t\tb|-" << Kletka_2[1][0] << "-|-" << Kletka_2[1][1] << "-|-" << Kletka_2[1][2] << "-|-" << Kletka_2[1][3] << "-|-" << Kletka_2[1][4] << "-|-" << Kletka_2[1][5] << "-|-" << Kletka_2[1][6] << "-|-" << Kletka_2[1][7] << "-|-" << Kletka_2[1][8] << "-|-" << Kletka_2[1][9] << "-|" << endl;
	cout << "c|-" << Kletka_1[2][0] << "-|-" << Kletka_1[2][1] << "-|-" << Kletka_1[2][2] << "-|-" << Kletka_1[2][3] << "-|-" << Kletka_1[2][4] << "-|-" << Kletka_1[2][5] << "-|-" << Kletka_1[2][6] << "-|-" << Kletka_1[2][7] << "-|-" << Kletka_1[2][8] << "-|-" << Kletka_1[2][9] << "-|\t\tc|-" << Kletka_2[2][0] << "-|-" << Kletka_2[2][1] << "-|-" << Kletka_2[2][2] << "-|-" << Kletka_2[2][3] << "-|-" << Kletka_2[2][4] << "-|-" << Kletka_2[2][5] << "-|-" << Kletka_2[2][6] << "-|-" << Kletka_2[2][7] << "-|-" << Kletka_2[2][8] << "-|-" << Kletka_2[2][9] << "-|" << endl;
	cout << "d|-" << Kletka_1[3][0] << "-|-" << Kletka_1[3][1] << "-|-" << Kletka_1[3][2] << "-|-" << Kletka_1[3][3] << "-|-" << Kletka_1[3][4] << "-|-" << Kletka_1[3][5] << "-|-" << Kletka_1[3][6] << "-|-" << Kletka_1[3][7] << "-|-" << Kletka_1[3][8] << "-|-" << Kletka_1[3][9] << "-|\t\td|-" << Kletka_2[3][0] << "-|-" << Kletka_2[3][1] << "-|-" << Kletka_2[3][2] << "-|-" << Kletka_2[3][3] << "-|-" << Kletka_2[3][4] << "-|-" << Kletka_2[3][5] << "-|-" << Kletka_2[3][6] << "-|-" << Kletka_2[3][7] << "-|-" << Kletka_2[3][8] << "-|-" << Kletka_2[3][9] << "-|" << endl;
	cout << "e|-" << Kletka_1[4][0] << "-|-" << Kletka_1[4][1] << "-|-" << Kletka_1[4][2] << "-|-" << Kletka_1[4][3] << "-|-" << Kletka_1[4][4] << "-|-" << Kletka_1[4][5] << "-|-" << Kletka_1[4][6] << "-|-" << Kletka_1[4][7] << "-|-" << Kletka_1[4][8] << "-|-" << Kletka_1[4][9] << "-|\t\te|-" << Kletka_2[4][0] << "-|-" << Kletka_2[4][1] << "-|-" << Kletka_2[4][2] << "-|-" << Kletka_2[4][3] << "-|-" << Kletka_2[4][4] << "-|-" << Kletka_2[4][5] << "-|-" << Kletka_2[4][6] << "-|-" << Kletka_2[4][7] << "-|-" << Kletka_2[4][8] << "-|-" << Kletka_2[4][9] << "-|" << endl;
	cout << "f|-" << Kletka_1[5][0] << "-|-" << Kletka_1[5][1] << "-|-" << Kletka_1[5][2] << "-|-" << Kletka_1[5][3] << "-|-" << Kletka_1[5][4] << "-|-" << Kletka_1[5][5] << "-|-" << Kletka_1[5][6] << "-|-" << Kletka_1[5][7] << "-|-" << Kletka_1[5][8] << "-|-" << Kletka_1[5][9] << "-|\t\tf|-" << Kletka_2[5][0] << "-|-" << Kletka_2[5][1] << "-|-" << Kletka_2[5][2] << "-|-" << Kletka_2[5][3] << "-|-" << Kletka_2[5][4] << "-|-" << Kletka_2[5][5] << "-|-" << Kletka_2[5][6] << "-|-" << Kletka_2[5][7] << "-|-" << Kletka_2[5][8] << "-|-" << Kletka_2[5][9] << "-|" << endl;
	cout << "g|-" << Kletka_1[6][0] << "-|-" << Kletka_1[6][1] << "-|-" << Kletka_1[6][2] << "-|-" << Kletka_1[6][3] << "-|-" << Kletka_1[6][4] << "-|-" << Kletka_1[6][5] << "-|-" << Kletka_1[6][6] << "-|-" << Kletka_1[6][7] << "-|-" << Kletka_1[6][8] << "-|-" << Kletka_1[6][9] << "-|\t\tg|-" << Kletka_2[6][0] << "-|-" << Kletka_2[6][1] << "-|-" << Kletka_2[6][2] << "-|-" << Kletka_2[6][3] << "-|-" << Kletka_2[6][4] << "-|-" << Kletka_2[6][5] << "-|-" << Kletka_2[6][6] << "-|-" << Kletka_2[6][7] << "-|-" << Kletka_2[6][8] << "-|-" << Kletka_2[6][9] << "-|" << endl;
	cout << "h|-" << Kletka_1[7][0] << "-|-" << Kletka_1[7][1] << "-|-" << Kletka_1[7][2] << "-|-" << Kletka_1[7][3] << "-|-" << Kletka_1[7][4] << "-|-" << Kletka_1[7][5] << "-|-" << Kletka_1[7][6] << "-|-" << Kletka_1[7][7] << "-|-" << Kletka_1[7][8] << "-|-" << Kletka_1[7][9] << "-|\t\th|-" << Kletka_2[7][0] << "-|-" << Kletka_2[7][1] << "-|-" << Kletka_2[7][2] << "-|-" << Kletka_2[7][3] << "-|-" << Kletka_2[7][4] << "-|-" << Kletka_2[7][5] << "-|-" << Kletka_2[7][6] << "-|-" << Kletka_2[7][7] << "-|-" << Kletka_2[7][8] << "-|-" << Kletka_2[7][9] << "-|" << endl;
	cout << "i|-" << Kletka_1[8][0] << "-|-" << Kletka_1[8][1] << "-|-" << Kletka_1[8][2] << "-|-" << Kletka_1[8][3] << "-|-" << Kletka_1[8][4] << "-|-" << Kletka_1[8][5] << "-|-" << Kletka_1[8][6] << "-|-" << Kletka_1[8][7] << "-|-" << Kletka_1[8][8] << "-|-" << Kletka_1[8][9] << "-|\t\ti|-" << Kletka_2[8][0] << "-|-" << Kletka_2[8][1] << "-|-" << Kletka_2[8][2] << "-|-" << Kletka_2[8][3] << "-|-" << Kletka_2[8][4] << "-|-" << Kletka_2[8][5] << "-|-" << Kletka_2[8][6] << "-|-" << Kletka_2[8][7] << "-|-" << Kletka_2[8][8] << "-|-" << Kletka_2[8][9] << "-|" << endl;
	cout << "j|-" << Kletka_1[9][0] << "-|-" << Kletka_1[9][1] << "-|-" << Kletka_1[9][2] << "-|-" << Kletka_1[9][3] << "-|-" << Kletka_1[9][4] << "-|-" << Kletka_1[9][5] << "-|-" << Kletka_1[9][6] << "-|-" << Kletka_1[9][7] << "-|-" << Kletka_1[9][8] << "-|-" << Kletka_1[9][9] << "-|\t\ti|-" << Kletka_2[9][0] << "-|-" << Kletka_2[9][1] << "-|-" << Kletka_2[9][2] << "-|-" << Kletka_2[9][3] << "-|-" << Kletka_2[9][4] << "-|-" << Kletka_2[9][5] << "-|-" << Kletka_2[9][6] << "-|-" << Kletka_2[9][7] << "-|-" << Kletka_2[9][8] << "-|-" << Kletka_2[9][9] << "-|" << endl;
}

void Box::SetCaseFirstPlayer(int _Stroka, int _Stolb, char _Simvol)
{
	if (_Stroka < 0 || _Stroka > 9 || _Stolb < 0 || _Stolb > 9)
		cout << "ќшибка, данной €чейки не существует." << endl;
	else
	Kletka_1[_Stroka][_Stolb] = _Simvol;
}

char Box::GetCaseFirstPlayer(int _Stroka, int _Stolb)
{
	if (_Stroka < 0 || _Stroka > 9 || _Stolb < 0 || _Stolb > 9)
		cout << "ќшибка, данной €чейки не существует." << endl;
	else
	return Kletka_1[_Stroka][_Stolb];
	return '\0';
}
void Box::SetCaseSecondPlayer(int _Stroka, int _Stolb, char _Simvol)
{
	if (_Stroka < 0 || _Stroka > 9 || _Stolb < 0 || _Stolb > 9)
		cout << "ќшибка, данной €чейки не существует." << endl;
	else
	Kletka_1[_Stroka][_Stolb] = _Simvol;
}

char Box::GetCaseSecondPlayer(int _Stroka, int _Stolb)
{
	if (_Stroka < 0 || _Stroka > 9 || _Stolb < 0 || _Stolb > 9)
		cout << "ќшибка, данной €чейки не существует." << endl;
	else
	return Kletka_2[_Stroka][_Stolb];
	return '\0';
}