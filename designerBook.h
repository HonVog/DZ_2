#include <iostream>
#include <cstring>
#include <cstdio>
#include <conio.h>
#include "declFunc.h"



enum saize { // ����� ����� ����s���� ������� � ��������� 
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
/// ����� ������������ ����� ������ ���������� �����
/// </summary>
/// <param name="SAIZ">����������� ������ ������� </param>
/// <param name="arrBook"> ����������� Macc�� ���������� ����� </param>
/// <param name="last">����������� ��������� ��������� ��������� ������� � ������� </param>
/// <param name="free">����������� ������ ��������� ����� � ��������� �����</param>
/// <param name="human">��������� ������ ��������� �����</param>

class designerBook
{
private:
	const static const int SAIZ{ 100 };
	static phonBook arrBook[SAIZ];
	static int last;
	static int free[SAIZ];
	phonBook human;
public:
	designerBook() {} // 90% ���������� �������� ����������� ����� �� ���������

	/// <summary>
	///��������� �������� � ��������� ��� �� ����������� ���������� 
	/// </summary>
	/// <param name="vvod">����������� �����</param>
	bool skan(phonBook human) {
		if (designerBook::chekReg(human)) {
			if (last == SAIZ) {
				system("cls");
				std::cout << "�������� ����� ���������� ���������� �����" << std::endl;
				return false;
			}
			else {
				arrBook[designerBook::chekFri()] = phonBook(human);
				return true;
			}
		}
		else {
			std::cout << "�� ��� ����������� ���� ��� ����� ��������� *" << std::endl;
			return false;
		}
		return false;
	}

	~designerBook() {} // ������ �� ������ ������ �������� ������. � ������ ��� �� �������� � �������. �� ��� ����������� �� ��������

	// ������� 
	int get_last() const {
		return designerBook::last;
	}

	int get_arrFree(int i) const {
		if (free[i] != 0)
			return designerBook::free[i];
		return 0;
	}

	// ������� ���������� �������� �������
	designerBook& print(int i) {
		arrBook[i].print();
	}

private:
	// ����� ���������� ������ ���������� ����� ���������� �������� � �������
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
	//����� ��������� ����� � ��������� ��� �������� �� ����������
   // ����������� ����� �� ��� ������ ��� ����� ������
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

