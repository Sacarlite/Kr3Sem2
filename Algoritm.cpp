#pragma once
#include <vector>//Библиотека подключения вектора
#include <iostream>//Библиотека ввода и вывода
#include "Herbivores.h"//Подключение HeaderFile с классом Herbivores
#include "Algoritm.h"//Подключение HeaderFile с списком алгоритмов
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "ConsoleOutput.h"//Подключение HeaderFile с функцией вывода списка животных на консоль
#include "Input.h"//Подключение HeaderFile с функцией ввода списка животных на консоль
#include "MainMenu.h"//Подключение HeaderFile с пунктами меню
std::vector<std::string> CompressionAlghoritm(std::vector<std::string> text)//Функция компрессии текста
{
	std::vector<std::string> compressedText;
	std::cout << "Какая длинна позиции должна кодироватся" << std::endl;
	std::cout << "Ввод: ";
	int compessdCoefficient = GetPositiveIntMoreThen0();
	for (auto i = text.begin(); i < text.end(); i++) {
		std::string tmp_str = *i;
		std::string added_string;
		int counter=0;
		auto iter = tmp_str.begin();
		for (auto j = tmp_str.begin(); j < tmp_str.end(); j++) {
			if (*iter==*j) {
				counter++;
			}
			if ((*iter != *j|| j== tmp_str.end()-1)&& counter>= compessdCoefficient) {
				added_string.push_back('{');
				added_string.push_back(*iter);
				added_string.push_back(',');
				added_string.insert(added_string.length(), std::to_string(counter));
				added_string.push_back('}');
				if (j == tmp_str.end() - 1) {
					break;
				}
				iter = j;
				counter = 1;
			}
			if((*iter != *j || j == tmp_str.end() - 1) && counter < compessdCoefficient){
				added_string.insert(added_string.length(), std::string(iter, j));
				iter = j;
				counter = 1;
			}
		}
		compressedText.push_back(added_string);
	}
	return compressedText;
}
