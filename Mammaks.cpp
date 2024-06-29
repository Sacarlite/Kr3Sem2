#include "Mammals.h"//Подключение HeaderFile с классом Mammals
#include <iostream>//Подключение библиотеки ввода и вывода
/*Все коментарии прописаны в Mammals.h*/
Mammals::Mammals(std::string methodOfNutrition, double weight, std::string livingEnvironment, std::string name)//Конструктор класса apartment
	:_methodOfNutrition(methodOfNutrition),_weight(weight),_livingEnvironment(livingEnvironment),_name(name)
{
}

