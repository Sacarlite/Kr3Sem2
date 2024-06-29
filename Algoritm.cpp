#pragma once
#include <vector>//���������� ����������� �������
#include <iostream>//���������� ����� � ������
#include "Herbivores.h"//����������� HeaderFile � ������� Herbivores
#include "Algoritm.h"//����������� HeaderFile � ������� ����������
#include "Checks.h"//����������� HeaderFile � ���������� ����������������� �����
#include "ConsoleOutput.h"//����������� HeaderFile � �������� ������ ������ �������� �� �������
#include "Input.h"//����������� HeaderFile � �������� ����� ������ �������� �� �������
#include "MainMenu.h"//����������� HeaderFile � �������� ����
std::vector<std::string> CompressionAlghoritm(std::vector<std::string> text)//������� ���������� ������
{
	std::vector<std::string> compressedText;
	std::cout << "����� ������ ������� ������ �����������" << std::endl;
	std::cout << "����: ";
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
