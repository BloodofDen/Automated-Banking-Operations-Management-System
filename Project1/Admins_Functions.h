#pragma once

class AdminsPossibilities:protected UsersPossibilities
{
private:

	//�������� ������� ���������/���������� ������������
	void for_freeze_thawed(string str1, string str2, char ch);

	//�������� ������������ �� ��������������
	void increacetoAdmin(fstream &file);

	//������� ��������������
	void changeAdmin(Registratoin *&enter, fstream &file);

	//������ ���� �������������
	void userlist();

	//���������
	void freeze() { for_freeze_thawed("����������", "������������", '1'); }

	//����������
	void thawed() { for_freeze_thawed("�������������", "�������������", '0'); }
	
	//�������� ������������� ������������
	void check_User();

public:

	//������ ���������� ��������������
	void list(Registratoin *&enter, fstream &file);
};