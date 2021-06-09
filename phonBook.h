#include <iostream>
#include "declFunc.h"

/// <summary>
/// ����� ���������� �����
/// ����� ��� ������ ��������� ��� ���������� �� ������������
/// </summary>

class phonBook
{
	std::string _name;//���
	std::string _soName;// �������
	std::string _paName;//��������
	std::string _homTelefon;//�������� �������
	std::string _jobTelefon;//������� �������
	std::string _mobailTelefon;//��������� �������
	std::string _userInfo;//�������������� ���������� � ��������
public:
	//������������

	/// <summary>
	/// ������� ����������� � ������ �� ���� ������ ������������� ���������
	/// </summary>
	/// <param name="_pName">�������� ��� -> ����� ������� ���������� ������� ��������������</param>
	/// <param name="_pSoName">�������� ������� -> ����� ������� ���������� ������� ��������������</param>
	/// <param name="_pPaName">�������� �������� - > ����������������� ����� ���������������� ����� ������</param>
	/// <param name="_pHomTelefon">�������� ������� -> ������� ��������� ������������� � ����������� ������������</param>
	/// <param name="_pJobTelefon">������� ������� -> ������� ��������� ������������� � ����������� ������������</param>
	/// <param name="_pMobailTelefon">��������� ������� -> ������� ��������� � �.� � ��� ������� �������� ����������</param>
	/// <param name="_pUserInfo"></param>
	phonBook(std::string _pName, std::string _pSoName, std::string _pPaName, std::string _pHomTelefon,
		std::string _pJobTelefon, std::string _pMobailTelefon, std::string _pUserInfo) :
		_name{ _pName }, _soName{ _pSoName }, _paName{ _pPaName }, _homTelefon{ _pHomTelefon }, _jobTelefon{ _pJobTelefon },
		_mobailTelefon{ _pMobailTelefon }, _userInfo{ _pUserInfo }
	{
		if (_name == "") _name.clear(); // ����� � �������� ��������� ����� if (_name.empty())
		if (_soName == "") _soName.clear();
		if (_paName == "") _paName.clear();
		if (_homTelefon == "") _homTelefon.clear();
		if (_jobTelefon == "") _jobTelefon.clear();
		if (_mobailTelefon == "") _mobailTelefon.clear();
		if (_userInfo == "") _userInfo.clear();
	}

	phonBook(std::string _pName, std::string _pSoName, std::string _pMobailTelefon) :
		phonBook(_pName, _pSoName, "", "", "", _pMobailTelefon, "") {}

	phonBook(std::string _pName, std::string _pSoName, std::string _pMobailTelefon, std::string _pJobTelefon) :
		phonBook(_pName, _pSoName, "", "", _pJobTelefon, _pMobailTelefon, "") {}

	phonBook(std::string _pName, std::string _pSoName, std::string _pMobailTelefon, std::string _pJobTelefon, std::string _pHomTelefon) :
		phonBook(_pName, _pSoName, "", _pHomTelefon, _pJobTelefon, _pMobailTelefon, "") {}

	phonBook(std::string _pName, std::string _pSoName, std::string _pMobailTelefon, std::string _pJobTelefon,
		std::string _pHomTelefon, std::string _pUserInfo) :
		phonBook(_pName, _pSoName, "", _pHomTelefon, _pJobTelefon, _pMobailTelefon, _pUserInfo) {}

	phonBook() :phonBook("", "", "", "", "", "", "") {} // ���������� ��� ����������� ���������� �������!

	//�������� �� ��������

	std::string get_name() const { return phonBook::_name; }//�� ������ ���������� ��� �++ ���
	std::string get_soName() const { return phonBook::_soName; }
	std::string get_paName() const { return phonBook::_paName; }
	std::string get_homTelefon() const { return phonBook::_homTelefon; }
	std::string get_jobTelefon() const { return phonBook::_jobTelefon; }
	std::string get_mobailTelefon() const { return phonBook::_mobailTelefon; }
	std::string get_userInfo() const { return phonBook::_userInfo; }

	int get_leng_name() const { return phonBook::_name.length(); }//�� ������ ���������� ��� �++ ���
	int get_leng_soName() const { return phonBook::_soName.length(); }
	int get_leng_paName() const { return phonBook::_paName.length(); }
	int get_leng_homTelefon() const { return phonBook::_homTelefon.length(); }
	int get_leng_jobTelefon() const { return phonBook::_jobTelefon.length(); }
	int get_leng_mobailTelefon() const { return phonBook::_mobailTelefon.length(); }
	int get_leng_userInfo() const { return phonBook::_userInfo.length(); }


	//������� �������
	phonBook& set_name(std::string _name) { this->_name = _name; return *this; } //�� ������ ���������� ��� �++ ���
	phonBook& set_soName(std::string _soName) { this->_soName = _soName; return *this; }
	phonBook& set_paName(std::string _paName) { this->_paName = _paName; return *this; }
	phonBook& set_homTelefon(std::string _homTelefon) { this->_homTelefon = _homTelefon; return *this; }
	phonBook& set_jobTelefon(std::string _jobTelefon) { this->_jobTelefon = _jobTelefon; return *this; }
	phonBook& set_mobailTelefon(std::string _mobailTelefon) { this->_mobailTelefon = _mobailTelefon; return *this; }
	phonBook& set_userInfo(std::string _userInfo) { this->_userInfo = _userInfo; return *this; }

	// ����� ������� �� ����� ���������� ������
	phonBook& print() {
		if (!_name.empty())
			std::cout << "��� :" << phonBook::get_name() << std::endl;
		if (!_paName.empty())
			std::cout << "������� :" << phonBook::get_soName() << std::endl;
		if (!_homTelefon.empty())
			std::cout << "�������� :" << phonBook::get_paName() << std::endl;
		if (!_homTelefon.empty())
			std::cout << "�������� ������� :" << phonBook::get_homTelefon() << std::endl;
		if (!_mobailTelefon.empty())
			std::cout << "��������� ������� :" << phonBook::get_homTelefon() << std::endl;
		if (!_jobTelefon.empty())
			std::cout << "������� ������� :" << phonBook::get_jobTelefon() << std::endl;
		if (!_userInfo.empty())
			std::cout << "�������������� ���������� :" << phonBook::get_jobTelefon() << std::endl;
	}

	~phonBook() {
		// � ����� ����� ���� ��� �������� ����������� ������� char*
		// ����� ������� ��� string::~string() �� �� �����
	}
};

