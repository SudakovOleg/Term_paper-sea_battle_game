#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>
#include "Box.h"
#include "Ship.h"

using namespace std;

Ship::Ship()//����������� ����������� ������� ������ "-"
{
	for (int i(0); i < 9; i++)
		for (int j(0); j < 9; j++)
			SaveKletka_1[i][j] = GetCaseFirstPlayer(i, j);
	for (int i(0); i < 9; i++)
		for (int j(0); j < 9; j++)
			SaveKletka_2[i][j] = GetCaseSecondPlayer(i,j);
	FlagAuto = 0;
}

bool Ship::ProverkaUp(int i, int j) //�������� �����
{
	if (i == 0)//�������� ������� �������
	{
					return 0;
	}
	else if (j == 0)//�������� ����� �������
	{
		if (i == 9)//�������� ����� ������ ����
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
				if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
						return 1;
		}
		if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
			if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
				if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
					return 1;
	}
	else if (i == 9) //������ �������
	{
		if (j == 9) //����� ������ ����
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
				if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
						return 1;
		}
		if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
			if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
				if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
						if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
							return 1;
	}
	else if (j == 9) //�������� ������ �������
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
			if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
				if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
					if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //�������� ����� �����
						return 1;
	}
	else
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
			if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
				if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
						if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
							if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
								if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //�������� ����� �����
									return 1;
	}
	return 0;

}


bool Ship::ProverkaDown(int i, int j)//�������� ������ �������
{
	if (i == 9) //������ �������
		return 0;
	else if (i == 0)//�������� ������� �������
	{
		if (j == 0)//�������� ����� �������
		{
			if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
				if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
					return 1;
		}
		else if (j == 9)  //�������� ������ �������
		{
			if (GetCaseFirstPlayer(i + 1, j) == '-')
				if (GetCaseFirstPlayer(i, j - 1) == '-')
					return 1;
		}
		if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
			if (GetCaseFirstPlayer(i, j - 1) == '-') //�����
				if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //�������� ����� �����
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
						return 1;
	}
	else if (j == 0)// ����� �������
	{
		if (GetCaseFirstPlayer(i + 1, j) == '-') //�������� �����
			if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
				if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
					return 1;
	}
	else if (j == 9)//������ �������
	{
		if (GetCaseFirstPlayer(i + 1, j) == '-') //�������� �����
			if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
				if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
					if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //�������� ����� �����
						return 1;
	}
	else
	{
		if (GetCaseFirstPlayer(i + 1, j) == '-') //�������� �����
			if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
				if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
						if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
							if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
								if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //�������� ����� �����
									return 1;
	}
	return 0;
}

bool Ship::ProverkaRight(int i, int j) //�������� ������
{
	if (j == 9)//�������� ������ �������
		return 0;
	else if (i == 0)//� ������ ������������ � ������� �������
	{
		if (j == 0)//� ����� �������
		{
			if (GetCaseFirstPlayer(i + 1, j) == '-') //��������  �����
				if (GetCaseFirstPlayer(i, j + 1) == '-') // �������� ������
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
						return 1;
		}
		if (GetCaseFirstPlayer(i + 1, j) == '-') //��������  �����
			if (GetCaseFirstPlayer(i, j + 1) == '-') // �������� ������
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
						if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //�������� ����� �����
							return 1;
	}
	else if (j == 0)//���� � ����� �������
	{
		if (i == 9)//� ������ ������
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') // �������� �����
				if (GetCaseFirstPlayer(i, j + 1) == '-') // �������� ������
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
					return 1;
		}//������ � ����� �������
		if (GetCaseFirstPlayer(i + 1, j) == '-') // �������� �����
			if (GetCaseFirstPlayer(i - 1, j) == '-') // �������� ������
				if (GetCaseFirstPlayer(i, j + 1) == '-') // �������� ������
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
						if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
							return 1;
	}
	else if (i == 9)//������ ������ ������
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') // �������� ������
			if (GetCaseFirstPlayer(i, j + 1) == '-') // �������� ������
				if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
					return 1;
	}
	else //�����
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
			if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
				if (GetCaseFirstPlayer(i + 1, j) == '-') // �������� �����
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
						if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
							if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
								if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //�������� ����� �����
									return 1;
	}
	return 0;
}

bool Ship::ProverkaLeft(int i, int j)//�������� �����
{
	if (j == 0)//����� �������
		return 0;
	else if (j == 9)//������ �������
	{
		if (i == 0)//������� �������
		{
			if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
				if (GetCaseFirstPlayer(i + 1, j) == '-')//�������� ����� 
					if (GetCaseFirstPlayer(i + 1, j - 1) == '-')//�������� ����� �����
						return 1;
		}
		if (i == 9)//������ ������
		{
			if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
				if (GetCaseFirstPlayer(i - 1, j) == '-')//�������� ������
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-')//�������� ������ �����
						return 1;
		}
		if (GetCaseFirstPlayer(i + 1, j) == '-')//�������� �����
			if (GetCaseFirstPlayer(i, j - 1) == '-')//�������� �����
				if (GetCaseFirstPlayer(i - 1 , j) == '-')//�������� ������
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-')//�������� ������ �����
						if (GetCaseFirstPlayer(i + 1, j - 1) == '-')//�������� ����� �����
							return 1;
	}
	else if (i == 0)//������� �������
	{
		if (GetCaseFirstPlayer(i, j - 1) == '-')//�������� �����
			if (GetCaseFirstPlayer(i + 1, j - 1) == '-')//�������� ����� �����
				if (GetCaseFirstPlayer(i + 1, j) == '-')//�������� �����
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-')//�������� ����� ������
						return 1;
	}
	else if(i == 9)//������ �������
	{
		if (GetCaseFirstPlayer(i, j - 1) == '-')//�������� �����
			if (GetCaseFirstPlayer(i - 1, j - 1) == '-')//�������� ������ �����
				if (GetCaseFirstPlayer(i - 1, j) == '-')//�������� ������
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-')//�������� ������ ������
						return 1;
	}
	else//�����
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
			if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
				if (GetCaseFirstPlayer(i + 1, j) == '-') // �������� �����
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
						if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
							if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
								if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //�������� ����� �����
									return 1;
	}
	return 0;
}

int Ship::SetUp(int i, int j, int Palub)
{
	setlocale(LC_ALL, "rus");
	ProverkaInPut(i, j);
	SetCaseFirstPlayer(i,j,'0');//����������� ������ ������ (����)
	if (FlagAuto == 0)
	PrintBox();//������ ����
	//_getch();
	if (Palub == 1)
		return 1;
	else
	{
		int _TempForSwitch;
		if (FlagAuto == 0)
		{
			system("cls");//������� ������
			cout << "�������� ��������� ��������: " << endl;
			cout << "1. �����" << endl;
			cout << "2. ������" << endl;
			cout << "3. �����" << endl;
			cout << "4. ������" << endl;
		}
		if (FlagAuto == 0)
		{
			do
			{
				cin >> _TempForSwitch;//�������� �������� ����
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
			int Temp = Palub;//���������� ��� �������� ���-�� ��� ������������� ����� ��� ������������ ��������
			int TempI[5] = { 0 }; //���������� ��� �������� ������ ��� ������������� �����
			for (int t(0); t < Palub; t++)
				if (ProverkaLeft(i, j - t))//�������� ���������� � ��������� ������ � �������� ��������
				{
					Temp--;
					SetCaseFirstPlayer(i, j - t, '0');;
					TempI[t] = j - t;
					system("cls");
					//if (FlagAuto == 0)
					PrintBox();
					_getch();
				}
				else //�������� � ������ �� ������ �����
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
			int Temp = Palub;//���������� ��� �������� ���-�� ��� ������������� ����� ��� ������������ ��������
			int TempI[5] = { 0 }; //���������� ��� �������� ������ ��� ������������� �����
			for (int t(0); t < Palub; t++)
				if (ProverkaRight(i, j + t))//�������� ���������� � ��������� ������ � �������� ��������
				{
					Temp--;
					SetCaseFirstPlayer(i, j + t, '0');;
					TempI[t] = j + t;
					system("cls");
					//if (FlagAuto == 0)
					PrintBox();
					_getch();
				}
				else //�������� � ������ �� ������ �����
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
			int Temp = Palub;//���������� ��� �������� ���-�� ��� ������������� ����� ��� ������������ ��������
			int TempI[5] = { 0 }; //���������� ��� �������� ������ ��� ������������� �����
			for (int t(0); t < Palub; t++)
				if (ProverkaDown(i + t, j))//�������� ���������� � ��������� ������ � �������� ��������
				{
					Temp--;
					SetCaseFirstPlayer(i + t, j, '0');;
					TempI[t] = i + t;
					system("cls");
					//if (FlagAuto == 0)
					PrintBox();
					_getch();
				}
				else //�������� � ������ �� ������ �����
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
			int Temp = Palub;//���������� ��� �������� ���-�� ��� ������������� ����� ��� ������������ ��������
			int TempI[5] = { 0 }; //���������� ��� �������� ������ ��� ������������� �����
			for (int t(0); t < Palub; t++)
				if (ProverkaUp(i - t, j))//�������� ���������� � ��������� ������ � �������� ��������
				{
					Temp--;
					SetCaseFirstPlayer(i - t, j, '0');;
					TempI[t] = i - t;
					system("cls");
					//if (FlagAuto == 0)
					PrintBox();
					_getch();
				}
				else //�������� � ������ �� ������ �����
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
	if (i == 0)// ������� ������
	{
		if (j == 0)//����� �������
		{
			if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
				if (GetCaseFirstPlayer(i + 1, j) == '-')//�������� ����� 
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-')//�������� ����� ������
					return 1;
		}
		if (j == 9)
		{
			if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
				if (GetCaseFirstPlayer(i + 1, j) == '-')//�������� ����� 
					if (GetCaseFirstPlayer(i + 1, j - 1) == '-')//�������� ����� �����
					return 1;
		}
		if (GetCaseFirstPlayer(i + 1, j) == '-')
			if (GetCaseFirstPlayer(i, j + 1) == '-')
				if (GetCaseFirstPlayer(i, j - 1) == '-')
					if (GetCaseFirstPlayer(i + 1, j + 1) == '-')
						if (GetCaseFirstPlayer(i + 1, j - 1) == '-')
				return 1;
	}
	else if (i == 9) //������ �����
	{
		if (j == 0) //�����
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') // �������� �����
				if (GetCaseFirstPlayer(i, j + 1) == '-') // �������� ������
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
						return 1;
		}
		else if( j == 9)
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
				if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
						return 1;
		}
		else
		{
			if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
				if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� ������
					if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
						if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
							if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
								return 1;
		}
	}
	else if(j == 0)
	{
		if (GetCaseFirstPlayer(i + 1, j) == '-') // �������� �����
			if (GetCaseFirstPlayer(i - 1, j) == '-') // �������� ������
				if (GetCaseFirstPlayer(i, j + 1) == '-') // �������� ������
					if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
						if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
							return 1;
	}
	else if (j == 9)
	{
		if (GetCaseFirstPlayer(i + 1, j) == '-')//�������� �����
			if (GetCaseFirstPlayer(i, j - 1) == '-')//�������� �����
				if (GetCaseFirstPlayer(i - 1, j) == '-')//�������� ������
					if (GetCaseFirstPlayer(i - 1, j - 1) == '-')//�������� ������ �����
						if (GetCaseFirstPlayer(i + 1, j - 1) == '-')//�������� ����� �����
							return 1;
	}
	else
	{
		if (GetCaseFirstPlayer(i - 1, j) == '-') //�������� ������
			if (GetCaseFirstPlayer(i, j - 1) == '-') //�������� �����
				if (GetCaseFirstPlayer(i, j + 1) == '-') //�������� �����
					if (GetCaseFirstPlayer(i + 1, j) == '-') // �������� �����
						if (GetCaseFirstPlayer(i - 1, j - 1) == '-') //�������� ������ �����
							if (GetCaseFirstPlayer(i - 1, j + 1) == '-') //�������� ������ ������
								if (GetCaseFirstPlayer(i + 1, j + 1) == '-') //�������� ����� ������
									if (GetCaseFirstPlayer(i + 1, j - 1) == '-') //�������� ����� �����
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
		cout << "�������� ������";
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
		cout << "������� ������ ��� " << _TempPalub << "-��������� �������: ";
		_TempStroka = InputAndConvert();
		cout << "������� ������� ��� " << _TempPalub << "-��������� �������: ";
		cin.ignore();
		cin >> _TempStolb;
		if (ProverkaInPut(_TempStroka, _TempStolb - 1))
		{
			if (SetUp(_TempStroka, _TempStolb - 1, _TempPalub) == 0)
				return Rastanovka(_TempPalub);
		}
		else
		{
			cout << "�� ���������� ������������!";
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
			cout << "�� ���������� ������������!";
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