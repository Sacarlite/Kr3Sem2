#include <iostream>//Библеотека ввода и вывода
#include <windows.h>//Библеотека ответственная за русскую локализацию консоли
#include <conio.h>//Библеотека ответственная за функцию getch
#include <vector>//Библеотека подключения вектора
#include "MainMenu.h"//Подключение HeaderFile с Enum-меню
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "ConsoleOutput.h"//Подключение HeaderFile с выводом текста на консоль
#include "FileInput.h"//Подключение HeaderFile с файловым вводом
#include "FileOutput.h"//Подключение HeaderFile с файловым выводом
#include "Input.h"//Подключение HeaderFile с вводом с консоли
#include "Algoritm.h"//Подключение HeaderFile с вводом с консоли
#include "PersonalInterface.h"//Подключение HeaderFile пользовательского интерфейса
#define QUIT 27//Макрос присваивания Esc значение 27

int main()
{
	setlocale(LC_CTYPE, "RU"); //Локализация
	SetConsoleCP(1251); //функции для настройки локализации в строковых переменных при вводе
	SetConsoleOutputCP(1251); //функции для настройки локализации в строковых переменных при выводе
	int userChoice = 0; //Переменная пользовательского ввода
	std::vector<std::string> text; //Вектор вводных строк
	ShowGreetings(); //Вывод приветствия
	ShowTask(); //Вывод задания
	do
	{
		ShowInputOption(); //Вывод типа вввода
		userChoice = GetChoise(); //Ввод пользовательского решения
		switch (userChoice) //switch выбора консольного ввода или файлового
		{
		case (ConsoleDataInput):
			text = ConsoleInput(); //Ввод текста с консоли 
			break;
		case (FileDataInput):
			text = FileInput(); //Ввод текста из файла
			ConsoleOutput(text); //Вывод считанных данных на консоль
			break;
		}
		ShowAlghoritmChoise();
		userChoice = GetChoise(); //Ввод пользовательского решения
		std::vector<std::string> newText;//Создание вектора нового текста
		switch (userChoice) //switch выбора консольного ввода или файлового
		{
		case (Compress):
			newText = CompressionAlghoritm(text); //Сжатие текста
			break;
		case (Decompress):
			try {
				newText = DecompressionAlghoritm(text); //Восстановление текста 
			}
			catch (std::exception) {
				std::cout << "Произошла ошибка при восстановлении текста" << std::endl;
				text.clear(); //Чистка вектора исходных строк
				newText.clear(); //Чистка вектора модифицированного текста
				continue;
			}
			break;
		}
		std::cout << "Итоговый текст" << std::endl;
		ConsoleOutput(newText); //Вывод модифицированных данных на консоль
			ShowOutputType(); //Вывод сообщения об сохранении выбранных данных в файл
			userChoice = GetChoise(); // Ввод пользовательского решения
			if (userChoice == Yes)
			{
				FileOutput(newText); //Сохранение модифицированного текста в фаил
			}
			text.clear(); //Чистка вектора исходных строк
			newText.clear(); //Чистка вектора модифицированного текста
		std::cout << "Нажмите Esc чтобы завершить работу программы." << std::endl;
		std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
		userChoice = _getch(); //Ввод кода символа введённого с клавиатуры
	} while (userChoice != QUIT); //Проверка что код символа равен коду макроса Quit
}
