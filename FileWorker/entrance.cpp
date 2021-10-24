#include "entrance.h"
#include "dirWork.h"
#include "fileWork.h"

using namespace std;

//void entrance::inputMenu()
//{
//	//записываем выбор пользователя в переменную
//	char choice;
//	do
//	{
//		system("cls");
//		cout << "Пожалуйста, выберите действие...\n";
//		//просмотр содержимого дисков
//		cout << "\n 1 - Работа с файлами\n";
//		//создать папку или файл
//		cout << " 2 - Работа с директориями\n";
//		//выход из программы
//		cout << "\n 0 - Выход\n ";
//		//принимаем выбор пользователя
//		cin >> choice;
//		//анализируем выбор и вызываем соответсвующее действие
//		switch (choice)
//		{
//		case '1':
//		{fileWork fW;
//		fW.fileMenu(); }
//		break;
//		case '2':
//		{dirWork dW;
//		dW.dirMenu(); }
//		break;
//		}
//	} while (choice != '0');//выход из программы	
//}
