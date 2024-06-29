#pragma once
#include <string>//Подключение библиотеки строк
#include<fstream>//Подключение библиотеки файлового ввода

double GetPositiveDoubleMoreThen0();//Функция ввода с консоли значения с плавающей точкой
int GetPositiveIntMoreThen0();//Функция ввода с консоли целого положительного значения
std::string CheckLineS(std::ifstream& file);//Функция ввода из фаила строкового значения
std::string GetString();//Функция ввода с консоли адреса
int CheckLineI(std::ifstream& file);//Функция ввода из фаила целого положительного значения
double CheckLineD(std::ifstream& file);//Функция ввода из фаила значения с плавающей точкой
int GetChoise();//Функция ввода пользовательского ввода
bool GetTrueOrFalse();//Функция ввода логической переменной
bool CheckLineB(std::ifstream& file);//Функция ввода логической переменной
int GetMenuPoint();//Функция ввода выбора пункта менюы