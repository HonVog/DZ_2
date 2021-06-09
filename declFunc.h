#pragma once

#include <iostream>
#include "phonBook.h"
#include "designerBook.h"

enum Book {//������� ������
	NAME = 1,
	SONAME,
	PANAME,
	HOMTEL,
	JOBTEL,
	MOBTEL,
	USERINFO,
	EXIT
};

// � ���� ������� ����� ���� ������ ���� ���� �� ��������� 
//�� ��-�� ����������������� ����� ��� �������� ������� ���������
// ������ ���� ��������� �� ������ ������������ � ��������� �������� � ������
void sborkaMoegoHizoida() {

	designerBook book;

	std::string vvod;
	int klik;
	while (true)
	{
		phonBook human;
		std::cout << "������� ����� �������� ������ ������ *  ������������ ���� ��� �����\n\n\t1 * : ����� ���� ���\n"
			<< "\t2 * : ������ �������\n\t3 : ������ ��������\n\t4 : �������� �������\n\t5 : ������� �������\n\t"
			<< "6 * : ��������� �������\n\t 7 : �������������� ������ ������� ������� �������\n\t 8 : �����";

		if (_kbhit()) {
			// �������� ������ �������� �������
			klik = _getch();
			system("cls");
			switch (klik)
			{
			case NAME:
				std::cout << "������� ���� ��� :";
				std::cin >> vvod;
				human.set_name(vvod);
				break;
			case SONAME:
				std::cout << "������� ���� ������� :";
				std::cin >> vvod;
				human.set_soName(vvod);
				break;
			case PANAME:
				std::cout << "������� �������� :";
				std::cin >> vvod;
				human.set_paName(vvod);
				break;
			case HOMTEL:
				std::cout << "������� �������� ������� :";
				std::cin >> vvod;
				human.set_homTelefon(vvod);
				break;
			case JOBTEL:
				std::cout << "������� �������� ������� :";
				std::cin >> vvod;
				human.set_homTelefon(vvod);
				break;
			case MOBTEL:
				std::cout << "������� ��������� ������� :";
				std::cin >> vvod;
				human.set_mobailTelefon(vvod);
				break;
			case USERINFO:
				std::cout << "������� ���������� � ���� :";
				std::cin >> vvod;
				human.set_userInfo(vvod);
				break;
			case EXIT:
				system("cls"); return;
			default:
				system("cls");
				std::cout << "\n������������ ���� ��������� �������\n";
				break;
			}
			if (book.skan(human)) {
				std::cout << "\n������ ��������� � ���������� �����" << std::endl;
			}
		}
	}
}