#include <vector>//���������� ����������� �������
#include "Herbivores.h"//����������� HeaderFile � ������� Herbivores
#include "ConsoleOutput.h"//����������� HeaderFile � ������� ������ �� �������
#include <iostream>//���������� ����� � ������


void ConsoleOutput(std::vector<std::string> text)
{
	std::cout << "�����:" << std::endl;
	for (auto i = text.begin(); i < text.end(); ++i)//������� ������� ����� ��� ������ ��������� 
	{
		std::cout << *i<<std::endl;
	}
	std::cout << std::endl;
}
