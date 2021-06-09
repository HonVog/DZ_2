#include <iostream>
#include <cstring>
#include <cstdio>
#include <conio.h>
#include "declFunc.h"



enum saize { // здесь будем указsвать размеры и проверять 
	saizeMin = 3,
	saizeName = 20,
	saizeSoName = 20,
	saizePaName = 20,
	saizeHomTelefon = 10,
	saizeJobTelefon = 10,
	saizeMobailTelefon = 11,
	saizeUserInfo = 200
};

/// <summary>
/// класс представляет собой массив телефонной книги
/// </summary>
/// <param name="SAIZ">статический размер массива </param>
/// <param name="arrBook"> статический Maccив телефонной книги </param>
/// <param name="last">статическая переменая последний свободный элемент в массиве </param>
/// <param name="free">статический массив свободных ячеек в телефоной книге</param>
/// <param name="human">переменая класса телефоная книга</param>

class designerBook
{
private:
	const static const int SAIZ{ 100 };
	static phonBook arrBook[SAIZ];
	static int last;
	static int free[SAIZ];
	phonBook human;
public:
	designerBook() {} // 90% параметров статичны конструктор нужен по умолчанию

	/// <summary>
	///принимает пораметр и проверяет его на соотвествие заполнения 
	/// </summary>
	/// <param name="vvod">принимаемый класс</param>
	bool skan(phonBook human) {
		if (designerBook::chekReg(human)) {
			if (last == SAIZ) {
				system("cls");
				std::cout << "Привышен лимит заполнений телефонной книги" << std::endl;
				return false;
			}
			else {
				arrBook[designerBook::chekFri()] = phonBook(human);
				return true;
			}
		}
		else {
			std::cout << "Не все необходимые поля для ввода заполнены *" << std::endl;
			return false;
		}
		return false;
	}

	~designerBook() {} // ничего не делает просто занимает строку. в теории тут бы проверку и очистки. НО КАК РЕАЛИЗОВАТЬ НЕ ПРИДУМАЛ

	// геттеры 
	int get_last() const {
		return designerBook::last;
	}

	int get_arrFree(int i) const {
		if (free[i] != 0)
			return designerBook::free[i];
		return 0;
	}

	// выводим содержимое элемента массива
	designerBook& print(int i) {
		arrBook[i].print();
	}

private:
	// метод возвращает первый встреченый адрес свободного элемента в массиве
	int chekFri() {
		if (last == 0) {
			static int free[SAIZ]{ 0, };
			++last;
			return (designerBook::last - 1);
		}
		int chek = 0;
		for (int i = 0; i < last; ++i) {
			if (arrBook[i].get_paName().empty()) {
				free [SAIZ] = i;
				(chek == 0) ? chek = i : chek;
			}
		}
		return chek;
	}
	//метод принимает класс и проверяет все элементы на сотвествие
   // регулярками легче но кто сказал что будет просто
	bool chekReg(phonBook& human) {
		int chek;
		chek = human.get_leng_name();
		if (chek < saizeMin || chek > saizeName) return false;

		chek = human.get_leng_soName();
		if (chek < saizeMin || chek > saizeSoName) return false;

		if (!human.get_paName().empty()) {
			chek = human.get_leng_paName();
			if (chek < saizeMin || chek > saizePaName) return false;
		}
		if (!human.get_homTelefon().empty()) {
			chek = human.get_leng_homTelefon();
			if (chek > saizeHomTelefon) return false;
		}

		chek = human.get_leng_mobailTelefon();
		if (chek > saizeMobailTelefon) return false;

		if (!human.get_jobTelefon().empty()) {
			chek = human.get_leng_jobTelefon();
			if (chek > saizeJobTelefon)
				return false;
		}

		if (!human.get_userInfo().empty()) {
			chek = human.get_leng_userInfo();
			if (chek > saizeUserInfo) return false;
		}
		return true;
	}
};

