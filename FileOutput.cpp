#include "FileOutput.h"//����������� HeaderFile � ������� ������ � ����
#include <fstream>//���������� ����� � ������ �� �����
#include <iostream>//���������� ����� � ������
#include "Checks.h"//����������� HeaderFile � ���������� ������ ����������������� �����
#include "MainMenu.h"//����������� HeaderFile � Enum menu
#include "PersonalInterface.h"//����������� HeaderFile � ���������������� �����������
#include <filesystem>//����������� ���������� ��� �������� ��������� �����
class FileWriteException//���������������� ����� ������ ��������� ��������������
{
public:
	FileWriteException(std::string message) : message{ message } {}//����������� ������ 
	std::string getMessage() const { return message; }//������� ��������� �� ������
private:
	std::string message;//���� �������� ��������� �� ������
};
void WriteText(std::vector<std::string> newText,std::string fileName)//������� ������ ������ � ����
{
	std::ofstream  out;//�������� ������ ������ � ����
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	try {
		out.open(fileName);//�������� ����� ��� ������
		for (auto i = newText.begin(); i < newText.end(); ++i)//������� ������� ����� ��� ������ ���������
		{
			out << *i;//������ ������ � ����
		}
		out.close();//�������� ������
		std::cout << "������ ������� ���������" << std::endl;
	}
	catch(const std::exception&)//��������� ������
	{
		throw FileWriteException("���������� �������� ������ � ����. ��������� �������.");//������ ���������������� ������ ��������� ������
	}
}
void FileOutput(std::vector<std::string> newText)
{
	std::ifstream out2;//�������� ������ ������ �� �����
	std::string fileName;//���������� ����� ��� ���� �����
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	int userChoice = 0;//���������� ����������������� �����
	while (true) {
		std::cout << "������� ��� ����� (� ���������� .txt): ";
		std::cin >> fileName;//���� ���� � �����
		try {
			if(fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. "<<std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//�������� �� ��������� �����
					std::cout << "���� � ����� ������ ��� ����������" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("���������� �������� ������ � ����. ��������� �������.");//������ ���������������� ������ ��������� ������

			}
			out2.open(fileName);//������� �������� �����
			ShowOutputChoise();//������� ������ �� ������� ������ �����
			userChoice = GetChoise();//���� ����������������� ������
			if (userChoice == Yes) {
				
				out2.close();//�������� ������ ������ �� �����
				WriteText(newText, fileName);//������� ������ � ����
			}
			else {
				out2.close();//�������� ������ ������ �� �����
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteText(newText, fileName);//������� ������ � ����
				break;
			}
			catch ( FileWriteException err) {//��������� ������ �������������� � ������
				std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
			}
		}
		catch (FileWriteException err) {//��������� ������ �������������� � ������
			std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
		}

	}
}
