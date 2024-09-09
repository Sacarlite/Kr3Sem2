#include "Checks.h"//Подключение HeaderFile Checks
#include "CheckExeption.h"//Подключение HeaderFile с классом ошибки пользовательского ввода
#include <iostream>//Подключение библиотеки ввода и вывода
#include <tuple>//Подключение библиотеки tuple(кортежи)
#define A -64
#define я -1

int GetPositiveIntMoreThen0()//Функция ввода с консоли целого положительного значения
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Перевод строки в целочисленное значение
            if (value > 0) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выбрасывание ошибки
            }
        }
        catch (std::exception&) {//Обработка произошедшей ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;//Вывод сообщения об ошибке
        }
        
    }
}



int GetChoise()
{

    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Преобразование строки в целочисленный тип данных
            if (value == 1 || value == 2) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выброс ошибки
            }
        }
        catch (std::exception&) {//Обработка ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}
int GetMenuPoint()
{

    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Преобразование строки в целочисленный тип данных
            if (value == 1 || value == 2||value==3 || value == 4) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выброс ошибки
            }
        }
        catch (std::exception&) {//Обработка ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}
