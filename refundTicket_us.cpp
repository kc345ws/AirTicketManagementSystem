#include"User.h"
#include"UserTicket.h"
#include"Flight.h"
extern Flight* FLIGHT_WAIT;
//用户退票
void User::refundTicket_us() {
	User UI;
	Flight F;
	string refunddata;//要退票的航班号
	string refundnum;//要退票的航班航班号
	string refundtime;//要退票的航班起降时间
	LoginedUser->mg->userTicket->load_ut();//加载用户机票信息
	//LoginedUser->mg->userTicket->showTickets(false);//显示用户已购买机票
	UserTicket::Ticket* tempticket = LoginedUser->mg->userTicket->sentine->next;
	bool isfound = false;
	system("cls");
	LoginedUser->mg->userTicket->showTickets(false);
	UI.print_item(23);
	cout << "请输入要退票的航班日期" << endl;
	cin >> refunddata;
	cout << "请输入要退票的航班号" << endl;
	cin >> refundnum;
	cout << "请输入要退票的起降时间" << endl;
	cin >> refundtime;
	while (tempticket) {
		if (tempticket->data == refunddata && tempticket->num == refundnum && tempticket->time == refundtime) {
			F.change_finum(tempticket->Ticketcount, tempticket->data, tempticket->num, tempticket->time);//更改航班剩余机票数量
			LoginedUser->mg->userTicket->delete_ut(tempticket->data, tempticket->num, tempticket->time);//从用户机票信息删除该机票
			isfound = true;

			
			responseRefund_us(tempticket->data, tempticket->num, refundtime);//当有用户退票成功时,响应用户抢票请求

			break;
		}
		tempticket = tempticket->next;
	}
	
	if (isfound) {
		cout << "退票成功" << endl;
		cout << "按任意键返回主界面" << endl;
		getchar();
		getchar();
		login_uf();
	}
	else {
		cout << "退票失败，你没有购买相应航班的机票" << endl;
		cout << "按任意键返回主界面" << endl;
		getchar();
		getchar();
		login_uf();
	}
}