#ifndef SHIP_H
#define SHIP_H

#include "Box.h"

using namespace std;
		
		//расположение кораблей

		class Ship : public Box 
		{
		private:int FlagAuto;
				char SaveKletka_1[9][9];
				char SaveKletka_2[9][9];
				bool ProverkaUp(int i, int j);
				bool ProverkaDown(int i, int j);
				bool ProverkaRight(int i, int j);
				bool ProverkaLeft(int i, int j);
				int InputAndConvert();//Конвертер буквенного ввода в численный
				bool ProverkaInPut(int i, int j);//Проверка ввода
		public: 
			Ship();//Конструктор
			int SetUp(int i, int j, int Palub);//Функция принимающая координаты и задействующая их для проверки
			void Rastanovka(int _TempPalub);//Сам процесс расстановки
			void Ships();
			void Copy();
			int AutoChoose();
			void Auto();
			//Правила расстановки кораблей
		};
	
#endif