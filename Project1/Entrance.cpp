#include"Headers.h"

string Registratoin::zvezda(string text)
{
	do
	{
		char *pass = new char[16];
		pass[0] = '\0';
		char elem;
		size_t counter = 0;
		cout << "��� " << text << "������(�� 6 �� 16 ��������): ";
		do
		{
			elem = _getch();
			switch (elem)
			{
			case 8:
			{
				if (counter)
				{
					swap(pass[counter], pass[counter - 1]);
					counter--;
					cout << "\b \b";
				}
			}break;
			case 13:break;
			default:
			{
				if (counter < 15)
				{
					swap(pass[counter], pass[counter + 1]);
					pass[counter] = elem;
					cout << '*';
				}
				if (counter == 15)
				{
					pass[counter] = elem;
					cout << '*';
				}
				counter++;
			}
			}
			if (elem == 13) break;
			if (counter > 15) break;
		} while (true);
		if (counter < 6 || counter > 15)
		{
			if (counter < 6)
			{
				cout << endl << "������� �������� ������, ���������� ���������!" << endl << endl;
				delete[] pass;
			}
			if (counter > 15)
			{
				cout << endl << "������� ������� ������, ���������� ���������!" << endl << endl;
				delete[] pass;
			}
		}
		else
		{
			cout << endl;
			return (static_cast<string>(pass));
		}
	} while (true);
}

bool Registratoin::access()
{
	bool rights = false;
	int i = 3;
	do
	{
		string code = "";
		cout << "�������: " << i << endl;
		cout << "������� ��� �������: ";	
		try
		{
			cin >> code;
			if (code.size() != 3)
				   throw 0;
			if ('9' > code[0] || code[0] > '9' || '1' > code[1] || code[1] > '1' || '1' > code[2] || code[2] > '1')
				throw 0;
			else   throw 1;
		}
		catch (int a) 
		{ 
			if (a)
			{
				rights = true;
				break; 
			}
		i--;
		cerr << "��� ������� �� ������!\n" << endl;
		}
	} while (i>0);
	Label::_tag();
	if (rights) cout << "����������� ��������������: " << endl;
	else		cout << "����������� ������������: " << endl;
	return rights;
}

bool Registratoin::similarLogin(string logpass, bool rights)
{
	fstream file;
	if (rights)
		file.open("Administrators\\" + logpass, ios_base::in);
	else
		file.open("Users\\" + logpass, ios_base::in);
	bool exist = file.is_open();
	file.close();
	return (exist);
}

void Registratoin::checkPassword(fstream &file)
{
	if (!file.is_open())
	{
		Label::_tag();
		cerr << "���� �� ��� ������!" << endl;
		_getch();
		exit(EXIT_FAILURE);
	}
	string str = "";
	file.seekg(0, ios_base::beg);
	getline(file, str);
	string prompt = "";
	bool prompt_bool = true;
	do
	{
		string password = Registratoin::zvezda();
		password = md5(password);
		if (str != password)
		{
			cerr << "������ ����� �� �����, ����������, ���������!" << endl;
			cout << "���������: ";
			if (prompt_bool)
			{
				getline(file, prompt);
				prompt_bool = false;
			}
			cout << prompt << endl << endl;
		}
		else
		{
			Label::_tag();
			file.seekg(0, ios::beg);
			string freeze = "";
			for (int i(0); i < 5; i++)
				getline(file, freeze);
			if (freeze[0] == '1')
			{
				cerr << "��� ������� ������������!\n��� ������� ���������� � ��������������!";
				_getch();
				exit(EXIT_SUCCESS);
			}
			cout << "���� �������� �������!";
			break;
		}
	} while (true);
}

void Registratoin::signUp()
{
	string input = "";
	bool acc = false;
	do
	{
		Label::_tag();
		cout << "<0> - ������������������ ��� ������������\n<1> - ������������������ ��� �������������\n--> ";
		try
		{
			cin >> input;
			if (input.size() > 1 || '0' > input[0] || input[0] > '1') throw 0;
			else                                                      throw 1;
		}
		catch (int i) { if (i) break; }
	} while (true);
	Label::_tag();
	if (stoi(input))
		acc = Registratoin::access();
	else
		cout << "����������� ������������: " << endl;
	string logpass = "";
	string userlist = "";
	bool is_similar;
	do
	{
		cout << "��� �����: ";
		cin >> logpass;
		userlist = logpass;
		logpass = md5(logpass);
		if (is_similar = similarLogin(logpass, acc))
		{
			cerr << "����� ����� ��� ����������! ����������, ���������!";
			Label::_tag();
		}
	} while (is_similar);
	fstream file;
	if (acc)
		file.open("Administrators\\" + logpass, ios_base::out);
	else {
		file.open("userlist", ios_base::out | ios_base::app);
		file << userlist << endl;
		file.close();
		file.open("Users\\" + logpass, ios_base::out);
	}
	if (!file.is_open())
	{
		cerr << "���� �� ����� ���� ������!" << endl;
		_getch();
	}
	do
	{
		logpass = Registratoin::zvezda();
		cout << "��������� ������ ��� ���" << endl;
		string check = Registratoin::zvezda();
		if (check != logpass)
			cerr << "������ �� �������, ���������� ���������!\n" << endl;
		else break;
	} while (true);
	file << md5(logpass) << endl;
	cout << endl << "��������� � ������(���� �� �������� ������, ��� ����������� ���������): ";
	char *prompt = new char[20];
	cin >> prompt;
	file << static_cast<string>(prompt) << endl << "0" << endl << "0" << endl << "0";
	Label::_tag();
	if (acc) cout << "������������� ������� ���������������!";
	else     cout << "������������ ������� ���������������!";
	file.close();
}

fstream Registratoin::logIn(bool &Access, bool change)
{
	if (change)
	{
		string input = "";
		do
		{
			Label::_tag();
			cout << "<0> - ����� ��� ������������\n<1> - ����� ��� �������������\n--> ";
			try
			{
				cin >> input;
				if (input.size() > 1 || '0' > input[0] || input[0] > '1') throw 0;
				else                                                      throw 1;
			}
			catch (int i) { if (i) break; }
		} while (true);
		if (stoi(input))
			Access = true;
		Label::_tag();
	}
	string login;
	cout << "��� �����: ";
	cin >> login;
	login = md5(login);
	fstream file;
	if (Access) file.open("Administrators\\" + login);
	else        file.open("Users\\" + login);
	if (!(file.is_open()))
	{
		Label::_tag();
		if(Access)	cerr << "������ �������������� �� ����������, �������� �����������!";
		else        cerr << "������ ������������ �� ����������, �������� �����������!";
		Access = false;
		file.close();
		return file;
	}
	else
	{
		file.close();
		if (Access)
			file.open("Administrators\\" + login, ios_base::in | ios_base::out);
		else
			file.open("Users\\" + login, ios_base::in | ios_base::out);
	}
	Registratoin::checkPassword(file);
	nickname_md5 = login;
	return file;
}

fstream Registratoin::signIn()
{
	string input = "";
	do
	{
		Label::_tag();
		cout << "������������, ��� ������������ ������� \"���������\"" << endl;
		cout << "\n<0> - \"����������\" ;(\n<1> - \"�������\" :)\n--> ";
		try
		{
			cin >> input;
			if (input.size() > 1 || '0' > input[0] || input[0] > '1') throw 0;
			else                                                      throw 1;
		}
		catch (int i) { if (i) break; }
	} while (true);
	if (!stoi(input))
	{
		Label::_tag();
		cout << "�������� ���!:)";
		_getch();
		exit(EXIT_SUCCESS);
	}
	_mkdir("Administrators");
	_mkdir("Users");
	fstream file;
	do
	{
		do
		{
			Label::_tag();
			cout << "<0> - ������ �����������\n<1> - ���� � ������� ������\n--> ";
			try
			{
				cin >> input;
				if (input.size() > 1 || '0' > input[0] || input[0] > '1') throw 0;
				else                                                      throw 1;
			}
			catch (int i) { if (i) break; }
		} while (true);
		if (!stoi(input)) Registratoin::signUp();
		else       file = Registratoin::logIn(Access, true);
		_getch();
		Label::_tag();
		if (file.is_open()) break;
	} while (true);
	return file;
}