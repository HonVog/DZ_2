#include <iostream>
#include "declFunc.h"

/// <summary>
/// класс телефонная книга
/// содер ФИО номера телефонов доп информации от пользователя
/// </summary>

class phonBook
{
	std::string _name;//Имя
	std::string _soName;// Фамилия
	std::string _paName;//Отчество
	std::string _homTelefon;//домашний телефон
	std::string _jobTelefon;//рабочий телефон
	std::string _mobailTelefon;//мобильный телефон
	std::string _userInfo;//дополнительная информация о контакте
public:
	//конструкторы

	/// <summary>
	/// главный конструктор в классе от него пойдет дилигирование остальных
	/// </summary>
	/// <param name="_pName">Вводимое имя -> будем считать параметром высокой приоритетности</param>
	/// <param name="_pSoName">Вводимая фамилия -> будем считать параметром высокой приоритетности</param>
	/// <param name="_pPaName">Вводимое отчество - > низкоприоритетный будем инициализировать через методы</param>
	/// <param name="_pHomTelefon">Домашний телефон -> средний приоритет инициализация в перегрузках конструктора</param>
	/// <param name="_pJobTelefon">Рабочий телефон -> средний приоритет инициализация в перегрузках конструктора</param>
	/// <param name="_pMobailTelefon">Мобильный телефон -> Высокий приоритет в И.Ф и моб телефон основные требования</param>
	/// <param name="_pUserInfo"></param>
	phonBook(std::string _pName, std::string _pSoName, std::string _pPaName, std::string _pHomTelefon,
		std::string _pJobTelefon, std::string _pMobailTelefon, std::string _pUserInfo) :
		_name{ _pName }, _soName{ _pSoName }, _paName{ _pPaName }, _homTelefon{ _pHomTelefon }, _jobTelefon{ _pJobTelefon },
		_mobailTelefon{ _pMobailTelefon }, _userInfo{ _pUserInfo }
	{
		if (_name == "") _name.clear(); // далее в функциях проверяем через if (_name.empty())
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

	phonBook() :phonBook("", "", "", "", "", "", "") {} // пользуемся как обнулителем информации массиве!

	//пробежим по геттерам

	std::string get_name() const { return phonBook::_name; }//не забыть переделать под С++ вид
	std::string get_soName() const { return phonBook::_soName; }
	std::string get_paName() const { return phonBook::_paName; }
	std::string get_homTelefon() const { return phonBook::_homTelefon; }
	std::string get_jobTelefon() const { return phonBook::_jobTelefon; }
	std::string get_mobailTelefon() const { return phonBook::_mobailTelefon; }
	std::string get_userInfo() const { return phonBook::_userInfo; }

	int get_leng_name() const { return phonBook::_name.length(); }//не забыть переделать под С++ вид
	int get_leng_soName() const { return phonBook::_soName.length(); }
	int get_leng_paName() const { return phonBook::_paName.length(); }
	int get_leng_homTelefon() const { return phonBook::_homTelefon.length(); }
	int get_leng_jobTelefon() const { return phonBook::_jobTelefon.length(); }
	int get_leng_mobailTelefon() const { return phonBook::_mobailTelefon.length(); }
	int get_leng_userInfo() const { return phonBook::_userInfo.length(); }


	//погнали сеттеры
	phonBook& set_name(std::string _name) { this->_name = _name; return *this; } //не забыть переделать под С++ вид
	phonBook& set_soName(std::string _soName) { this->_soName = _soName; return *this; }
	phonBook& set_paName(std::string _paName) { this->_paName = _paName; return *this; }
	phonBook& set_homTelefon(std::string _homTelefon) { this->_homTelefon = _homTelefon; return *this; }
	phonBook& set_jobTelefon(std::string _jobTelefon) { this->_jobTelefon = _jobTelefon; return *this; }
	phonBook& set_mobailTelefon(std::string _mobailTelefon) { this->_mobailTelefon = _mobailTelefon; return *this; }
	phonBook& set_userInfo(std::string _userInfo) { this->_userInfo = _userInfo; return *this; }

	// метод выводит на экран содержимое класса
	phonBook& print() {
		if (!_name.empty())
			std::cout << "Имя :" << phonBook::get_name() << std::endl;
		if (!_paName.empty())
			std::cout << "Фамилия :" << phonBook::get_soName() << std::endl;
		if (!_homTelefon.empty())
			std::cout << "Отчество :" << phonBook::get_paName() << std::endl;
		if (!_homTelefon.empty())
			std::cout << "Домашний телефон :" << phonBook::get_homTelefon() << std::endl;
		if (!_mobailTelefon.empty())
			std::cout << "Мобильный телефон :" << phonBook::get_homTelefon() << std::endl;
		if (!_jobTelefon.empty())
			std::cout << "Рабочий телефон :" << phonBook::get_jobTelefon() << std::endl;
		if (!_userInfo.empty())
			std::cout << "Дополнительная информация :" << phonBook::get_jobTelefon() << std::endl;
	}

	~phonBook() {
		// а здесь могла быть вся прелесть уничтожения массива char*
		// можно сделать так string::~string() но не стоит
	}
};

