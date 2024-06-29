#include <iostream>//���������� ����� � ������
#include <windows.h>//���������� ������������� �� ������� ����������� �������
#include <conio.h>//���������� ������������� �� ������� getch
#include <vector>//���������� ����������� �������
#include "MainMenu.h"//����������� HeaderFile � Enum-����
#include "Checks.h"//����������� HeaderFile � ���������� ����������������� �����
#include "ConsoleOutput.h"//����������� HeaderFile � ������� ������ �������� �� �������
#include "FileInput.h"//����������� HeaderFile � �������� ������
#include "FileOutput.h"//����������� HeaderFile � �������� �������
#include "Input.h"//����������� HeaderFile � ������ � �������
#include "Algoritm.h"//����������� HeaderFile � ������ � �������
#include "PersonalInterface.h"//����������� HeaderFile ����������������� ����������
#define QUIT 27//������ ������������ Esc �������� 27

int main()
{
	setlocale(LC_CTYPE, "RU"); //�����������
	SetConsoleCP(1251); //������� ��� ��������� ����������� � ��������� ���������� ��� �����
	SetConsoleOutputCP(1251); //������� ��� ��������� ����������� � ��������� ���������� ��� ������
	int userChoice = 0; //���������� ����������������� �����
	std::vector<std::string> text; //������ ������� ��������
	ShowGreetings(); //����� �����������
	ShowTask(); //����� �������
	do
	{
		ShowInputOption(); //����� ���� ������
		userChoice = GetChoise(); //���� ����������������� �������
		switch (userChoice) //switch ������ ����������� ����� ��� ���������
		{
		case (ConsoleDataInput):
			text = ConsoleInput(); //���� ������ �� ������������ � ������� 
			break;
		case (FileDataInput):
			text = FileInput(); //���� ������ �� ������������ �� �����
			ConsoleOutput(text); //����� ��������� ������ �� �������
			break;
		}
		std::vector<std::string> newText = CompressionAlghoritm(text);
		std::cout << "������ �����" << std::endl;
		ConsoleOutput(newText); //����� ��������� ������ �� �������
			ShowOutputType(); //����� ��������� �� ���������� ��������� ������ � ����
			userChoice = GetChoise(); // ���� ����������������� �������
			if (userChoice == Yes)
			{
				FileOutput(text, newText); //���������� ��������� ������� � ����
			}
		text.clear(); //������ ������� ��������
		newText.clear(); //������ ������� ��������
		std::cout << "������� Esc ����� ��������� ������ ���������." << std::endl;
		std::cout << "������� Enter ����� ����������." << std::endl;
		userChoice = _getch(); //���� ���� ������� ��������� � ����������
	} while (userChoice != QUIT); //�������� ��� ��� ������� ����� ���� ������� Quit
}
