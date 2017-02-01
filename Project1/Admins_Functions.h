#pragma once

class AdminsPossibilities:protected UsersPossibilities
{
private:

	//Основная функция заморозки/разиорозки Пользователя
	void for_freeze_thawed(string str1, string str2, char ch);

	//Повысить Пользователя до Администратора
	void increacetoAdmin(fstream &file);

	//Сменить Администратора
	void changeAdmin(Registratoin *&enter, fstream &file);

	//Список всех пользователей
	void userlist();

	//Заморозка
	void freeze() { for_freeze_thawed("блокировки", "заблокирован", '1'); }

	//Разморозка
	void thawed() { for_freeze_thawed("разблокировки", "разблокирован", '0'); }
	
	//Проверка существования пользователя
	void check_User();

public:

	//Полный функционал Администратора
	void list(Registratoin *&enter, fstream &file);
};