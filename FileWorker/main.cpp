#include <iostream>
#include "entrance.h"
#include "dirWork.h"
#include "fileWork.h"

using namespace std;

void inPut();
void main()
{
	setlocale(LC_ALL, "Russian");
	
	inPut();
}

void inPut()
{
	//записываем выбор пользователя в переменную
	char choice;
	do
	{
	system("cls");
	cout << "Пожалуйста, выберите действие...\n";
		cout << "\n 1 - Работа с файлами\n";
		cout << " 2 - Работа с директориями\n";
		cout << "\n 0 - Выход\n ";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{fileWork fW;
		fW.fileMenu(); }
			break;
		case '2':
		{dirWork dW;
		dW.dirMenu(); }
			break;
		}
	} while (choice != '0');//выход из программы		
}