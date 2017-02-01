#pragma once

class Registratoin
{
public:

	//Индикатор доступа
	bool Access = false;

	//Ник в MD5
	string nickname_md5 = "";

private:

	//Проверка на то, знает ли Админ код или нет. Если нет - то он Пользователь
	bool access();

	//Проверка на неповторение логинов
	bool similarLogin(std::string logpass, bool rights);

	//Проверка ввода пароля
	void checkPassword(fstream &file);

	//Регистрация
	void signUp();

public:

	//Преобразование пароля в звёздочки
	string zvezda(string text = "");

	//Авторизация
	fstream logIn(bool &Access, bool change);

	//Вход в систему
	fstream signIn();
};