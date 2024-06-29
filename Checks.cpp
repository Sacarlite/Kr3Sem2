#include "Checks.h"//Подключение HeaderFile Checks
#include "CheckExeption.h"//Подключение HeaderFile с классом ошибки пользовательского ввода
#include <iostream>//Подключение библиотеки ввода и вывода
#include <tuple>//Подключение библиотеки tuple(кортежи)
#define A -64
#define я -1

double GetPositiveDoubleMoreThen0()//Функция ввода с консоли значения с плавающей точкой
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            double value = std::stod(str);//Перевод строки в значение с плавающей точкой
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
bool isalpharus(char c)//Функция проверки на русские буквы
{
    return (c >= A && c <= я) || c == -88 || c == -72;
}
//Коментарии см. функцию ввода адреса
std::string CheckLineS(std::ifstream& file)
{
    std::string temp_s = "";
    try
    {
        std::getline(file, temp_s);
        if (!temp_s.empty())
        {
            if (!isalpharus(temp_s[0]))
            {
                throw std::exception();
            }
        }
        else
        {
            throw std::exception();
        }
        for (int i = 1; i < temp_s.size(); i++)//Цикл по i от 2го символа до конца строки
        {
            if (!isalpharus(temp_s[i]) && !isdigit(temp_s[i]) && temp_s[i] != '.' && temp_s[i] != ',' && temp_s[i] != '-' && temp_s[i] != ' ' && temp_s[i] != '/')
            {
                throw std::exception();
            }
            if (temp_s[i] == '.' && temp_s[i - 1] == '.')//Если две точки идут подряд
            {
                throw std::exception();//Выброс ошибки
            }
            if (temp_s[i] == '/' && temp_s[i - 1] == '/')//Если две дроби идут подряд
            {
                throw std::exception();
            }
            if (temp_s[i] == ',' && temp_s[i - 1] == ',')//Если две запятых идут подряд
            {
                throw std::exception();//Выброс ошибки
            }
            if (temp_s[i] == '-' && temp_s[i - 1] == '-')//Если два тире идут подряд
            {
                throw std::exception();//Выброс ошибки
            }
            if (temp_s[i] == ' ' && temp_s[i - 1] == ' ')//Если два пробела идут подряд
            {
                throw std::exception();//Выброс ошибки
            }
        }
        return temp_s;
       

    }
    catch (const std::exception&)
    {
        throw CheckException("Произошла ошибка при чтении информации из фаила");
    }
}

std::string GetString()
{
    std::string temp_s = "";//Объявление переменной строки
    while (true)
    {
        try
        {
            getline(std::cin, temp_s);//Запись строки введёной на консоль в переменную temp_s
            if (!temp_s.empty())//Если строка пуста
            {
                if (!isalpharus(temp_s[0]))//Если первый символ не буква
                {
                    throw std::exception();//Выброс ошибки
                }
            }
            else
            {
                throw std::exception();//Выброс ошибки
            }
            for (int i = 1; i < temp_s.size(); i++)//Цикл по i от 2го символа до конца строки
            {
                if (!isalpharus(temp_s[i]) && temp_s[i] != '.' && temp_s[i] != ',' && temp_s[i] != '-' && temp_s[i] != ' '&& temp_s[i] != '/')//Если символ не русская буква,точка, запятая, пробел и тире
                {
                    throw std::exception();//Выброс ошибки
                }
            	if(temp_s[i]=='.'&& temp_s[i-1]=='.')//Если две точки идут подряд
                {
                    throw std::exception();//Выброс ошибки
                }
                if (temp_s[i] == '/' && temp_s[i - 1] == '/')//Если две дроби идут подряд
                {
                    throw std::exception();
                }
                if (temp_s[i] == ',' && temp_s[i - 1] == ',')//Если две запятых идут подряд
                {
                    throw std::exception();//Выброс ошибки
                }
                if (temp_s[i] == '-' && temp_s[i - 1] == '-')//Если два тире идут подряд
                {
                    throw std::exception();//Выброс ошибки
                }
                if (temp_s[i] == ' ' && temp_s[i - 1] == ' ')//Если два пробела идут подряд
                {
                    throw std::exception();//Выброс ошибки
                }
            }
            return temp_s;

        }
        catch (const std::exception&)//Обработка ошибки
        {
            std::cout << "Произошла ошибка при обработке адреса повторите попытку: " << std::endl;//Вывод сообщения об ошибке
        }
    }
}
int CheckLineI(std::ifstream& file)
{
    std::string temp_v = "";//Объявление переменной строки
    try
    {
        std::getline(file, temp_v);//Запись строки введёной на консоль в переменную temp_s
        int temp_i = stoi(temp_v);//Преобразование строки в целочисленный тип
        if (temp_i <= 0)

        {
            throw  std::exception();//Выброс ошибки
        }
        else

            return temp_i;
    }
    catch (const std::exception&)//Обработка ошибки
    {
        throw CheckException("Произошла ошибка при чтении информации из фаила");//Выброс ошибки пользовательского типа
    }
    
}
double CheckLineD(std::ifstream& file)
{
    std::string temp_v = "";//Объявление переменной строки
    try
    {
        std::getline(file, temp_v);//Запись строки введёной на консоль в переменную temp_s

        double temp_d = stod(temp_v);//Преобразование строки в значение с плавающей точкой
        if (temp_d < 0)
        {
            throw std::exception();//Выброс ошибки
        }
        else

            return temp_d;
    }
        catch (const std::exception&)//Обработка ошибки
        {
            throw CheckException("Произошла ошибка при чтении информации из фаила");//Выброс ошибки пользовательского типа
        }
}
bool CheckLineB(std::ifstream& file)
{
    std::string temp_v = "";//Объявление переменной строки
    try
    {
        std::getline(file, temp_v);//Запись строки введёной на консоль в переменную temp_s
        if (temp_v == "Да") {
            return true;
        }
        else if (temp_v == "Нет") {
            return false;
        }
        else {
            throw std::exception();
        }
    }
    catch (const std::exception&)//Обработка ошибки
    {
        throw CheckException("Произошла ошибка при чтении информации из фаила");//Выброс ошибки пользовательского типа
    }
}
bool GetTrueOrFalse()
{
    int choise = GetChoise();
    if(choise==1)
    {
        return true;
    }
    else
    {
        return false;
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
