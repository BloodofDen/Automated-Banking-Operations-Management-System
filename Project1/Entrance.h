#pragma once

class Registratoin
{
public:

	//��������� �������
	bool Access = false;

	//��� � MD5
	string nickname_md5 = "";

private:

	//�������� �� ��, ����� �� ����� ��� ��� ���. ���� ��� - �� �� ������������
	bool access();

	//�������� �� ������������ �������
	bool similarLogin(std::string logpass, bool rights);

	//�������� ����� ������
	void checkPassword(fstream &file);

	//�����������
	void signUp();

public:

	//�������������� ������ � ��������
	string zvezda(string text = "");

	//�����������
	fstream logIn(bool &Access, bool change);

	//���� � �������
	fstream signIn();
};