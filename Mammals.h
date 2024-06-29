#pragma once
#include <string>//Подключение библеотеки строк
/*
Класс млекопитающее с приватными полями: способ питания, вес, среда 
обитания
*/
class Mammals//Класс млекопитающее
{
protected:
	std::string _methodOfNutrition{};//Поле способа питания
	double _weight{};//Поле веса
	std::string _livingEnvironment{};//Поле среда обитания
	std::string _name{};// Поле названия
public:
	Mammals(std::string methodOfNutrition, double weight, std::string livingEnvironment, std::string name);//Конструктор
	virtual ~Mammals()=default;//Деструктор
	virtual std::string GetFullInformation()=0;//Функция получения полной информации
	virtual void ShowFullIformation()=0;//Функция вывода полной информации
};


