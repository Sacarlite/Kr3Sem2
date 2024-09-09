#include <vector>//Библиотека подключения вектора
#include "Herbivores.h"//Подключение HeaderFile с классом Herbivores
#include "ConsoleOutput.h"//Подключение HeaderFile с выводом данных на консоль
#include <iostream>//Библиотека ввода и вывода


void ConsoleOutput(std::vector<std::string> text)
{
	std::cout << "Текст:" << std::endl;
	for (auto i = text.begin(); i < text.end(); ++i)//Перебор вектора строк при помощи итератора 
	{
		std::cout << *i<<std::endl;
	}
	std::cout << std::endl;
}
