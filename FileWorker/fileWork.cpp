#include <iostream>
#include <string.h>
#include <string>
#include <stdexcept>
#include <Windows.h>
#include <fstream>
#include <direct.h>
#include <stdio.h>
#include <io.h>
#include "fileWork.h"

using namespace std;

void fileWork::fileMenu()
{
		//записываем выбор пользователя в переменную
		char choice;
	do
	{
		system("cls");		
		cout << "\n Пожалуйста, выберите действие...\n\n";
		cout << " 1 - Создание файла\n";
		cout << " 2 - Удаление файла\n";
		cout << " 3 - Переименование файла\n";
		cout << " 4 - Копирование файла\n";
		cout << " 5 - Перемещение файла\n";
		cout << " 6 - Поиск по маске***\n";
		cout << "\n 0 - Выход\n ";
		//принимаем выбор пользователя
		cin >> choice;
		//анализируем выбор и вызываем соответсвующее действие
		switch (choice)
		{
		case '1':
			make();
			choice = '0';
			break;
		case '2':
			reMove();
			choice = '0';
			break;
		case '3':
			reName();
			choice = '0';
			break;
		case '4':
		{
			system("cls");
			char Src[MAX_PATH], Dest[MAX_PATH];
			cout << "Введите имя и путь к исходному файлу: ";
			cin >> Src;
			cout << "Введите имя и путь к файлу назначения: ";
			cin >> Dest;			
			coPy(Src, Dest);
			choice = '0';
		}
			break;
		case '5':
		{
			system("cls");
			char Src[MAX_PATH];
			char Dest[MAX_PATH];
			cout << "Введите имя и путь к исходному файлу: ";
			cin >> Src;
			cout << "Введите имя и путь к файлу назначения: ";
			cin >> Dest;
			moVe(Src, Dest);
			choice = '0';
		}
			break;
		case '6':
			searchMask();
			choice = '0';
			break;
		}
	} while (choice != '0');//выход из программы
}

void fileWork::make()
{
	system("cls");
	char name[MAX_PATH];	// Переменная для записи названия и пути файла.
	cout << "Введите имя и путь для создания файла: \n\n";
	cin >> name;
	ofstream out;
	out.open(name);
	if (!out.is_open())	// Проверка на открытие файла
	{
		cout << "Ошибка создания файла!\n\n";		
	}
	else
	{
	cout << "Файл успешно создан!\n\n";
	}
	out.close();
	system("pause");
}
void fileWork::reMove()
{
	system("cls");
	char name[MAX_PATH];	// 
	cout << "Введите имя и путь файла для удаления: ";
	cin >> name;
	if (remove(name))		//	
	{
		cout << "Ошибка! Невозможно удалить файл.\n\n";
		return;
	}
	else cout << "Файл успешно удалён!\n\n";
	system("pause");
}
void fileWork::reName()
{
	system("cls");
	char oldName[MAX_PATH], newName[MAX_PATH];
	//Получаем имя и путь к текущему имени директории и сохраняем в переменную oldName
	cout << "Введите текущее имя и путь файла: ";
	cin >> oldName;
	//Новое имя и путь директории и сохраняем в переменную newName
	cout << "Введите новое имя и путь файла: ";
	cin >> newName;
	//Производим переименование директории
	if (rename(oldName, newName) != 0)
		cout << "Ошибка! Невозможно переименовать файл.\n";
	else
		cout << "Файл успешно переименован!\n";
	system("pause");
}
void fileWork::coPy(const char* Src, const char* Dst)
{
	system("cls");
	ifstream in(Src, ios::in | ios::binary); // открываем существующий файл на чтение
	if (!in)
	{
		cout << " Невозможно открыть файл на чтение! \n";
		system("pause");
	}
	ofstream out(Dst, ios::out | ios::binary);  // создаём файл и открываем его на запись
	if (!out)
	{
		cout << " Невозможно открыть файл на запись! \n";
		system("pause");
	}
	out << in.rdbuf();  //Копируем информацию из вайла в файл
	in.close();			//Закрываем файл
	out.close();		//Закрываем файл
	cout << "Файл успешно скопирован!\n";
	system("pause");
}
void fileWork::moVe(const char* Src, const char* Dst)
{
	system("cls");
	ifstream in(Src, ios::in | ios::binary);     //Открываем исходный файл на чтение 
	if (!in)
	{
		cout << " Невозможно открыть файл на чтение! \n";
		system("pause");
	}
	ofstream out(Dst, ios::out | ios::binary);   //Открываем принимающий файл на запись
	if (!out)
	{
		cout << " Невозможно открыть файл на запись! \n";
		system("pause");
	}
	out << in.rdbuf();              //Копируем информацию из вайла в файл
	in.close();						//Закрываем файл
	out.close();					//Закрываем файл
	if (remove(Src))				//Удаляем исходный файл	
	{
		cout << "Ошибка! Невозможно удалить исходный файл.\n\n";
		return;
	}
	cout << "Файл успешно перемещён!\n";
	system("pause");
}
void fileWork::searchMask()
{
	system("cls");
	char Path[MAX_PATH];		// Запрос пути к файлу
	cout << "Введите путь к директории для поиска файлов: ";
	cin >> Path;
	char Mask[MAX_PATH];		// Запрос маски для поиска файла
	cout << "Введите маску для поиска файлов (например *.* или *.txt): ";
	cin >> Mask;
	char FullPath[MAX_PATH];	// Соединение пути и маски
	strcpy_s(FullPath, Path);	// Копирование
	strcat_s(FullPath, Mask);	// Добавление.
	_finddata_t* InfoFile = new _finddata_t;	// Создание объекта структуры, хранящей данные о файлах.
	long Done = _findfirst(FullPath, InfoFile);	// Поиск.
	int MayWeWork = Done;		// Переменная, чтобы в неё последующие поиски их результаты помещать.
	int Count = 0;				// Счетчик количества найденных файлов.
	while (MayWeWork != -1)
	{
		Count++;
		cout << InfoFile->name << endl;			// Вывод имени найденного файла.
		MayWeWork = _findnext(Done, InfoFile);	// Поиск следующего файла.
	}
	cout << "Было найдено " << Count << " файл(а/ов) в директории " << Path << " по маске: " << Mask << endl << endl;
	_findclose(Done);	//Освобождение памяти, выделеной под структуру finddata.
	system("pause");
	cout << endl;
	system("cls");
}
