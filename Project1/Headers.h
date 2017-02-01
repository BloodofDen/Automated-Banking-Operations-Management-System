#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<conio.h>
#include<ctime>
#include<direct.h>

using namespace std;

#include"md5.h"
#include"Entrance.h"
#include "Users_Functions.h"
#include "Admins_Functions.h"

class Label
{
public:
	static void _tag()
	{
		system("cls");
		cout << "\t\t" << "OAO \"ËÀÉØÀÁÀÍÊ\"" << endl;

		time_t presentTime = time(NULL);

		struct tm * timeInfo = localtime(&presentTime);
		cout << "Òåêóùåå âðåìÿ: ";
		if (timeInfo->tm_hour / 10 < 1) cout << '0';
		cout << timeInfo->tm_hour << ":";
		if (timeInfo->tm_min / 10 < 1) cout << '0';
		cout << timeInfo->tm_min << ":";
		if (timeInfo->tm_sec / 10 < 1) cout << '0';
		cout << timeInfo->tm_sec << endl << endl;
	}
};