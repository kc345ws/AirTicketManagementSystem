#include"Flight.h"
#include"User.h"
#include<iostream>

void isContinue(char ch);
char issucced();
void isWrong();
void changechar(char ch[], int changeobjID, Flight::FlightInfo* info);
//�޸ĺ�����Ϣ
void Flight::change_fi() {
	system("cls");
	User U_AI;
	browse_fi(false);
	char data_del[9];//�޸ĺ��������
	char num_del[10];//�޸ĺ���ĺ����
	char start_del[12];//�޸ĺ������ʼʱ��
	char end_del[12];//�޸ĺ���Ľ���ʱ��

	U_AI.print_item(16);//��ӡ�����޸ı���
	cout << "������Ҫ�޸ĺ��������(��:20190430)" << endl;
	cin >> data_del;
	cout << "������Ҫ�޸ĺ���ĺ����(��:MU5235)" << endl;
	cin >> num_del;
	cout << "������Ҫ�޸ĺ������ɵص�(��:����)" << endl;
	cin >> start_del;
	cout << "������Ҫ�޸ĺ���Ľ���ص�(��:����)" << endl;
	cin >> end_del;

	fi = flight;//��ֵ�ڱ����
	FlightInfo* tail = flight;//�м����
	bool ischange = false;//�Ƿ�ɹ��޸�

	char changedinfo[20];
	int changedcount;
	double changeprice;
	FlightInfo* saveinfo = fi;//����ִ����save_fil()��ָ�fiָ��
	while (fi) {

		if (strcmp(data_del, fi->data) == 0 && strcmp(num_del, fi->num) == 0
			&& strcmp(start_del, fi->start) == 0 && strcmp(end_del, fi->end) == 0) {

			ischange = true;
			int choice;
			char yorno;
			while (1) {
				U_AI.print_item(17);//��ӡ�����޸Ĳ�������
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "������Ҫ�޸ĵĺ�������" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 1,fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 2:
					cout << "������Ҫ�޸ĵĺ����" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 2, fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 3:
					cout << "������Ҫ�޸ĵ���ɵص�" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 3, fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 4:
					cout << "������Ҫ�޸ĵĽ���ص�" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 4, fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 5:
					cout << "������Ҫ�޸ĵ���ʱ��" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 5, fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 6:
					cout << "������Ҫ�޸ĵ�Ԥ�Ʒ���ʱ��" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 6, fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 7:
					cout << "������Ҫ�޸ĵ�Ԥ��ʣ��Ʊ��" << endl;
					cin >> changedcount;
					if (changedinfo != nullptr) {
						fi->count = changedcount;
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 8:
					cout << "������Ҫ�޸ĵ�Ʊ��" << endl;
					cin >> changeprice;
					if (changedinfo != nullptr) {
						fi->price = changeprice;
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 0:
					U_AI.login_mf();
					break;
				default:
					isWrong();
				}
			}
			break;
		}
		tail = fi;
		fi = fi->next;
		saveinfo = fi;
	}

	if (ischange) {//����޸ĳɹ�
		save_fil();				//���º�����Ϣ�����浽�ļ�

		cout << "\n���ڽ��к�����Ϣ�޸�..." << endl;
		Sleep(2000);
		system("cls");
		cout << "������Ϣ�޸ĳɹ�!" << endl;
		cout << "������ת����Ϣ����ϵͳ��ҳ..." << endl;
		Sleep(2000);
		system("cls");
		U_AI.login_mf();
	}
	else {
		cout << "û�в�ѯ����Ӧ�����޸�ʧ�ܣ��Ƿ�����޸�?(y/n)" << endl;
		char choice;
		cin >> choice;
		switch (choice)
		{
		case 'y':
			change_fi();
			cout << "�������¿�ʼ�޸�..." << endl;
			Sleep(2000);
			system("cls");
			break;
		default:
			cout << "������ת����Ϣ����ϵͳ��ҳ..." << endl;
			Sleep(2000);
			system("cls");
			U_AI.login_mf();
			break;
		}
	}
}

void isContinue(char ch) {//�Ƿ�����޸�
	User U_AI;
	switch (ch) {
	case 'y':
		break;
	default:
		cout << "����������Ϣ�������..." << endl;
		Sleep(2000);
		U_AI.login_mf();
		break;
	}
}

void isWrong() {//����޸�ʧ��
	cout << "������Ϣ����" << endl;
	cout << "�Ƿ�����޸�?(y/n)" << endl;
	char yorno;
	cin >> yorno;
	isContinue(yorno);
}

char issucced() {//����޸ĳɹ�
	char yorno;
	cout << "�޸ĳɹ�" << endl;
	cout << "�Ƿ�����޸�?(y/n)" << endl;
	cin >> yorno;
	return yorno;
}

void changechar(char ch[],int changeobjID, Flight::FlightInfo* info) {//�޸�char���͵�����

	if (changeobjID == 1) {//���Ҫ�޸ĺ�������
		for (int i = 0; i < strlen(ch); i++) {
			info->data[i] = ch[i];
		}
	}
	else if (changeobjID == 2) {
		for (int i = 0; i < strlen(ch); i++) {
			info->num[i] = ch[i];
		}
	}
	else if (changeobjID == 3) {
		for (int i = 0; i < strlen(ch); i++) {
			info->start[i] = ch[i];
		}
	}
	else if (changeobjID == 4) {
		for (int i = 0; i < strlen(ch); i++) {
			info->end[i] = ch[i];
		}
	}
	else if (changeobjID == 5) {
		for (int i = 0; i < strlen(ch); i++) {
			info->time[i] = ch[i];
		}
	}
	else if (changeobjID == 6) {
		for (int i = 0; i < strlen(ch); i++) {
			info->at[i] = ch[i];
		}
	}
}

void Flight::change_finum(int num, char data_ch[], char num_ch[], char time_ch[]) {
	system("cls");
	load_fil();
	fi = flight->next;//��ֵ�ڱ����
	FlightInfo* tail = flight;//�м����
	bool ischange = false;//�Ƿ�ɹ��޸�

	char changedinfo[20];
	int changedcount;
	double changeprice;
	FlightInfo* saveinfo = fi;//����ִ����save_fil()��ָ�fiָ��


	while (fi) {

		if (strcmp(data_ch, fi->data) == 0 && strcmp(num_ch, fi->num) == 0
			&& strcmp(time_ch, fi->time) == 0) {
			ischange = true;
			fi->count += num;//�����û���Ʊ������
			break;
		}
		tail = fi;
		fi = fi->next;
		saveinfo = fi;
	}

	if (ischange) {//����޸ĳɹ�
		save_fil();	//���º�����Ϣ�����浽�ļ�
	}
}
