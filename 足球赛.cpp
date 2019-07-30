#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
#include<stdlib.h>
#include<windows.h>
using namespace std;

void print(char a[])
{
	int i=0;
	for(i=0;a[i]!='\0';i++)
	{
		cout<<a[i];
		
	}
	cout<<endl;
}

class hero
{
private:
	char name[100];
	int HP;//体力值，进球比分与体力值有关//
	int AP;//精神值，只有精神值达到一定值才能组织某些进攻//
	int RP;//幸运值，决定射门和被扑的几率//
	int SP;//反击速度值，决定反击击的几率和连续组织进击的次数//
	int DA;//攻击值，和防御值一起决定消耗体力数值//
	int DF;//防守值，和武力值一起决定消耗体力数值//
public:
	//—————————————————初始化——————————————————————//
	//姓名初始化//
	void setname(char n[])
	{
		strcpy(name,n);
	};

	//属性初始化//
	void setnature()
	{
		HP=275+rand()%201;
		AP=0;
		RP=rand()%111;
		SP=rand()%121;
		DA=42+rand()%54;
		DF=rand()%101;
	}

	
	//————————————————————————反击—————————————————//
	void hit(hero &h)
	{
		int b2;
		int b1;
		int A=10+rand()%11;
		b1=rand()%20+DA*0.5-h.DF*0.1;
		b2=2*b1;
		
		int p=rand()%3; 
		
		if(p>=0 && p<=1)
		{
			cout<<name<<"组织反击";

			
			if(RP-h.RP>80)
			{
				cout<<"消耗了对手"<<b2<<"点体力值"<<endl;
				h.HP-=b2;
				h.AP+=A;
			}
			if(RP-h.RP>50 && RP-h.RP<=80)
			{
				int q=rand()%2;
				if(q==0)
				{
					cout<<"消耗了对手"<<b2<<"点体力值"<<endl;
					h.HP-=b2;
					h.AP+=A;
				}
				if(q==1)
				{
					cout<<"消耗了对手"<<b2<<"点体力值"<<endl;
					h.HP-=b1;
					h.AP+=A;
				}
			}
			if(RP-h.RP>0 && RP-h.RP<=50)
			{
				int q=rand()%5;
				if(q==0)
				{
					cout<<"消耗了对手"<<b2<<"点体力值"<<endl;
					h.HP-=b2;
					h.AP+=A;
				}
				if(q>0)
				{
					cout<<"消耗了对手"<<b2<<"点体力值"<<endl;
					h.HP-=b1;
					h.AP+=A;
				}

			}
			if(RP-h.RP<=0)
			{
				cout<<"消耗了对手"<<b2<<"点体力值"<<endl;
				h.HP-=b1;
				h.AP+=A;
			}

			}
		
		
		if(p==2)
		{
			cout<<name<<"的10号球员拿球组织反击，面对"<<h.name<<"的防守队员送出直塞";
			int r=rand()/5;
			if(r==0)
			{
				cout<<"皮球被漂亮地拦截，进攻队员只能折返跑"<<"消耗了"<<b1<<"点体力值"<<endl;
				HP-=b1;
			}
			if(r>0)
			{
			if(RP-h.RP>80)
			{
				cout<<"消耗了"<<b2<<"点体力值"<<endl;
				h.HP-=b2;
				h.AP+=A;
			}
			if(RP-h.RP>50 && RP-h.RP<=80)
			{
				int q=rand()%2;
				if(q==0)
				{
					cout<<"消耗了"<<b2<<"点体力值"<<endl;
					h.HP-=b2;
					h.AP+=A;
				}
				if(q==1)
				{
					cout<<"消耗了"<<b2<<"点体力值"<<endl;
					h.HP-=b1;
					h.AP+=A;
				}
			}
			if(RP-h.RP>0 && RP-h.RP<=50)
			{
				int q=rand()%5;
				if(q==0)
				{
					cout<<"消耗了"<<b2<<"点体力值"<<endl;
					h.HP-=b2;
					h.AP+=A;
				}
				if(q>0)
				{
					cout<<"消耗了"<<b2<<"点体力值"<<endl;
					h.HP-=b1;
					h.AP+=A;
				}

			}
			if(RP-h.RP<0)
			{
				cout<<"消耗了"<<b2<<"点体力值"<<endl;
				h.HP-=b1;
				h.AP+=A;
			}

			}
		}

	}

	//—————————————————————阵地进攻——————————————————————//
	void bite(hero &h)
	{
		int b=20+rand()%20+DA*0.5-h.DF*0.3;
		int A=15+rand()%11;
		int p=rand()%3;
		if(p==0)
		{
			cout<<name<<"在中前场拿球组织进攻，最后由左边前卫传出渗透球。"<<h.name<<"的中后卫大脚解围出底线，角球。"<<endl;
		}
		if(p>0)
		{
			cout<<name<<"在中前场拿球组织进攻，最后由左边前卫传出渗透球，一脚射门，球进啦！！！"<<h.name<<"消耗"<<b<<"点体力值"<<endl;
			h.HP-=b;
			h.AP+=A;
		}
	}


	//——————————————————————场间恢复————————————————————//
	void cure(hero &h)
	{
		cout<<name<<"的一位球员在无球跑动的情况下痛苦倒地，裁判暂停比赛。队医上场治疗，同时带来了运动饮料给其他球员，体力值涨50"<<endl;
		Sleep(2200);
		cout<<h.name<<"抱怨自己的足协和中国足协一样垃圾。"<<endl;
		HP=HP+50;
	}

	//——————————————————————愤怒————————————————————//
	void angry()
	{
		cout<<name<<"的主场观众唱起了YNWA，顿时精神值飙涨50点"<<endl;
		AP+=50;
	}



	//——————————————————————进攻函数——————————————————————//

	void decide(hero &h)
	{
		int r=rand()%101;
		if(AP<40)
		{
			if(0<=r && r<20)
			{
				cout<<name<<"发动了进攻"<<endl;
				Sleep(2200);
				hit(h);
				Sleep(2200);
				hit(h);
			}
			if(20<=r && r<=100)
			{
				hit(h);
			}
		}
		else if(40<=AP && AP<80)
		{
			if(0<=r && r<10)
			{
				cout<<name<<"发动了进攻"<<endl;
				Sleep(2200);
				hit(h);
				Sleep(2200);
				hit(h);
			}
			if(10<=r && r<30)
			{
				hit(h);
			}
			if(30<=r && r<40)
			{
				bite(h);
			}
			

		}
		else if(AP>=80)
		{
			if(0<=r && r<10)
			{
				cout<<name<<"发动了进攻"<<endl;
				Sleep(2200);
				hit(h);
				Sleep(2200);
				hit(h);
			}
			
			
			
			
			if(10<=r && r<20)
			{
				hit(h);
			}
			
		
			if(30<=r && r<40)
			{
				bite(h);
			}
			

		}

		
	}
	

	int getHP()
	{
		int hp=HP;
		return hp;
	}
	void showHP(hero &h)
	{
		cout<<name<<"的体力值："<<HP<<"                  "<<h.name<<"的体力值："<<h.HP<<endl;
	}



	void show(hero &h)
	{
		cout<<name<<"                     "<<h.name<<endl;
		cout<<"体力值："<<HP<<"                     "<<"体力值："<<h.HP<<endl;
		cout<<"进攻值："<<DA<<"                     "<<"进攻值："<<h.DA<<endl;
		cout<<"防守值："<<DF<<"                     "<<"防守值："<<h.DF<<endl;
		cout<<"幸运值："<<RP<<"                     "<<"幸运值："<<h.RP<<endl;
		cout<<"反击速度值："<<SP<<"                     "<<"反击速度值："<<h.SP<<endl;
	}
	
	//——————————————————————胜利宣言函数————————————————————————//
	void claim(hero &h)
	{
		int p=rand()%3;
		if (p==0)
		{
			cout<<h.name<<"被"<<name<<"击败了，比分1:3"<<endl;
			Sleep(200);
			cout<<name<<":希望在淘汰赛中见面"<<endl;
		}
		if (p==1)
		{
			cout<<h.name<<"被"<<name<<"击败了，比分1:7"<<endl;
			Sleep(200);
			cout<<h.name<<":耻辱不会忘记，下次世界杯见"<<endl;
		}
		if(p==2)
		{
			cout<<h.name<<"与"<<name<<"平局，比分1:1"<<endl;
			Sleep(2200);
			cout<<name<<":握手言和吧！"<<endl;
		}
	}

};

int main()
{
	srand(time(0));
	//——————————————————————姓名初始化————————————————————//
	char str1[200];	
	char str2[100];
	char str3[100];
	char str4[100];
	char n1[20];
	char n2[20];
	strcpy(str1,"2018俄罗斯世界杯已经开始了，你支持哪支球队？快来看看谁会捧得大力神杯！！！");
	strcpy(str2,"主队是：请输入队名");
	strcpy(str3,"客队是：请输入队名");
	strcpy(str4,"随着主裁判里佐利的一声长哨，比赛开始！！！");
	print(str1);
	print(str2);
	cin>>n1;
	print(str3);
	cin>>n2;
	print(str4);
	
	//——————————————————————属性初始化————————————————————//
	hero h1,h2;
	h1.setname(n1);
	h2.setname(n2);
	h1.setnature();
	h2.setnature();


	//—————————————————————亮相————————————————————————//
	h1.show(h2);

	int hp1,hp2;

	while(true)
	{
		h1.decide(h2);
		hp1=h1.getHP();
		hp2=h2.getHP();
		if(hp1<=0 || hp2<=0)
		{
			break;
		}
		
		Sleep(2200);
		h2.decide(h1);
		hp1=h1.getHP();
		hp2=h2.getHP();
		if(hp1<=0 || hp2<=0)
		{
			break;
		}
		
		

	}


	if(hp1<=0)
	{
		h2.claim(h1);	
	}
	if(hp2<=0)
	{
		h1.claim(h2);
	}
	system("pause");

	return 0;
	
}
