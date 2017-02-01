#pragma once

class UsersPossibilities
{
private:

	//Функция создания файла для обновления информации
	template<typename Type> fstream refreshFile(Registratoin *&enter, fstream &file, Type changes, int string_number);
	
	//Функция проверки ввода кредита
	string checking_input(string str);

	//Перегруженная функция проверки ввода кредита
	string checking_input(string str, string str1, string str2);

	//Взять новый кредит
	void creditNew(Registratoin *&enter, fstream &file);

	//Выплатить кредит
	void crediPay(Registratoin *&enter, fstream &file);

protected:

	//Функция, устанавливающая указатель на считывание в начале n-ной строки
	void numberofstring(fstream &file, int n);

	//Проверка баланса	
	int checkBalance(fstream &file);
	
	//Положить деньги
	void addMoney(Registratoin *&enter, fstream &file);
	
	//Снять деньги
	void getMoney(Registratoin *&enter, fstream &file);
	
	//Общая функция кредита включающая creditnew и creditold 
	void credit(Registratoin *&enter, fstream &file);
	
	//Изменить пароль
	void changePassword(Registratoin *&enter, fstream &file);
	
	//История операций
	void historyofOperations(fstream &file);

public:

	//Пользовательский функционал
	void list(Registratoin *&enter, fstream &file);
};