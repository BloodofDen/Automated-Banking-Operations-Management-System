#include"Headers.h"

template<typename Type> fstream UsersPossibilities::refreshFile(Registratoin *&enter, fstream &file, Type changes, int string_number)
{
	if (!(file.is_open()))
	{
		file.close();
		Label::_tag();
		cerr << "Ошибка!Файл не был открыт!";
		_getch();
		exit(EXIT_FAILURE);
	}
	fstream refreshfile;
	string old_path = "";
	string new_path = "";
	char copy_char;
	if (enter->Access)
	{
		refreshfile.open("Administrators\\" + enter->nickname_md5 + ".temp", ios_base::out);
		old_path = "Administrators\\" + enter->nickname_md5;
		new_path = "Administrators\\" + enter->nickname_md5 + ".temp";
	}
	else
	{
		refreshfile.open("Users\\" + enter->nickname_md5 + ".temp", ios_base::out);
		old_path = "Users\\" + enter->nickname_md5;
		new_path = "Users\\" + enter->nickname_md5 + ".temp";
	}
 	file.seekg(0, ios::beg);
	refreshfile.seekp(0, ios::beg);
	for (int i(0); i < string_number - 1; i++)
	{
		do
		{
			file.get(copy_char);
			refreshfile.put(copy_char);
		} while (copy_char != '\n');
	}
	refreshfile << changes << endl;
	
	do//Пропуск строки
	{
		file.get(copy_char);
	} while (copy_char != '\n');

	file.get(copy_char);
	while (!file.eof())
	{
		refreshfile.put(copy_char);
		file.get(copy_char);
	}
	file.close();
	refreshfile.close();
	remove(old_path.c_str());
	rename(new_path.c_str(), old_path.c_str());
	if (enter->Access)	refreshfile.open("Administrators\\" + enter->nickname_md5, ios_base::in | ios_base::out | ios_base::ate);
	else                refreshfile.open("Users\\" + enter->nickname_md5, ios_base::in | ios_base::out | ios_base::ate);
	return refreshfile;
}

void UsersPossibilities::numberofstring(fstream &file, int n)
{
	if (!(file.is_open()))
	{
		file.close();
		Label::_tag();
		cerr << "Ошибка!Файл не был открыт!";
		_getch();
		exit(EXIT_FAILURE);
	}
	char p;
	int i = 0;
	file.seekg(0, ios::beg);
	do {
		do { 
			p = file.get(); 
		} while (p != '\n');
		i++;
	} while (i < n - 1);
}

int UsersPossibilities::checkBalance(fstream &file)
{
	if (!(file.is_open()))
	{
		file.close();
		Label::_tag();
		cerr << "Ошибка!Файл не был открыт!";
		_getch();
		exit(EXIT_FAILURE);
	}
	string balance = "";
	file.seekg(0, ios::beg);
	numberofstring(file, 3);
	getline(file, balance);
	cout << "Баланс($): " << balance << endl;
	long kesh = stol(balance);
	getline(file, balance);
	cout << "Текущий кредит($): ";
	long credit = stol(balance);
	credit ? cout << balance << endl: cout << "null" << endl;
	return kesh;
}

void UsersPossibilities::addMoney(Registratoin *&enter, fstream &file)
{
	if (!(file.is_open()))
	{
		file.close();
		Label::_tag();
		cerr << "Ошибка!Файл не был открыт!";
		_getch();
		exit(EXIT_FAILURE);
	}
	string add = "";
	int balance = checkBalance(file);
	bool flag;
	do {
		flag = false;
		cout << "Сумма пополнения($): ";
		cin >> add;
		for (size_t i(0); i < add.size(); i++)
		{
			if (!isdigit(add[i]))
			{
				flag = true;
				break;
			}
		}
	} while (flag);
	balance += stoi(add);
	file = refreshFile(enter, file, balance, 3);
	file << endl << "Пополнение средств($): " << add;
	Label::_tag();
	checkBalance(file);
}

void UsersPossibilities::getMoney(Registratoin *&enter, fstream &file)
{
	if (!(file.is_open()))
	{
		file.close();
		Label::_tag();
		cerr << "Ошибка!Файл не был открыт!";
		_getch();
		exit(EXIT_FAILURE);
	}
	string get_money = "";
	int balance = checkBalance(file);
	bool flag;
	do {
		flag = false;
		cout << "Сумма снятия($): ";
		cin >> get_money;
		for (size_t i(0); i < get_money.size(); i++)
		{
			if (!isdigit(get_money[i]))
			{
				flag = true;
				break;
			}
		}
	} while (flag);
	balance -= stoi(get_money);
	if (balance < 0)
	{
		Label::_tag();
		cerr << "Не хватает денег на счёте!" << endl;
		return;
	}
	file = refreshFile(enter, file, balance, 3);
	file << endl << "Снятие средств($): " << get_money;
	Label::_tag();
	checkBalance(file);
}

string UsersPossibilities::checking_input(string str, string str1, string str2)
{
	string input = "";
	do
	{
		Label::_tag();
		cout << str << str2 << endl << str1;
		try
		{
			cin >> input;
			int size = input.size();
			switch (size)
			{
			case 1:
			{
				if ('1' > input[0] || input[0] > '9')
					throw 0;
				else throw 1;
			}break;
			case 2:
			{
				if ('1' > input[0] || input[0] > '9' || '0' > input[1] || input[1] > '9')
					throw 0;
				else throw 1;
			}break;
			case 3:
			{
				if ('1' > input[0] || input[0] > '9' || '0' > input[1] || input[1] > '9' || '0' > input[2] || input[2] > '9')
					throw 0;
				else throw 1;
			}break;
			case 4:
			{
				if ('1' > input[0] || input[0] > '9' || '0' > input[1] || input[1] > '9' || '0' > input[2] || input[2] > '9' || '0' > input[3] || input[3] > '9')
					throw 0;
				else throw 1;
			}break;
			case 5:
			{
				if ('1' > input[0] || input[0] > '9' || '0' > input[1] || input[1] > '9' || '0' > input[2] || input[2] > '9' || '0' > input[3] || input[3] > '9' || '0' > input[4] || input[4] > '9')
					throw 0;
				else throw 1;
			}break;
			case 6:
			{
				if ('1' > input[0] || input[0] > '9' || '0' > input[1] || input[1] > '9' || '0' > input[2] || input[2] > '9' || '0' > input[3] || input[3] > '9' || '0' > input[4] || input[4] > '9' || '0' > input[5] || input[5] > '9')
					throw 0;
				else throw 1;
			}break;
			case 7:
			{
				if ('1' > input[0] || input[0] > '1' || '0' > input[1] || input[1] > '0' || '0' > input[2] || input[2] > '0' || '0' > input[3] || input[3] > '0' || '0' > input[4] || input[4] > '0' || '0' > input[5] || input[5] > '0' || '0' > input[6] || input[6] > '0')
					throw 0;
				else throw 1;
			}break;
			default: throw 0; break;
			}
		}
		catch (int i) { if (i) break; }
		cerr << "Неверный ввод!";
		_getch();
	} while (true);
	return input;
}

string UsersPossibilities::checking_input(string str)
{
	string input = "";
	do
	{
		Label::_tag();
		cout << str;
		try
		{
			cin >> input;
			int size = input.size();
			switch (size)
			{
			case 1:
			{
				if ('1' > input[0] || input[0] > '9')
					throw 0;
				else throw 1;
			}break;
			case 2:
			{
				if ('1' > input[0] || input[0] > '9' || '0' > input[1] || input[1] > '9')
					throw 0;
				else throw 1;
			}break;
			case 3:
			{
				if ('1' > input[0] || input[0] > '9' || '0' > input[1] || input[1] > '9' || '0' > input[2] || input[2] > '9')
					throw 0;
				else throw 1;
			}break;
			case 4:
			{
				if ('1' > input[0] || input[0] > '9' || '0' > input[1] || input[1] > '9' || '0' > input[2] || input[2] > '9' || '0' > input[3] || input[3] > '9')
					throw 0;
				else throw 1;
			}break;
			case 5:
			{
				if ('1' > input[0] || input[0] > '9' || '0' > input[1] || input[1] > '9' || '0' > input[2] || input[2] > '9' || '0' > input[3] || input[3] > '9' || '0' > input[4] || input[4] > '9')
					throw 0;
				else throw 1;
			}break;
			case 6:
			{
				if ('1' > input[0] || input[0] > '9' || '0' > input[1] || input[1] > '9' || '0' > input[2] || input[2] > '9' || '0' > input[3] || input[3] > '9' || '0' > input[4] || input[4] > '9' || '0' > input[5] || input[5] > '9')
					throw 0;
				else throw 1;
			}break;
			case 7:
			{
				if ('1' > input[0] || input[0] > '1' || '0' > input[1] || input[1] > '0' || '0' > input[2] || input[2] > '0' || '0' > input[3] || input[3] > '0' || '0' > input[4] || input[4] > '0' || '0' > input[5] || input[5] > '0' || '0' > input[6] || input[6] > '0')
					throw 0;
				else throw 1;
			}break;
			default: throw 0; break;
			}
		}
		catch (int i) { if (i) break; }
		cerr << "Неверный ввод!";
		_getch();
	} while (true);
	return input;
}

void UsersPossibilities::creditNew(Registratoin *&enter, fstream &file)
{
	int coefficient;
	string current_balance = "";
	string input = checking_input("Введите сумму на которую хотите взять кредит:\nМинимальная сумма - 100$.\nМаксимальная сумма - 1000.000$.\nРазмер ежемесячной пени:\n|100 - 500$      | --- 5%\n|500 - 1000$     | --- 10%\n|1000 - 1000.000$| --- 30%\n--> ");
	int addition = stoi(input);
	if (addition <= 500)       coefficient = static_cast<int>(addition*1.05);
	else if (addition <= 1000) coefficient = static_cast<int>(addition*1.1);
	else if (addition > 1000)  coefficient = static_cast<int>(addition*1.3);
	numberofstring(file, 3);
	getline(file, current_balance);
	addition += stoi(current_balance);;
	file = refreshFile(enter, file, addition, 3);
	file = refreshFile(enter, file, coefficient, 4);
	file.seekp(0, ios::end);
	file << endl << "Взят кредит на сумму " << coefficient << '$';
	cout << "Взят кредит на сумму " << coefficient << "$!";
}

void UsersPossibilities::crediPay(Registratoin *&enter, fstream &file)
{
	int decreace, current_credit;
	string str = "";
	numberofstring(file, 4);
	getline(file, str);
	current_credit = stoi(str);
	if (!current_credit)
	{
		Label::_tag();
		cerr << "У вас нет кридита!" << endl;
		return;
	}
	string input = checking_input("Ваш текущий кредит составляет: ", "Введите сумму на которую хотите погасить кредит: ", str);
	decreace = stoi(input);
	current_credit -= decreace;
	if (current_credit < 0)
	{
		numberofstring(file, 3);
		getline(file, str);
		current_credit *= -1;
		current_credit += stoi(str);
		file = refreshFile(enter, file, current_credit, 3);
		file = refreshFile(enter, file, "0", 4);
		current_credit = 0;
	}
	else file = refreshFile(enter, file, current_credit, 4);
	Label::_tag();
	if (!current_credit)
	{
		cout << "Ваш кредит погашен! Поздравляю!";
		file << endl << "Кредит полностью погашен!";
	}
	else
	{
		file << endl << "Кредит частично погашен на сумму " << decreace << '$';
		cout << "Ваш кредит частично погашен на " << decreace << "$!";
	}
}

void UsersPossibilities::credit(Registratoin *&enter, fstream &file)
{
	if (!(file.is_open()))
	{
		file.close();
		Label::_tag();
		cerr << "Ошибка!Файл не был открыт!";
		_getch();
		exit(EXIT_FAILURE);
	}
	string input = "";
	do 
	{
		Label::_tag();
		cout << "<0> - Взять новый кредит\n<1> - Погасить уже взятый\n--> ";
		try
		{
			cin >> input;
			if (input.size() > 1 || '0' > input[0] || input[0] > '1') throw 0;
			else                                                      throw 1;
		}
		catch (int i) { if (i) break; }
	} while (true);
	switch (stoi(input))
	{
	case 0: numberofstring(file, 4);
		getline(file, input);
		if (stoi(input) > 0)
		{
			Label::_tag();
			cout << "У вас уже есть действующий кредит!" << endl;
			return;
		}
		creditNew(enter, file); break;
	case 1: crediPay(enter, file); break;
	}
}

void UsersPossibilities::changePassword(Registratoin *&enter, fstream &file)
{
	if (!(file.is_open()))
	{
		file.close();
		Label::_tag();
		cerr << "Ошибка!Файл не был открыт!";
		_getch();
		exit(EXIT_FAILURE);
	}
	string newpassword = enter->zvezda("новый ");
	file = refreshFile(enter, file, md5(newpassword), 1);
	string prompt = "";
	cout << "Введите новую подсказку к паролю: ";
	cin >> prompt;
	file = refreshFile(enter, file, prompt, 2);
	Label::_tag();
	cout << "Пароль успешно изменён!";
	file.seekp(0, ios::end);
	file << endl << "Пароль был успешно изменён!";
}

void UsersPossibilities::historyofOperations(fstream &file)
{
	if (!(file.is_open()))
	{
		file.close();
		Label::_tag();
		cerr << "Ошибка!Файл не был открыт!";
		_getch();
		exit(EXIT_FAILURE);
	}
	string hisory = "";
	file.seekg(0, ios::beg);
	numberofstring(file, 5);
	getline(file, hisory);
	cout << "История операций: " << endl << endl;
	while (!file.eof())
	{
		getline(file, hisory);
		cout << hisory << endl;
	}
	file.seekg(0, ios::beg);
}

void UsersPossibilities::list(Registratoin *&enter, fstream &file)
{
	if (!(file.is_open()))
	{
		file.close();
		Label::_tag();
		cerr << "Ошибка!Файл не был открыт!";
		_getch();
		exit(EXIT_FAILURE);
	}
	do
	{
		string input = "";
		do
		{
			Label::_tag();
			cout << "Возможности Пользователя: " << endl;
			cout << "<0> - Выход" << endl;
			cout << "<1> - Проверка баланса" << endl;
			cout << "<2> - Пополнение средств" << endl;
			cout << "<3> - Снятие средств" << endl;
			cout << "<4> - Операции с кредитом" << endl;
			cout << "<5> - История операций" << endl;
			cout << "<6> - Смена пароля" << endl;
			cout << "--> ";
			try
			{
				cin >> input;
				if (input.size() > 1 || '0' > input[0] || input[0] > '6') throw 0;
				else                                                      throw 1;
			}
			catch (int i) { if (i) break; }
		} while (true);
		Label::_tag();
		switch (stoi(input))
		{
		case 0: cout << "Хорошего дня!"; _getch(); file.close(); return;
		case 1: checkBalance(file); break;
		case 2: addMoney(enter, file); break;
		case 3: getMoney(enter, file); break;
		case 4: credit(enter, file); break;
		case 5: historyofOperations(file); break;
		case 6: changePassword(enter, file); break;
		}
		_getch();
	} while (true);
}