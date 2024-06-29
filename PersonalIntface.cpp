#include <iostream>//Подключение библеотеки ввода и вывода
#include "PersonalInterface.h"

void ShowTask() {
	std::cout << "Найти в тексте все последовательности идущих подряд одинаковых символов " << std::endl;
	std::cout << "и заменить их сигнатурой{ символ, количество }. Минимальная длинна" << std::endl;
	std::cout << "последовательности, которая может подвергаться замене, задается" << std::endl;
	std::cout << "пользователем.Предусмотреть режим восстановления оригинального текста." << std::endl;
	std::cout << "Пример: текст «длинношеее животное» должен быть заменен текстом" << std::endl;
	std::cout << "«длиннош{ e, 3 } животное»." << std::endl;
	}

void ShowOutputDataOption()
{
	std::cout << "Вы хотите сохранить исходные данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
	std::cout << "Ввод:";
}
void ShowInputOption()
{
	std::cout << "Какой вид ввода данных вы хотите использовать?" << std::endl;
	std::cout << "1)Фаиловый" << std::endl;
	std::cout << "2)Консольный" << std::endl;
	std::cout << "Ввод:";
}

void ShowGreetings()
{
	std::cout << "Контрольная работа №3 Кутькина Олеся 4304г" << std::endl;
}

void ShowOutputType()
{
	std::cout << "Вы хотите записать данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
	std::cout << "Ввод:";
}


void ShowOutputChoise()
{
	std::cout << "Вы хотите перезаписать данный фаил?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Ввести новое имя(путь к фаилу)" << std::endl;
	std::cout << "Ввод:";
}
