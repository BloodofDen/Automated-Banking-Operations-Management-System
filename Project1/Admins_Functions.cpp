#include"Headers.h"

void AdminsPossibilities::increacetoAdmin(fstream &file)
{
	if (!(file.is_open()))
	{
		file.close();
		Label::_tag();
		cerr << "Ошибка!Файл не был открыт!";
		_getch();
		exit(EXIT_FAILURE);
	}
	cout << "Введите имя Пользователя: ";
	string username = "";
	cin >> username;
	string spforAnsw = username;
	username = md5(username);
	ifstream oldUser("Users\\" + username);
	if (!(oldUser.is_open()))
	{
		Label::_tag();
		cerr << "Пользователь с таким именем не найден!" << endl;
		return;
	}
	else
	{
		fstream newAdmin("Administrators\\" + username);
		if (newAdmin.is_open())
		{
			Label::_tag();
			cerr << "Администратор с таким именем уже существует!" << endl;
			return;
		}
		else
		{
			newAdmin.close();
			newAdmin.open("Administrators\\" + username, ios_base::out);
			oldUser.seekg(0, ios::beg);
			string copy = "";
			while (!oldUser.eof())
			{
				getline(oldUser, copy);
				newAdmin << copy << endl;
			}
			oldUser.close();
			newAdmin << endl << "Был повышен до Администратора!";
			newAdmin.close();
			Label::_tag();
			string path = "Users\\" + username;
			if (remove(path.c_str())) cerr << "Внимание! Файл \"старого\" Пользователя не был удалён!" << endl;
			else                      cout << endl << "Пользователь " << spforAnsw << " теперь Администратор!";
		}
	}
}

void AdminsPossibilities::changeAdmin(Registratoin *&enter, fstream &file)
{
	file.close();
	file = enter->logIn(enter->Access = true, false);
}

void AdminsPossibilities::for_freeze_thawed(string str1, string str2, char ch)
{
	string login = "";
	cout << "Логин для " << str1 << ": ";
	cin >> login;
	fstream file("Users\\" + md5(login));
	Label::_tag();
	if (!(file.is_open()))
		cerr << "Такого Пользователя не существует!";
	else
	{
		UsersPossibilities::numberofstring(file, 5);
		file.seekp(file.tellg(), ios::beg);
		file << ch;
		cout << "Пользователь " << str2 << " Администратором!";
		file.seekp(0, ios::end);
		file << endl << "Был " << str2 << " Администратором!";
		file.close();
	}
}

void AdminsPossibilities::userlist()
{
	fstream file("userlist");
	if (!file.is_open())
	{
		Label::_tag();
		cerr << "На данный момент ни один пользователь не зарегистрировался!" << endl;
		return;
	}
	string user = "";
	cout << "Зарегестрированные пользователи: " << endl << "___________________________" << endl;
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		getline(file, user);
		cout << user << endl;
	}
	cout << "___________________________";
	file.close();
}

void AdminsPossibilities::check_User()
{
	string name = "";
	cout << "Введите имя пользователя: ";
	cin >> name;
	name = md5(name);
	ifstream file("Users\\" + name);
	bool exist = file.is_open();
	file.close();
	if (exist) cout << "\nПользователь Существует!";
	else cout << "\nПользователь НЕ Существует!";
}

void AdminsPossibilities::list(Registratoin *&enter, fstream &file)
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
			cout << "Возможности Администратора: " << endl;
			cout << "<0>  -  Выход" << endl;
			cout << "<1>  -  Проверка баланса" << endl;
			cout << "<2>  -  Пополнение средств" << endl;
			cout << "<3>  -  Снятие средств" << endl;
			cout << "<4>  -  Операции с кредитом" << endl;
			cout << "<5>  -  История операций" << endl;
			cout << "<6>  -  Смена пароля" << endl;
			cout << "<7>  -  Повысить до Администратора" << endl;
			cout << "<8>  -  Заморозить доступ Пользователю" << endl;
			cout << "<9>  -  Разморозить доступ Пользователю" << endl;
			cout << "<10> -  Смена Администратора" << endl;
			cout << "<11> -  Список всех Пользователей" << endl;
			cout << "<12> -  Проверка Пользователя на существование" << endl;
			cout << "--> ";
			try
			{
				cin >> input;
				if (input.size() > 2) throw 0;
				if (input.size() == 1)
				{
					if ('0' > input[0] || input[0] > '9')
						throw 0;
					else  throw 1;
				}
				else if (input.size() == 2)
				{
					if ('1' > input[0] || input[0] > '1' || '0' > input[1] || input[1] > '2')
						throw 0;
					else  throw 1;
				}
			}
			catch (int i) { if (i) break; }
		} while (true);
		Label::_tag();
		switch (stoi(input))
		{
		case 0: cout << "Хорошего дня!"; _getch(); file.close(); return;
		case 1: { UsersPossibilities::checkBalance(file); }break;
		case 2: { UsersPossibilities::addMoney(enter,file); }break;
		case 3: { UsersPossibilities::getMoney(enter, file); }break;
		case 4: { UsersPossibilities::credit(enter, file); }break;
		case 5: { UsersPossibilities::historyofOperations(file); }break;
		case 6: { UsersPossibilities::changePassword(enter, file); }break;
		case 7: { AdminsPossibilities::increacetoAdmin(file); }break;
		case 8: { AdminsPossibilities::freeze(); }break;
		case 9: { AdminsPossibilities::thawed(); }break;
		case 10: {AdminsPossibilities::changeAdmin(enter, file); }break;
		case 11: {AdminsPossibilities::userlist(); }break;
		case 12: {AdminsPossibilities::check_User(); }break;
		}
		_getch();
		Label::_tag();
	} while (true);
}