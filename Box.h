#ifndef BOX_H
#define BOX_H

class Box //����� ����
{
private:
	char Kletka_1[9][9];//������/������� ������� ����
	char Kletka_2[9][9];//������/������� ������� ����
public:
	Box(); //�����������, ����� ���������� ��� �� �������
	void PrintBox(); //����������� �������� ��������� �����
	void SetCaseFirstPlayer(int _Stroka, int _Stolb, char _Simvol);//�������� �������� ������ �� ������ ���� �� ������������ ������
	char GetCaseFirstPlayer(int _Stroka, int _Stolb);//�������� �������� ������ �� ������ ����
	void SetCaseSecondPlayer(int _Stroka, int _Stolb, char _Simvol);//�������� �������� ������ �� ������ ���� �� ������������ ������
	char GetCaseSecondPlayer(int _Stroka, int _Stolb);//�������� �������� ������ �� ������ ����
};
#endif
