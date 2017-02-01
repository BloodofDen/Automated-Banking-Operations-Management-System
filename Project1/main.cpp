#include "Headers.h"

int main()
{
	setlocale(0, "rus");
	Registratoin *enter = new Registratoin();
	fstream file = enter->signIn();
	if (enter->Access)
	{
		AdminsPossibilities *admin = new AdminsPossibilities();
		admin->list(enter, file);
		delete admin;
	}
	else
	{
		UsersPossibilities *user = new UsersPossibilities();
		user->list(enter, file);
		delete user;
	}
	delete enter;
	return 0;
}