#pragma once
#include <string>//Подключение библиотеки строк
#include "Mammals.h"//Подключение HeaderFile с классом Mammals
/*
Класс травоядное наследуемый от класса млекопитающее с приватными полями: ядовитость,средняя продолжительность жизни
обитания
*/
class Herbivores : public Mammals//Класс травоядное
{
private:
	bool _poisonous{};//Поле ядовитое
	int _averageLifeExpectancy{};//Поле средней продолжительности жизни
	std::string PoisonousToString();
public:
	Herbivores(std::string methodOfNutrition, double weight, std::string livingEnvironment,
		std::string name, bool poisonous, int averageLifeExpectancy);//Конструктор
	std::string GetFullInformation() override;//Функция получения полной информации
	void ShowFullIformation() override;//Функция вывода полной информации
	void SetMethodOfNutrition(std::string methodOfNutrition);//Функция установки поля метод питания введёнными данными
	void SetWeight(double weight);//Функция установки поля веса введёнными данными
	void SetLivingEnvironment(std::string livingEnvironment);//Функция установки поля среды обитания введёнными данными
	void SetName(std::string name);//Функция установки поля имени введёнными данными
	void SetPoisonous(bool poisonous);//Функция установки поля ядовитость введёнными данными
	void SetAverageLifeExpectancy(int averageLifeExpectancy);//Функция установки поля средняя продолжительность жизни введёнными данными
};
