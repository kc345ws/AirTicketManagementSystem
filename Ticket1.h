#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

class Flight
{
//public:
public :
	struct FlightInfo
	{
		char data[9];				//航班日期
		char num[10];				//航班号
		char start[12];				//起始地
		char end[12];				//目的地
		char time[16];				//起降时间
		char at[6];					//飞行时间
		int count;					//票数
		double price;				//票价
		struct FlightInfo *next;	//指向下一个航班信息
		struct FlightInfo *prior;	//指向前一个航班信息

	/*public:
		void setdata(char chagdata[]) { 
			for (int i = 0; i < strlen(data); i++) {
				data[i] = chagdata[i];
			}
		};
		void setnum(char chagnum[]) {
			for (int i = 0; i < strlen(num); i++) {
				num[i] = chagnum[i];
			}
		};
		void setstart(char chagstart[]) {
			for (int i = 0; i < strlen(start); i++) {
				start[i] = chagstart[i];
			}
		};
		void setend(char chagend[]) {
			for (int i = 0; i < strlen(end); i++) {
				end[i] = chagend[i];
			}
		};
		void settime(char chagtime[]) {
			for (int i = 0; i < strlen(time); i++) {
				time[i] = chagtime[i];
			}
		};
		void setat(char chagtime[]) {
			for (int i = 0; i < strlen(at); i++) {
				at[i] = chagtime[i];
			}
		};
		void setcount(int chagcount) {
			count = chagcount;
		};
		void setprice(double chagprice) {
			price = chagprice;
		};*/
	}*flight,*fi,*fn,*fg;
//flight初始化哨兵结点 fi从文件读取时创建的 fn输入航班信息时创建的 
public:	
	int flight_num;					//所有航班数

	public:
		Flight();
		~Flight();
		void destroy(FlightInfo *&F);					//释放链表

		void init_fnf();								//初始化记录数量的文件user_num.txt
		void current_time();							//当前时间
		void input_fi();								//输入航班信息
		void input_sfi(int note,int note1,int note2);	//输入需查找的航班信息
	//	void save_fitf(FlightInfo *userinfo);			//保存航班信息到文件
		void load_fil();								//把文件中航班信息装载到链表
		void save_fil();								//保存链表中航班信息到文件中
		void Inser_fi();								//把航班信息按日期顺序插入链表

		void add_fi();			//添加航班信息
		//void browse_fi(); 		//浏览航班信息
		void browse_fi(bool isback); 		//浏览航班信息
		//	void save_fi();		//保护航班信息,防止信息丢失
		//	bool load_fi();		//读取航班信息
		void sort_byfp();		//全部航班按票价降序显示
		void search_fi();		//按航班号查找航班信息
		void order();			//订票

		void delete_fi();//删除航班信息
		void change_fi();//修改航班信息

		void save_fn();			//保存航班总数
		int load_fn();			//读取航班总数
		void save_lfui1();		//保存登录系统的用户信息
		int load_lfui1();		//读取登录系统的用户信息
		//	void load_bfi();	//读取二进制形式保存的航班信息文件内容
		friend class UserInfo;

		FlightInfo*getFlightinfo() { return fi; };
};																			