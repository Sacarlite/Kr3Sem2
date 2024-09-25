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

std::vector<std::string> DecompressionAlghoritm(std::vector<std::string> text)//Функция декомпрессии
{
	std::vector<std::string> normalText;
	for (auto i = text.begin(); i < text.end(); i++) {
		std::string tmpString = *i;
		int pivot = 0;
		int index = 0;
		while (tmpString.find_first_of("{", pivot) != std::string::npos) {
			index = tmpString.find_first_of("{", pivot);
			pivot = index;
			char insertedChar = tmpString[pivot + 1];
			if (tmpString.find_first_of("}", pivot) == std::string::npos) {
				break;
			}
			if (tmpString[pivot + 2] != ',') {
				pivot++;
				continue;
			}
			index = tmpString.find_first_of("}", pivot);
			int numberSize = index - (pivot + 3);//Получаем длинну числа
			auto num = tmpString.substr(pivot + 3, numberSize);
			int number = 0;
			try {
				number = std::stoi(num);
			}
			catch (std::exception) {
				pivot++;
				continue;
			}
			tmpString.erase(pivot, numberSize+4);
			tmpString.insert(pivot, number, insertedChar);
			pivot = pivot + number;
		}
		normalText.push_back(tmpString);
	}

	return normalText;
}
