#include"User.h"
#include"UserTicket.h"
#include"Flight.h"
extern Flight* FLIGHT_WAIT;
//�û���Ʊ
void User::refundTicket_us() {
	User UI;
	Flight F;
	string refunddata;//Ҫ��Ʊ�ĺ����
	string refundnum;//Ҫ��Ʊ�ĺ��ຽ���
	string refundtime;//Ҫ��Ʊ�ĺ�����ʱ��
	LoginedUser->mg->userTicket->load_ut();//�����û���Ʊ��Ϣ
	//LoginedUser->mg->userTicket->showTickets(false);//��ʾ�û��ѹ����Ʊ
	UserTicket::Ticket* tempticket = LoginedUser->mg->userTicket->sentine->next;
	bool isfound = false;
	system("cls");
	LoginedUser->mg->userTicket->showTickets(false);
	UI.print_item(23);
	cout << "������Ҫ��Ʊ�ĺ�������" << endl;
	cin >> refunddata;
	cout << "������Ҫ��Ʊ�ĺ����" << endl;
	cin >> refundnum;
	cout << "������Ҫ��Ʊ����ʱ��" << endl;
	cin >> refundtime;
	while (tempticket) {
		if (tempticket->data == refunddata && tempticket->num == refundnum && tempticket->time == refundtime) {
			F.change_finum(tempticket->Ticketcount, tempticket->data, tempticket->num, tempticket->time);//���ĺ���ʣ���Ʊ����
			LoginedUser->mg->userTicket->delete_ut(tempticket->data, tempticket->num, tempticket->time);//���û���Ʊ��Ϣɾ���û�Ʊ
			isfound = true;

			
			responseRefund_us(tempticket->data, tempticket->num, refundtime);//�����û���Ʊ�ɹ�ʱ,��Ӧ�û���Ʊ����

			break;
		}
		tempticket = tempticket->next;
	}
	
	if (isfound) {
		cout << "��Ʊ�ɹ�" << endl;
		cout << "�����������������" << endl;
		getchar();
		getchar();
		login_uf();
	}
	else {
		cout << "��Ʊʧ�ܣ���û�й�����Ӧ����Ļ�Ʊ" << endl;
		cout << "�����������������" << endl;
		getchar();
		getchar();
		login_uf();
	}
}