#include "Herbivores.h"//Подключение HeaderFile с классом Herbivores
#include <iostream>//Библиотека ввода и вывода
#include "Mammals.h"//Подключение HeaderFile с классом Mammals
Herbivores::Herbivores(std::string methodOfNutrition, double weight, std::string livingEnvironment,
	std::string name, bool poisonous, int averageLifeExpectancy):Mammals{ methodOfNutrition ,weight,livingEnvironment,name}, _poisonous{poisonous}, _averageLifeExpectancy{ averageLifeExpectancy }
{
}
std::string Herbivores::PoisonousToString()
{
	if (_poisonous)
	{
		return  "Да";
	}
	else
	{
		return  "Нет";
	}
}

std::string Herbivores::GetFullInformation() 
{

		return  _name +"\n" + _methodOfNutrition + "\n" + std::to_string(_weight) + "\n"+
			  _livingEnvironment + "\n"+PoisonousToString() + "\n"+
			 std::to_string(_averageLifeExpectancy) + "\n";
}
void Herbivores::ShowFullIformation()
{
	std::cout << "Название:" << _name << std::endl;
	std::cout << "Вес:" << _weight << std::endl;
	std::cout << "Способ питания:" << _methodOfNutrition << std::endl;
	std::cout << "Среда обитания:" << _livingEnvironment << std::endl;
	std::cout << "Средняя продолжительность:" <<_averageLifeExpectancy << std::endl;
	std::cout << "Ядовитость: " << PoisonousToString() << std::endl;
	
}
void Herbivores::SetMethodOfNutrition(std::string methodOfNutrition)
{
	_methodOfNutrition = methodOfNutrition;
}

void Herbivores::SetWeight(double weight)
{
	_weight = weight;
}

void Herbivores::SetLivingEnvironment(std::string livingEnvironment)
{
	_livingEnvironment = livingEnvironment;
}

void Herbivores::SetName(std::string name)
{
	_name = name;
}

void Herbivores::SetPoisonous(bool poisonous)
{
	_poisonous = poisonous;
}

void Herbivores::SetAverageLifeExpectancy(int averageLifeExpectancy)
{
	_averageLifeExpectancy = averageLifeExpectancy;
}