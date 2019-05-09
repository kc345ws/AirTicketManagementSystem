#include "Flight.h"
#include "User.h"
#include <iostream>
#include<iomanip>

using namespace std;

void Flight::browse_fi(bool isback) 	//���������Ϣ
{
	User U_AI;
	
	system("cls");
	U_AI.print_item(11);
	if((flight_num=load_fn())==0)		//�жϺ�����Ϣ�Ƿ�Ϊ��
	{
		cout<<"�޺�����Ϣ�ɹ���ʾ!"<<endl;
		Sleep(2000);
	}
	else	//��������Ϣ��Ϊ��ʱ������ִ�����²���
	{
		cout<<"�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����"<<endl;
		load_fil();
		fi=flight->next;
		while(fi!=NULL)
		{
			cout.setf(ios::left);
			cout<< setw(8) <<fi->data<<" "<< setw(7) <<fi->num<<" "<< setw(5) <<fi->start<<"\t"<< setw(5) <<fi->end<<"\t"<< 
				setw(11) <<fi->time<<"\t"<< setw(3) <<fi->at << "����" <<"    "<< setw(4) <<fi->count<<"  "<< setw(5) <<fi->price<<"  "
				<< setw(5) <<fi->transit<< "\t"<<setw(3) <<fi->transittime<<"����"<<"   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			fi=fi->next;
		}
		
	}

	if (isback) {
		cin.sync();
		cout << "\n\n������������ػ�Ʊ����ϵͳ��ҳ\n";
		getchar();
		getchar();
		system("cls");
		U_AI.mode = U_AI.load_mode();
		if (U_AI.mode == 1)
			U_AI.login_mf();
		else if (U_AI.mode == 0)
			U_AI.login_uf();
	}
}

/*void Flight::browse_fi_priceLTH() {//����Ʊ�Ӹߵ�������
	User U_AI;

	system("cls");
	U_AI.print_item(11);
	if ((flight_num = load_fn()) == 0)		//�жϺ�����Ϣ�Ƿ�Ϊ��
	{
		cout << "�޺�����Ϣ�ɹ���ʾ!" << endl;
		Sleep(2000);
	}
	else	//��������Ϣ��Ϊ��ʱ������ִ�����²���
	{
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		load_fil();
		Flight::FlightInfo* LTHPrice = new Flight::FlightInfo();
		Flight::FlightInfo* Tempinfo = flight->next;
		Flight::FlightInfo* frontLTH = LTHPrice;
		Flight::FlightInfo* firstLTH = LTHPrice;
		//LTHPrice->next = new Flight::FlightInfo();
		//LTHPrice = LTHPrice->next;
		LTHPrice->price = 0;
		while (Tempinfo) {
			if (Tempinfo->price > LTHPrice->price) {
				//LTHPrice->next = Tempinfo;
				LTHPrice->next = new Flight::FlightInfo();
				LTHPrice = LTHPrice->next;
				for (int i = 0; i < size(Tempinfo->data); i++) {
					LTHPrice->data[i] = Tempinfo->data[i];
				}
				for (int i = 0; i < size(Tempinfo->num);i++) {
					LTHPrice->num[i] = Tempinfo->num[i];
				}
				for (int i = 0; i < size(Tempinfo->start); i++) {
					LTHPrice->start[i] = Tempinfo->start[i];
				}
				for (int i = 0; i < size(Tempinfo->end); i++) {
					LTHPrice->end[i] = Tempinfo->end[i];
				}
				for (int i = 0; i < size(Tempinfo->time); i++) {
					LTHPrice->time[i] = Tempinfo->time[i];
				}
				for (int i = 0; i < size(Tempinfo->at); i++) {
					LTHPrice->at[i] = Tempinfo->at[i];
				}
				LTHPrice->count = Tempinfo->count;
				LTHPrice->price = Tempinfo->price;
				LTHPrice->transit = Tempinfo->transit;
				LTHPrice->transittime = Tempinfo->transittime;
				LTHPrice->isDelay = Tempinfo->isDelay;
			}
			else {
				frontLTH->next = new Flight::FlightInfo();
				frontLTH = frontLTH->next;
				frontLTH->next = LTHPrice;

				for (int i = 0; i < size(Tempinfo->data); i++) {
					frontLTH->data[i] = Tempinfo->data[i];
				}
				for (int i = 0; i < size(Tempinfo->num); i++) {
					frontLTH->num[i] = Tempinfo->num[i];
				}
				for (int i = 0; i < size(Tempinfo->start); i++) {
					frontLTH->start[i] = Tempinfo->start[i];
				}
				for (int i = 0; i < size(Tempinfo->end); i++) {
					frontLTH->end[i] = Tempinfo->end[i];
				}
				for (int i = 0; i < size(Tempinfo->time); i++) {
					frontLTH->time[i] = Tempinfo->time[i];
				}
				for (int i = 0; i < size(Tempinfo->at); i++) {
					frontLTH->at[i] = Tempinfo->at[i];
				}
				frontLTH->count = Tempinfo->count;
				frontLTH->price = Tempinfo->price;
				frontLTH->transit = Tempinfo->transit;
				frontLTH->transittime = Tempinfo->transittime;
				frontLTH->isDelay = Tempinfo->isDelay;
			}
			Tempinfo = Tempinfo->next;
		}
		//f_file >> fi->data >> fi->num >> fi->start >> fi->end >> fi->time >> fi->at >> fi->count >> fi->price >> fi->transit >> fi->transittime >> fi->isDelay;

		//fi = flight->next;
		firstLTH = firstLTH->next;
		while (firstLTH)
		{
			cout.setf(ios::left);
			cout << setw(8) << firstLTH->data << " " << setw(7) << firstLTH->num << " " << setw(5) << firstLTH->start << "\t" << setw(5) << firstLTH->end << "\t" <<
				setw(11) << firstLTH->time << "\t" << setw(3) << firstLTH->at << "����" << "    " << setw(4) << firstLTH->count << "  " << setw(5) << firstLTH->price << "  "
				<< setw(5) << firstLTH->transit << "\t" << setw(3) << firstLTH->transittime << "����" << "   ";
			if (firstLTH->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			firstLTH = firstLTH->next;
		}	
	}
		
		cin.sync();
		cout << "\n\n������������ػ�Ʊ����ϵͳ��ҳ\n";
		getchar();
		getchar();
		system("cls");
		U_AI.mode = U_AI.load_mode();
		if (U_AI.mode == 1)
			U_AI.login_mf();
		else if (U_AI.mode == 0)
			U_AI.login_uf();
}*/


void Flight::browse_fi_priceLTH()	//Ʊ������
{
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              ���ఴƱ��������ʾ                           #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*�Ժ�����Ϣ��Ʊ�۽�������*/
		f_ai = new FlightInfo;
		f_ai = flight;//�ڱ��ڵ�
		fi = f_ai->next->next;//�ڶ�����Ч���
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//���ȸ�ֵ��һ����Ч���
			fn = f_ai;//�ڱ��ڵ�
			while (fn->next != NULL && fn->next->price < fi->price)//�ҵ�һ����fi->price��Ľ��
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*�������*/
		//cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��\t��Ʊ��\tƱ��" << endl;
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << "   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n����������ػ�Ʊ����ϵͳ��ҳ." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "û�к�����Ϣ!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_atLTH()
{
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              ���ఴ����ʱ��������ʾ                       #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*�Ժ�����Ϣ��Ʊ�۽�������*/
		f_ai = new FlightInfo;
		f_ai = flight;//�ڱ��ڵ�
		fi = f_ai->next->next;//�ڶ�����Ч���
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//���ȸ�ֵ��һ����Ч���
			fn = f_ai;//�ڱ��ڵ�
			int tempa = atoi(fn->next->at);
			int tempb = atoi(fi->at);
			while (fn->next != NULL && tempa < tempb) {
				fn = fn->next;
				if (fn->next) {
					tempa = atoi(fn->next->at);
					tempb = atoi(fi->at);
				}
			}
				
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*�������*/
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << "   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n����������ػ�Ʊ����ϵͳ��ҳ." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "û�к�����Ϣ!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_atHTL() {
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              ���ఴ����ʱ�併����ʾ                       #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*�Ժ�����Ϣ��Ʊ�۽�������*/
		f_ai = new FlightInfo;
		f_ai = flight;//�ڱ��ڵ�
		fi = f_ai->next->next;//�ڶ�����Ч���
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//���ȸ�ֵ��һ����Ч���
			fn = f_ai;//�ڱ��ڵ�
			int tempa = atoi(fn->next->at);
			int tempb = atoi(fi->at);
			while (fn->next != NULL && tempa > tempb)
			{
				fn = fn->next;
				if (fn->next) {
					tempa = atoi(fn->next->at);
					tempb = atoi(fi->at);
				}
			}
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*�������*/
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << "   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n����������ػ�Ʊ����ϵͳ��ҳ." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "û�к�����Ϣ!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_countLTH()
{
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              ���ఴ��Ʊ��������ʾ                         #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*�Ժ�����Ϣ��Ʊ�۽�������*/
		f_ai = new FlightInfo;
		f_ai = flight;//�ڱ��ڵ�
		fi = f_ai->next->next;//�ڶ�����Ч���
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//���ȸ�ֵ��һ����Ч���
			fn = f_ai;//�ڱ��ڵ�
			while (fn->next != NULL && fn->next->count < fi->count)
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*�������*/
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << "   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n����������ػ�Ʊ����ϵͳ��ҳ." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "û�к�����Ϣ!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_countHTL() {
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              ���ఴ��Ʊ��������ʾ                         #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*�Ժ�����Ϣ��Ʊ�۽�������*/
		f_ai = new FlightInfo;
		f_ai = flight;//�ڱ��ڵ�
		fi = f_ai->next->next;//�ڶ�����Ч���
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//���ȸ�ֵ��һ����Ч���
			fn = f_ai;//�ڱ��ڵ�
			while (fn->next != NULL && fn->next->count > fi->count)//�ҵ�һ����fi->price��Ľ��
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*�������*/
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << "   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n����������ػ�Ʊ����ϵͳ��ҳ." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "û�к�����Ϣ!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_transtimeLTH()
{
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              ���ఴ��תʱ��������ʾ                       #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*�Ժ�����Ϣ��Ʊ�۽�������*/
		f_ai = new FlightInfo;
		f_ai = flight;//�ڱ��ڵ�
		fi = f_ai->next->next;//�ڶ�����Ч���
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//���ȸ�ֵ��һ����Ч���
			fn = f_ai;//�ڱ��ڵ�
			while (fn->next != NULL && fn->next->transittime < fi->transittime)//�ҵ�һ����fi->price��Ľ��
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*�������*/
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << "   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n����������ػ�Ʊ����ϵͳ��ҳ." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "û�к�����Ϣ!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_transtimeHTL() {
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              ���ఴ��תʱ�併����ʾ                       #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*�Ժ�����Ϣ��Ʊ�۽�������*/
		f_ai = new FlightInfo;
		f_ai = flight;//�ڱ��ڵ�
		fi = f_ai->next->next;//�ڶ�����Ч���
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//���ȸ�ֵ��һ����Ч���
			fn = f_ai;//�ڱ��ڵ�
			while (fn->next != NULL && fn->next->transittime > fi->transittime)//�ҵ�һ����fi->price��Ľ��
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*�������*/
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << "   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n����������ػ�Ʊ����ϵͳ��ҳ." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "û�к�����Ϣ!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_dateLTH()
{
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              ���ఴ����������ʾ                           #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*�Ժ�����Ϣ��Ʊ�۽�������*/
		f_ai = new FlightInfo;
		f_ai = flight;//�ڱ��ڵ�
		fi = f_ai->next->next;//�ڶ�����Ч���
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//���ȸ�ֵ��һ����Ч���
			fn = f_ai;//�ڱ��ڵ�
			while (fn->next != NULL && strcmp(fn->next->data ,fi->data)<0)//�ҵ�һ����fi->price��Ľ��
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*�������*/
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << "   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n����������ػ�Ʊ����ϵͳ��ҳ." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "û�к�����Ϣ!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_dateHTL() {
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              ���ఴ���ڽ�����ʾ                           #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*�Ժ�����Ϣ��Ʊ�۽�������*/
		f_ai = new FlightInfo;
		f_ai = flight;//�ڱ��ڵ�
		fi = f_ai->next->next;//�ڶ�����Ч���
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//���ȸ�ֵ��һ����Ч���
			fn = f_ai;//�ڱ��ڵ�
			while (fn->next != NULL && strcmp(fn->next->data, fi->data) > 0)//�ҵ�һ����fi->price��Ľ��
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*�������*/
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << "   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n����������ػ�Ʊ����ϵͳ��ҳ." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "û�к�����Ϣ!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}


