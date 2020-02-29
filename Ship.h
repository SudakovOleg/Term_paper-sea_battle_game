#ifndef SHIP_H
#define SHIP_H

#include "Box.h"

using namespace std;
		
		//������������ ��������

		class Ship : public Box 
		{
		private:int FlagAuto;
				char SaveKletka_1[9][9];
				char SaveKletka_2[9][9];
				bool ProverkaUp(int i, int j);
				bool ProverkaDown(int i, int j);
				bool ProverkaRight(int i, int j);
				bool ProverkaLeft(int i, int j);
				int InputAndConvert();//��������� ���������� ����� � ���������
				bool ProverkaInPut(int i, int j);//�������� �����
		public: 
			Ship();//�����������
			int SetUp(int i, int j, int Palub);//������� ����������� ���������� � ������������� �� ��� ��������
			void Rastanovka(int _TempPalub);//��� ������� �����������
			void Ships();
			void Copy();
			int AutoChoose();
			void Auto();
			//������� ����������� ��������
		};
	
#endif