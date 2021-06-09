#pragma once

#include <iostream>
#include "phonBook.h"
#include "designerBook.h"

enum Book {//жмакаем кнопки
	NAME = 1,
	SONAME,
	PANAME,
	HOMTEL,
	JOBTEL,
	MOBTEL,
	USERINFO,
	EXIT
};

// в этой функции много чего должно было бфть по умолчанию 
//но из-за неконтролируемого роста она получила жесткое обризание
// теперь тупо пробегает по выбору пользователя и вкидывает значение в массив
void sborkaMoegoHizoida() {

	designerBook book;

	std::string vvod;
	int klik;
	while (true)
	{
		phonBook human;
		std::cout << "Введите число согласно вашему выбору *  обязательные поля для ввода\n\n\t1 * : Вести свое имя\n"
			<< "\t2 * : Ввести фамилию\n\t3 : Ввести отчество\n\t4 : Домашний телефон\n\t5 : Рабочий телефон\n\t"
			<< "6 * : Мобильный телефон\n\t 7 : Дополнительные данные которые желаете указать\n\t 8 : Выход";

		if (_kbhit()) {
			// передаем символ пойманой клавиши
			klik = _getch();
			system("cls");
			switch (klik)
			{
			case NAME:
				std::cout << "Введите свое имя :";
				std::cin >> vvod;
				human.set_name(vvod);
				break;
			case SONAME:
				std::cout << "Введите свою фамилию :";
				std::cin >> vvod;
				human.set_soName(vvod);
				break;
			case PANAME:
				std::cout << "Введите отчество :";
				std::cin >> vvod;
				human.set_paName(vvod);
				break;
			case HOMTEL:
				std::cout << "Введите домашний телефон :";
				std::cin >> vvod;
				human.set_homTelefon(vvod);
				break;
			case JOBTEL:
				std::cout << "Введите домашний телефон :";
				std::cin >> vvod;
				human.set_homTelefon(vvod);
				break;
			case MOBTEL:
				std::cout << "Введите мобильный телефон :";
				std::cin >> vvod;
				human.set_mobailTelefon(vvod);
				break;
			case USERINFO:
				std::cout << "Введите информацию о себе :";
				std::cin >> vvod;
				human.set_userInfo(vvod);
				break;
			case EXIT:
				system("cls"); return;
			default:
				system("cls");
				std::cout << "\nНеправельный ввод повторите попытку\n";
				break;
			}
			if (book.skan(human)) {
				std::cout << "\nДанные дабавлены в телефонную книгу" << std::endl;
			}
		}
	}
}