#include "Input.h"//Подключение HeaderFile с вводом данных с консоли
#include <iostream>//Подключение библиотеки ввода и вывода
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "MainMenu.h"//Подключение HeaderFile с Enum menu

std::vector<std::string> ConsoleInput()
{
	while (true) {
		std::vector<std::string> text;//Объявления вектора строк
        std::string str;//Объявление вводимой строки
        std::cout << "Ввод сжимаемого текста:" << std::endl;
        try {	
            while(true) {
                std::getline(std::cin, str);//Ввод строки с консоли
                if (str.empty()) {//Если строка пуста то цикл прекращается
                    break;
                }
                str.push_back('\n');//Добавление символа конца строки
                text.push_back(str);//Добавление строки в конец вектора
            }
            if (text.empty()) {
                throw std::exception();
            }
            return text;
        }
        catch (std::exception) {
            std::cout << "Произошла ошибка при вводе данных повторите попытку." << std::endl;
            text.clear();//Чистка вектора строк
            str.clear();//Чистка строки
            continue;
        }
    }
}
