#include <iostream>
#include <Windows.h>
#include <direct.h>
#include <stdio.h>
#include <io.h>
#include "fileWork.h"

using namespace std;

void fileWork::fileMenu()
{
	system("cls");
	//предлагаем пользователю выбрать действие
	cout << "\n Пожалуйста, выберите действие...\n";
	//записываем выбор пользователя в переменную
	char choice;
	do
	{
		//создать папку или файл
		cout << "\n 1 - Создание файла\n";
		//удалить папку или файл
		cout << " 2 - Удаление файла\n";
		//переименовать папку или файл
		cout << " 3 - Переименование файла\n";
		//копировать/перенести папку или файл
		cout << " 4 - Копирование файла\n";
		//вычислить размер папки или файла
		cout << " 5 - Перемещение файла\n";
		//поиск по маске
		cout << " 6 - Поиск по маске\n";
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
		{
			system("cls");
			char Source[MAX_PATH];
			char Destination[MAX_PATH];
			cout << "Введите имя и путь к исходному файлу: ";
			cin >> Source;
			cout << "Введите имя и путь к файлу назначения: ";
			cin >> Destination;			
			coPy(Source, Destination);
			cout << "Файл успешно скопирован!\n\n";
			system("pause");
			cout << endl;
		}
			break;
		case '5':
		{
			system("cls");
			char Source[MAX_PATH];
			char Destination[MAX_PATH];
			cout << "Введите имя и путь к исходному файлу: ";
			cin >> Source;
			cout << "Введите имя и путь к файлу назначения: ";
			cin >> Destination;
			moVe(Source, Destination);
		}
			break;
		case '6':
			break;
		case '7':
			break;
		}
	} while (choice != '0');//выход из программы
}

void fileWork::make()
{
	system("cls");
	char name[MAX_PATH];	// define MAX_PATH - максимальный путь 260 символов.
	cout << "Введите имя для создания файла с указаннием пути: ";
	cin >> name;
	FILE* check;
	if (!fopen_s(&check, name, "r") != 0)	// Ïîïûòêà îòêðûòü ôàéë íà ÷òåíèå.
	{
		cout << "Файл с таким именем уже существует!\n\n";
		fclose(check);
		return;
	}
	fopen_s(&check, name, "w");	// Îòêðûòèå ôàéëà íà çàïèñü (ñîçäàíèå).
	if (!check)	// Åñëè óêàçàòåëü íà ôàéë íóëåâîé.
	{
		cout << "Ошибка создания файла!" << endl << endl;
		return;
	}
	cout << "Файл успешно создан!" << endl << endl;
	fclose(check);
	system("pause");
	cout << endl;
	system("cls");
}
void fileWork::reMove()
{
	system("cls");
	char name[MAX_PATH];	// Òåêóùåå è íîâîå èìÿ ôàéëà.
	cout << "Введите имя и путь файла для удаления: ";
	cin >> name;
	if (remove(name))		//	Óäàëèòü ôàéë è ïðîâåðèòü ðåçóëüòàò
	{
		cout << "Ошибка! Невозможно переименовать файл.\n\n";
		return;
	}
	else cout << "Ok...\n\n";
	system("pause");
	cout << endl;
	system("cls");
}
void fileWork::reName()
{
	system("cls");
	char oldName[MAX_PATH], newName[MAX_PATH];
	//Получаем имя и путь к текущему имени директории и сохраняем в переменную oldName
	cout << "Введите текущее имя и путь файла:";
	cin >> oldName;
	//Новое имя и путь директории и сохраняем в переменную newName
	cout << "Введите новое имя и путь файла:";
	cin >> newName;
	//Производим переименование директории
	if (rename(oldName, newName) != 0)
		cout << "Ошибка! Невозможно переименовать файл.\n";
	else
		cout << "Ok...\n";
}
void fileWork::coPy(const char* Source, const char* Destination)
{
	// Указатели на файлы:
	FILE* Src, * Dest;
	// Открытие оригинального файла в бинарном(двоичном) режиме на чтение.
	if (fopen_s(&Src, Source, "rb") != 0)
	{
		cout << "Файл не найден! Проверьте имя и путь к файлу!" << endl << endl;
		return;
	}
	int hSrc = _fileno(Src);		// Получить дискриптор файла.
	int Size = _filelength(hSrc);	// Определить размер файла.
	char* Data = new char[Size];	// Выделить память под буфер для копирования содержимого файла.
	if (!Data)
	{
		cout << "Ошибка выделения памяти, при создании буфера для копирования файла!" << endl << endl;
		fclose(Src);
		return;
	}
	if (fopen_s(&Dest, Destination, "wb") != 0)	// Îòêðûâòèå ôàéëà íàçíà÷åíèÿ, â áèíàðíîì ðåæèìå íà çàïèñü.
	{
		cout << "Ошибка копирования файла! Проверьте имя и путь назначения!" << endl << endl;
		fclose(Src);
		delete[] Data;
		return;
	}
	int DataValue;		// Объем данных.
	// Считать данные:
	while (!feof(Src))	// Пока н до ли до конца ис одно о файла.
	{
		// Считать данные в строку Data, подсчитывая объем данных в строке и помещая его в DataValue
		DataValue = fread(Data, sizeof(char), Size, Src);			// fread работает в бинарном режиме.
		if (DataValue)fwrite(Data, sizeof(char), DataValue, Dest);	// Записать строку в файл назначения.
		else break;	// Если закончились данные заканчиваем запись.
	}
	// Закрыть файлы:
	fclose(Src);
	fclose(Dest);
	// Освобождение памяти, выделенную под буфер.
	delete[] Data;
}

void fileWork::moVe(const char* Source, const char* Destination)
{
	// Указатели на файлы:
	FILE* Src, * Dest;
	// Открытие оригинального файла в бинарном(двоичном) режиме на чтение.
	if (fopen_s(&Src, Source, "rb") != 0)
	{
		cout << "Файл не найден! Проверьте имя и путь к файлу!" << endl << endl;
		return;
	}
	int hSrc = _fileno(Src);		// Получить дискриптор файла.
	int Size = _filelength(hSrc);	// Определить размер файла.
	char* Data = new char[Size];	// Выделить память под буфер для копирования содержимого файла.
	if (!Data)
	{
		cout << "Ошибка выделения памяти, при создании буфера для копирования файла!" << endl << endl;
		fclose(Src);
		return;
	}
	if (fopen_s(&Dest, Destination, "wb") != 0)	// Îòêðûâòèå ôàéëà íàçíà÷åíèÿ, â áèíàðíîì ðåæèìå íà çàïèñü.
	{
		cout << "Ошибка копирования файла! Проверьте имя и путь назначения!" << endl << endl;
		fclose(Src);
		delete[] Data;
		return;
	}
	int DataValue;		// Объем данных.
	// Считать данные:
	while (!feof(Src))	// Пока н до ли до конца ис одно о файла.
	{
		// Считать данные в строку Data, подсчитывая объем данных в строке и помещая его в DataValue
		DataValue = fread(Data, sizeof(char), Size, Src);			// fread работает в бинарном режиме.
		if (DataValue)fwrite(Data, sizeof(char), DataValue, Dest);	// Записать строку в файл назначения.
		else break;	// Если закончились данные заканчиваем запись.
	}
	// Закрыть файлы:
	fclose(Src);
	fclose(Dest);
	// Освобождение памяти, выделенную под буфер.
	delete[] Data;


	const char* name = Source;
	if (remove(name))		//Удаляем исходный файл
	{
		cout << "Ошибка! Невозможно переместить файл.\n\n";
		return;
	}
	else cout << "Ok...\n\n";
	system("pause");
	cout << endl;
	system("cls");
}
