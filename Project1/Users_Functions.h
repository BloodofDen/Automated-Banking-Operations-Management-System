#pragma once

class UsersPossibilities
{
private:

	//������� �������� ����� ��� ���������� ����������
	template<typename Type> fstream refreshFile(Registratoin *&enter, fstream &file, Type changes, int string_number);
	
	//������� �������� ����� �������
	string checking_input(string str);

	//������������� ������� �������� ����� �������
	string checking_input(string str, string str1, string str2);

	//����� ����� ������
	void creditNew(Registratoin *&enter, fstream &file);

	//��������� ������
	void crediPay(Registratoin *&enter, fstream &file);

protected:

	//�������, ��������������� ��������� �� ���������� � ������ n-��� ������
	void numberofstring(fstream &file, int n);

	//�������� �������	
	int checkBalance(fstream &file);
	
	//�������� ������
	void addMoney(Registratoin *&enter, fstream &file);
	
	//����� ������
	void getMoney(Registratoin *&enter, fstream &file);
	
	//����� ������� ������� ���������� creditnew � creditold 
	void credit(Registratoin *&enter, fstream &file);
	
	//�������� ������
	void changePassword(Registratoin *&enter, fstream &file);
	
	//������� ��������
	void historyofOperations(fstream &file);

public:

	//���������������� ����������
	void list(Registratoin *&enter, fstream &file);
};