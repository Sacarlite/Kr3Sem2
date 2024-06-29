#include "FileInput.h"//Подключение HeaderFile с вводом данных из фаила
#include <fstream>//Библеотека ввода и вывода из фаила
#include <iostream>//Библеотека ввода и вывода
#include "CheckExeption.h"//Подключение HeaderFile с пользовательским классом ошибок ввода
#include "Checks.h"//Подключение HeaderFile с обработкой ошибок пользовательского ввода
#include <filesystem>//Подключение библеотеки для проверки состояния фаила

std::vector<std::string> FileInput()
{
	std::vector<std::string> text;//Объявления вектора cтрок
	std::string fileName;//Объявление переменной имени фаила
	std::ifstream file;//Создание потока для чтения из фаила
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	while (true)
	{
		std::cout << "Введите имя фаила (в разрешении .txt): " << std::endl;
		std::cin >> fileName;//Ввод пути к фаилу
		try
		{
			if (fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. " << std::endl;
				continue;
			}
			if (std::filesystem::is_regular_file(fileName)) {//Проверка на системные фаилы
				file.open(fileName);//Открытие потока ввода
				std::cout << "Фаил открыт успешно. " << std::endl;
			}
		}
		catch (const std::exception&)//Обработка ошибки при чтении из фаила
		{
			std::cout << " Произошла ошибка при открытии фаила.Повторите попытку:" << std::endl;
			continue;

		}
		try {
			file.exceptions(!std::ifstream::badbit | !std::ifstream::failbit);
			std::string str;//Объявление вводимой строки
			while (std::getline(file, str)) {
				if (str.empty()) {//Если строка пуста то цикл прекращается
					break;
				}
				text.push_back(str);//Добавление строки в конец вектора
			}
			if (text.empty()) {
					throw std::exception();
				}
		}
		catch (const std::exception) {//Обработка ошибки
			std::cout << "Произошла ошибка при чтении информации. Повторите попытку:" << std::endl;
			text.clear();
			file.close();//закрытие потока
			continue;
		}
		file.close();//закрытие потока
		return  text;
	}
}
