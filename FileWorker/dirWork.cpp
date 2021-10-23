#include <iostream>
#include <Windows.h>
#include <direct.h>
#include <stdio.h>
#include <io.h>
#include "dirWork.h"

using namespace std;

void dirWork::dirMenu()
{
	system("cls");
	//предлагаем пользователю выбрать действие
	cout << "\n Пожалуйста, выберите действие...\n";
	//записываем выбор пользователя в переменную
	char choice;
	do
	{
		//создать папку или файл
		cout << "\n 1 - Создание директории\n";
		//удалить папку или файл
		cout << " 2 - Удаление директории\n";
		//переименовать папку или файл
		cout << " 3 - Переименование директории\n";
		//копировать/перенести папку или файл
		cout << " 4 - Копирование директории\n";
		//вычислить размер папки или файла
		cout << " 5 - Перенос директории\n";
		//просмотр содержимого дисков
		cout << " 6 - Просмотр содержимого директории\n";
		//выход из программы
		cout << "\n 0 - Выход\n";
		//принимаем выбор пользователя
		cin >> choice;
		//анализируем выбор и вызываем соответсвующее действие
		switch (choice)
		{
		case '1':
			make();
			break;
		case '2':
			reMove();
			break;
		case '3':
			reName();
			break;
		case '4':
			system("cls");
			char Source[MAX_PATH];
			char Destination[MAX_PATH];
			cout << "Введите имя и путь к копируемой директории: ";
			cin.getline(Source, MAX_PATH);
			cout << "Введите имя и путь к директории назначения: ";
			cin.getline(Destination, MAX_PATH);
			coPy(Source, Destination);
			//Copy_Directory(Source, Destination);
			//cout << "Скопировано: " << CountDir << " папка(и) и " << CountFile << " файл(а)!" << endl << endl;
			system("pause");
			cout << endl;
			system("cls");
			break;
		case '5':
			//moVe();
			break;
		case '6':
			break;
		}
	} while (choice != '0');//выход из программы
}

void dirWork::make()
{
	system("cls");
	char name[MAX_PATH];
	//Получаем имя и путь к создаваемой директории
	cout << "Введите имя создаваемой директории:";
	cin >> name;
	//Создаем директорию и проверяем результат
	if (_mkdir(name) == -1)
		cout << "Ошибка! Невозможно создать директорию.\n";
	else
		cout << "Ok...\n";
}
void dirWork::reMove()
{
	system("cls");
	char name[MAX_PATH];
	//Получаем имя и путь к удаляемой директории
	cout << "Введите имя директории:";
	cin >> name;
	//Удаляем директорию и проверяем результат
	if (_rmdir(name) == -1)
		cout << "Ошибка! Невозможно удалить директорию.\n";
	else
		cout << "Ok...\n";
}
void dirWork::reName()
{
	system("cls");
	char oldName[MAX_PATH], newName[MAX_PATH];
	//Получаем имя и путь к текущему имени директории и сохраняем в переменную oldName
	cout << "Введите текущее имя директории и путь:";
	cin >> oldName;
	//Новое имя и путь директории и сохраняем в переменную newName
	cout << "Введите новое имя директории и путь:";
	cin >> newName;
	//Производим переименование директории
	if (rename(oldName, newName) != 0)
		cout << "Ошибка! Невозможно переименовать директорию.\n";
	else
		cout << "Ok...\n";
}
void dirWork::coPy(const char* Source, const char* Destination)
{

}

void dirWork::moVe(const char* Source, const char* Destination)
{
}
