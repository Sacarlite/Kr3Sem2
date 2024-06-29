#include "FileInput.h"//����������� HeaderFile � ������ ������ �� �����
#include <fstream>//���������� ����� � ������ �� �����
#include <iostream>//���������� ����� � ������
#include "CheckExeption.h"//����������� HeaderFile � ���������������� ������� ������ �����
#include "Checks.h"//����������� HeaderFile � ���������� ������ ����������������� �����
#include <filesystem>//����������� ���������� ��� �������� ��������� �����

std::vector<std::string> FileInput()
{
	std::vector<std::string> text;//���������� ������� c����
	std::string fileName;//���������� ���������� ����� �����
	std::ifstream file;//�������� ������ ��� ������ �� �����
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	while (true)
	{
		std::cout << "������� ��� ����� (� ���������� .txt): " << std::endl;
		std::cin >> fileName;//���� ���� � �����
		try
		{
			if (fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. " << std::endl;
				continue;
			}
			if (std::filesystem::is_regular_file(fileName)) {//�������� �� ��������� �����
				file.open(fileName);//�������� ������ �����
				std::cout << "���� ������ �������. " << std::endl;
			}
		}
		catch (const std::exception&)//��������� ������ ��� ������ �� �����
		{
			std::cout << " ��������� ������ ��� �������� �����.��������� �������:" << std::endl;
			continue;

		}
		try {
			file.exceptions(!std::ifstream::badbit | !std::ifstream::failbit);
			std::string str;//���������� �������� ������
			while (std::getline(file, str)) {
				if (str.empty()) {//���� ������ ����� �� ���� ������������
					break;
				}
				text.push_back(str);//���������� ������ � ����� �������
			}
			if (text.empty()) {
					throw std::exception();
				}
		}
		catch (const std::exception) {//��������� ������
			std::cout << "��������� ������ ��� ������ ����������. ��������� �������:" << std::endl;
			text.clear();
			file.close();//�������� ������
			continue;
		}
		file.close();//�������� ������
		return  text;
	}
}
