//����Աɾ��������Ϣ
#include "Flight.h"
#include "User.h"
#include <iostream>

void Flight::delete_fi() {
	int i = 0;
	User U_AI;

	system("cls");

	load_fil();				//���ļ��к�����Ϣװ�ص�����
	//input_fi();				//����Ҫ��ӵĺ�����Ϣ
	//Inser_fi();				//�Ѻ�����Ϣ������˳���������
	browse_fi(false);
	char data_del[9];//ɾ�����������
	char num_del[10];//ɾ������ĺ����
	char start_del[12];//ɾ���������ʼʱ��
	char end_del[12];//ɾ������Ľ���ʱ��
	U_AI.print_item(15);//��ӡ����ɾ������
	cout << "������Ҫɾ�����������(��:20190430)" << endl;
	cin >> data_del;
	cout << "������Ҫɾ������ĺ����(��:MU5235)" << endl;
	cin >> num_del;
	cout << "������Ҫɾ���������ɵص�(��:����)" << endl;
	cin >> start_del;
	cout << "������Ҫɾ������Ľ���ص�(��:����)" << endl;
	cin >> end_del;

	fi = flight;//��ֵ�ڱ����
	FlightInfo* tail= flight;//�м����
	//fstream f_file;
	bool isdel = false;//�Ƿ�ɹ�ɾ��
	/*f_file.open("flight.txt", ios::in);
	if (!f_file) {
		cout << "��ȡ������Ϣʧ��" << endl;
		return;
	}*/
	while (fi) {
		//f_file >> fi->data >> fi->num >> fi->start >> fi->end >> fi->time >> fi->at >> fi->count >> fi->price;

		if (strcmp(data_del, fi->data) == 0 && strcmp(num_del, fi->num) == 0
			&& strcmp(start_del, fi->start) == 0 && strcmp(end_del, fi->end) == 0) {

			tail->next = fi->next;
			delete fi;
			cout << "ɾ���ɹ�" << endl;
			isdel = true;
			break;
		}
		tail = fi;
		fi = fi->next;
		i++;
	}

	//f_file.close();

	if (isdel) {//���ɾ���ɹ�
		save_fil();				//���º�����Ϣ�����浽�ļ�

		--flight_num;			//��������1
		save_fn();				//���溽������

		cout << "\n���ڽ��к�����Ϣɾ��..." << endl;
		Sleep(2000);
		system("cls");
		cout << "������Ϣɾ���ɹ�!" << endl;
		cout << "������ת����Ϣ����ϵͳ��ҳ..." << endl;
		Sleep(2000);
		system("cls");
		U_AI.login_mf();
	}
	else {
		cout << "û�в�ѯ����Ӧ����ɾ��ʧ�ܣ��Ƿ����ɾ��?(y/n)" << endl;
		char choice;
		cin >> choice;
		switch (choice)
		{
		case 'y':
			delete_fi();
			cout << "�������¿�ʼɾ��..." << endl;
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