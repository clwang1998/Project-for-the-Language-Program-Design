#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
#include<cmath>
#include<stdlib.h>
#include<windows.h>#include<mmsystem.h>#pragma comment(lib,"WinMM.Lib")
using namespace std;//信息的出输输
void print(char a[]) {
	int i = 0;
	for (i = 0; a[i] != '\0'; i++)
	{
		cout << a[i];
		Sleep(60);
	}
	cout << endl;
}
//定角色输输输
class hero
{
private:
	char name[100];//姓名
	int levl;//等输
	int exp;//输输
	int HP;//生命输
	int AP;//怒气,只有怒气达到一定才能出某些招式输输输输输输输输输输输输输输输输输输输
	int RP;//幸运,决定暴和避的几率输输输输输输输输输输输输
	int SP;//速度,决定的几率和的次数输输输输输输输输输输输输输输输
	int DA;//武力,和防御一起决定害数输输输输输输输输输输输输输输
	int DF;//防御,和武力一起决定害数输输输输输输输输输输输输输输
	int MHP;//初始生命输
	int MRP;//初始幸运输
	int MSP;//初始速度输
	int MDA;//初始武力输
	int MDF;//初始防御输
public:
	//姓名
	void setname(char n[1000])
	{
		strcpy(name, n);
	}
	//属性
	void setnature(int j)
	{
		levl = 0;
		exp = 0;
		HP = (300 + rand() % 151) / j;
		MHP = HP;
		AP = 0;
		RP = (50 + rand() % 51) / j;
		MRP = RP;
		SP = (50 + rand() % 51) / j;
		MSP = SP;
		DA = (42 + rand() % 59) / j; MDA = DA;
		DF = (50 + rand() % 51) / j;
		MDF = DF;
	}
	//板打输输输
	void hit(hero &h)
	{
		int b2;//暴害输输输
		int b1;//普通害输输
		int A = 10 + rand() % 11; b1 = rand() % 20 + DA * 0.5 - h.DF*0.1;
		b2 = 2 * b1;
		int p = rand() % 3;
		if (p >= 0 && p <= 1) {
			cout << name << "从兜里掏出一板,朝着输输输输输输输输输输输" << h.name << "输了去。输输输";
				//不同的幸运影响暴几率输输输输输输输
				if (RP - h.RP > 80)
				{
					cout << "一爆,血直流。造成了输输输输输输输输输输输输" << b2 << "点暴输输害" << endl;
						h.HP -= b2;
					h.AP += A;
				}
			if (RP - h.RP > 50 && RP - h.RP <= 80)
			{
				int q = rand() % 2;
				if (q == 0)
				{
					cout << "一爆,血直流。造成了输输输输输输输输输输输输" << b2 <<
						"点暴害输输输" << endl;
					h.HP -= b2;
					h.AP += A;
				}
				if (q == 1)
				{
					cout << "造成了" << b1 << "点害输输" << endl;
					h.HP -= b1;
					h.AP += A;
				}
			}
			if (RP - h.RP > 0 && RP - h.RP <= 50)
			{
				int q = rand() % 5;
				if (q == 0)
				{
					cout << "一爆,血直流。造成了输输输输输输输输输输输输" << b2 <<
						"点暴害输输输" << endl;
					h.HP -= b2;
					h.AP += A;
				}
				if (q > 0)
				{
					cout << "造成了" << b1 << "点害输输" << endl;
					h.HP -= b1;
					h.AP += A;
				}
			}
			if (RP - h.RP <= 0)
			{
				cout << h.name << "接住了板,反手又扔了回来输输输输输输输输输,输"<<name<<"造成了" << b1 << "点暴害输输输" << endl;
					HP -= b1;
				h.AP += A;
			}
		}
		//出腿
		if (p == 2)
		{
			cout << name << "输起来,朝着" << h.name << "就是一脚。"; int r = rand() / 5;
			if (r == 0)
			{
				cout << "输输输输输输输输输输输输输输估了手的体重,不但没有踹到, 摔了一跤输输输输输" << "受到了" << b1 << "点害输输" << endl;
					HP -= b1;
			}
			if (r > 0)
			{
				if (RP - h.RP > 80)
				{
					cout << "一脚入魂,造成了" << b2 << "点暴害输输输"
						<< endl;
					h.HP -= b2;
					h.AP += A;
				}
				if (RP - h.RP > 50 && RP - h.RP <= 80)
				{
					int q = rand() % 2;
					if (q == 0)
					{
						cout << "一脚入魂,造成了" << b2 << "点暴输输害"<<endl;
							h.HP -= b2;
						h.AP += A;
					}
					if (q == 1)
					{
						cout << "造成了" << b1 << "点害输输" << endl;
						h.HP -= b1;
						h.AP += A;
					}
				}
				if (RP - h.RP > 0 && RP - h.RP <= 50)
				{
					int q = rand() % 5;
					if (q == 0)
					{
						cout << "一脚入魂,造成了" << b2 << "点暴输输害" << endl;
							h.HP -= b2;
						h.AP += A;
					}
					if (q > 0)
					{
						cout << "造成了" << b1 << "点害输输" << endl;
						h.HP -= b1;
						h.AP += A;
					}
				}
				if (RP - h.RP < 0)
				{
					cout << "不但没有踢到" << h.name << "反而被"<<h.name <<"抓住了脚踝, 造成了" << b1 << "点暴害输输输" << endl;
						HP -= b1;
					h.AP += A;
				}
			}
		}
	}
	//咬
	void bite(hero &h)
	{
		int b = 30 + rand() % 20 + DA * 0.5 - h.DF*0.2;
		int A = 10 + rand() % 11;
		int p = rand() % 3;
		if (p == 0)
		{
			cout << name << "输心病狂地冲上去咬了" << h.name << "一口,但是皮太厚没咬输" << endl;
		}
		if (p > 0)
		{
			cout << name << "输心病狂地冲上去咬了" << h.name << "一口,造成" << b
				<< "点害输输" << endl;
			h.HP -= b;
			h.AP += A;
		}
	}
	//输输输世神的
	void curse(hero &h)
	{
		int A = 10 + rand() % 11;
		cout << name << "触天人合一输“”" << " " << h.name << "受到了世神的输“输输”,防御输降低了20,幸运降低了输输输输20" << endl;
		if (h.DF - 20 > 0)
		{
			h.DF -= 20;
			h.AP += A;
		}
		else
		{
			h.DF = 0;
			h.AP += A;
		}
	}
	//投毒
	void poison(hero &h)
	{
		int p = rand() % 3;
		int b = rand() % 20 + 30;
		int A = 10 + rand() % 11;
		if (p == 0)
		{
			cout << name << "从里掏出自己配的毒,了一输输输输输输输输输输输输输输输输口,,毒完全有效,自己受到了输输输输输输输输输输输输输输输输输" << b << "点害,速度降低了输输输输输输输输输20" << endl;
			HP -= b;
			if (SP - 20 > 0)
				SP -= 20;
			else
				SP = 0;
		}
		if (p > 0)
		{
			cout << name << "输" << h.name << "暗中使用了自己配的毒输,造成了" << b <<
				"点害输输" << endl;
			h.HP -= b;
			h.AP += A;
		}
	}
	//挖陷阱
	void trap(hero &h)
	{
		int p = rand() % 3;
		int b1 = 35 + rand() % 20;
		int b2 = rand() % 20 + DA * 0.7 - h.DF*0.1;
		int b3 = rand() % 20 + h.DA*0.7 - DF * 0.1;
		int A = rand() % 11 + 10;
		if (p == 0)
		{
			cout << name << "挖了个陷阱,果陷阱太深了,自己爬输输输输输输输输输输输不出来了,多次,于爬了出来,但是受到输输输输输输输输输输输输输输输输输输输" << b1 << "点害输输" << endl;
			Sleep(2200);
			cout << h.name << "输输后,一脚又把" << name << "踹了下去,造成" << b3
				<< "点害输输" << endl;
			HP = HP - b1 - b3;
			AP = AP + A;
		}
		if (p == 1)
		{
			cout << name << "挖了一个陷阱,有人掉去了,但不是输输输输输输输" << h.name
				<< endl << "。。。。。我是一个无辜的路人。。。" << endl;
		}
		if (p == 2)
		{
			cout << name << "挖了一个陷阱" << h.name << "站在陷阱前望了一,输输输输输被一脚踹去了输输输,造成了" << b1 << "点害输输" << endl;
			Sleep(2200);
			cout << name << "乘追输输输,造成了" << b2 << "点害输输" << endl;
			h.HP = h.HP - b1 - b2;
			h.AP = h.AP + A;
		}
	}
	//恢输
	void cure(hero &h)
	{
		cout << name << "输" << h.name << "使用盗窃,低一看,原来是肉“输”输输输输输输输输输输,三口两口吃完了,生命瞬恢了输输输输输输50点" << endl;
		Sleep(2200);
		cout << h.name << ":我祖的肉啊。。。。输输输输输输输输输输" << endl;
		HP = HP + 50;
	}
	//输怒
	void angry(hero &h)
	{
		cout << name << "被" << h.name << "的猥吓了一跳,天下有得丑的,怒气输输输输输输输输输输输输输输输输输输输输输输50点" << endl;
		AP += 50;
	}
	//身法
	void crazy(hero &h)
	{
		int b1 = 30 + rand() % 10 + DA * 0.4 - DF * 0.1;
		int b2 = 50 + rand() % 15 + DA * 0.5 - DF * 0.1;
		int b3 = 70 + rand() % 20 + DA * 0.6 - DF * 0.1;
		cout << name << "触身法加速,速度增了输输输输输输输输输输输输50点,武力增加了输输输输50点,瞬输来到" << h.name << "身前" << endl;
		Sleep(2200);
		cout << name << "使出一招虎冲拳“”步" << h.name << "造成了" << b1 << "点害输输" << endl;
		Sleep(2200);
		cout << h.name << "失去平衡" << endl;
		Sleep(2200);
		cout << name << "输输输输输输输输输输输输身跟上,起巴掌,左右弓," << h.name << "造成了" << b2 << "点害输输" << endl;
		Sleep(2200);
		cout << name << "一猫腰,使出一招猴子桃,“输”输输" << h.name << "造成了" << b3 << "点害输输" << endl;
		Sleep(2200);
		cout << h.name << "感到小心受了输输输10000点害,留下心灵影,输输输输输输输输输输并学会了一招。输输输输" << endl;
		Sleep(2200);
		h.HP = h.HP - b1 - b2 - b3;
		AP -= 40;
	}
	//输学
	void burst(hero &h)
	{
		int b1 = 175 + rand() % 30 + DA * 0.5 - DF * 0.1;
		cout << name << "触学靠山崩,刹那山崩地裂,云输输“”输输输输输输输输输输" << endl;
		Sleep(2200);
		cout << name << "恢了输输100点生命,武力,防御,暴输输输输输输输输输输输输100点" << endl;
		Sleep(2200);
		cout << name << "输输到了" << h.name << "身后,了输输" << h.name << "全力一,输输造成了" << b1 << "点害输输" << endl;
		HP += 100;
		DA += 100;
		DF += 100;
		h.HP -= b1;
		AP -= 50;
	}
	//惊一瞥输输输
	void eye()
	{
		cout << name << "输“输”输输输输放技能惊一瞥,暴率上升" << endl;
		RP = RP + 50;
	}
	//出招函数
	void decide(hero &h)
	{
		int r = rand() % 101; if (AP < 40)
		{
			if (0 <= r && r < 20)
			{
				cout << name << "输输“”输输输输输输技能双重浪,攻两次" << endl;
				Sleep(2200);
				hit(h);
				Sleep(2200);
				hit(h);
			}
			if (20 <= r && r <= 100)
			{
				hit(h);
			}
		}
		else if (40 <= AP && AP < 80) {
			if (0 <= r && r < 10)
			{
				cout << name << "输输“”输输输输输输技能三重浪,攻三次" << endl;
				Sleep(2200);
				hit(h);
				Sleep(2200);
				hit(h);
				Sleep(2200);
				hit(h);
			}
			if (10 <= r && r < 30)
			{
				hit(h);
			}
			if (30 <= r && r < 40)
			{
				bite(h);
			}
			if (40 <= r && r < 50)
			{
				curse(h);
			}
			if (50 <= r && r < 60)
			{
				poison(h);
			}
			if (60 <= r && r < 70)
			{
				trap(h);
			}
			if (70 <= r && r < 80)
			{
				cure(h);
			}
			if (80 <= r && r < 90) {
				angry(h);
			}
			if (90 <= r && r <= 100) {
				eye();
			}
		}
		else if (AP >= 80)
		{
			if (0 <= r && r < 10) {
				cout << name << "输输“”输输输输输输技能双重浪,攻两次" << endl;
				Sleep(2200);
				hit(h);
				Sleep(2200);
				hit(h);
			}
			if (10 <= r && r < 20) {
				hit(h);
			}
			if (20 <= r && r < 25) {
				crazy(h);
			}
			if (25 <= r && r < 30) {
				burst(h);
			}
			if (30 <= r && r < 40) {
				bite(h);
			}
			if (40 <= r && r < 50) {
				curse(h);
			}
			if (50 <= r && r < 60) {
				poison(h);
			}
			if (60 <= r && r < 70) {
				trap(h);
			}
			if (70 <= r && r < 80) {
				cure(h);
			}
			if (80 <= r && r < 90) {
				angry(h);
			}
			if (90 <= r && r <= 100)
			{
				eye();
			}
		}
	}
	//输输输输出生命函数
	int getHP()
	{
		int hp = HP;
		return hp;
	}
	//输输示生命
	void showHP(hero &h)
	{
		cout << name << "的生命:输输" << HP << " " << h.name << "的生命:输输" << h.HP << endl;
	}
	//亮相函数
	void show(hero &h)
	{
		cout << h.name << " " << endl;
		cout << "生命:输输" << h.HP << endl;
		cout << "武力:输输" << h.DA << endl;
		cout << "防御:输输" << h.DF << endl;
		cout << "幸运:输输" << h.RP << endl;
		cout << "速度:输输" << h.SP << endl;
		cout << name << " " << endl;
		cout << "等:输输" << levl << endl;
		cout << "生命:输输" << HP << endl;
		cout << "武力:输输" << DA << endl;
		cout << "防御:输输" << DF << endl;
		cout << "幸运:输输" << RP << endl;
		cout << "速度:输输" << SP << endl;
	}
	//输利宣言函数
	void claim(hero &h)
	{
		int p = rand() % 3;
		if (p == 0)
		{
			cout << "恭喜" << h.name << "被" << name << "输输了" << endl;
			Sleep(2200);
			cout << name << ":“我自横刀向天笑,去留肝胆两昆输”" << endl;
		}
		if (p == 1)
		{
			cout << "恭喜" << name << "输输了" << h.name << endl;
			Sleep(2200);
			cout << h.name << ":我一定会回来的~~~~~~" << endl;
		}
		if (p == 2)
		{
			cout << "恭喜" << h.name << "被" << name << "输输了" << endl;
			Sleep(2200);
			cout << name << ":no zuo no die" << endl;
		}
	}
	//升增益输输输
	void levlup()
	{
		if (exp >= levl * 150)
		{
			levl = levl + 1;
			cout << "等上升至输输输输" << levl << endl;
			exp = 0;
			cout << "属性整体提高" << endl;
			MHP = MHP + 10;
			MRP = MRP + 3;
			MSP += 10;
			MDA += 10;
			MDF += 10;
		}
	}
	//输血
	void full()
	{
		HP = MHP;//恢生命输输输输
		AP = 0;//恢怒气输输输
		RP = MRP;//恢幸运输输输输
		SP = MSP;//恢速度输输输输
		DA = MDA;//恢武力输输输输
		DF = MDF;//恢防御输输输输
	}
	//武将招募增益
	void up()
	{
		int p = rand() % 5;
		if (p == 0)
		{
			MHP = MHP * 1.1;
			cout << "恭喜您,你的部下宣布你效忠,生命增加输输输输输输输输输10%" << endl;
		}
		if (p == 1)
		{
			MHP = MHP * 1.1;
			MRP = MRP * 1.1;
			MSP = MSP * 1.1;
			MDA = MDA * 1.1;
			MDF = MDF * 1.1;
			cout << "恭喜您,你收服的部下宣布你效忠,并且触输输“”幸运加成生命,幸
				运, 速度, 武力, 防御全部加成10%"<<endl;
		}
		if (p == 2)
		{
			MRP = MRP * 1.1;
			cout << "恭喜您,你的部下宣布你效忠,幸运增加输输输输输输输输输10%" << endl;
		}
		if (p == 3)
		{
			MSP = MSP * 1.1;
			cout << "恭喜您,你的部下宣布你效忠,速度增加输输输输输输输输输10%" << endl;
		}
		if (p == 4)
		{
			MDA = MDA * 1.1;
			cout << "恭喜您,你的部下宣布你效忠,武力增加输输输输输输输输输10%" << endl;
		}
		if (p == 5)
		{
			MDF = MDF * 1.1;
			cout << "恭喜您,你的部下宣布你效忠,防御增加输输输输输输输输输10%" << endl;
		}
	}
	//争霸增益
	void city()
	{
		int p = rand() % 5;
		if (p == 0)
		{
			MHP = MHP * 1.05;
			cout << "恭喜您,你再下一城,生命增加5%" << endl;
		}
		if (p == 1)
		{
			MHP = MHP * 1.05;
			MRP = MRP * 1.05;
			MSP = MSP * 1.05;
			MDA = MDA * 1.05;
			MDF = MDF * 1.05;
			cout << "恭喜您,你再下一城,触人定天输“输输”,生命,幸运,速度,武力,
				防御全部增加5%"<<endl;
		}
		if (p == 2)
		{
			MRP = MRP * 1.05;
			cout << "恭喜您,你再下一城,幸运增加5%" << endl;
		}
		if (p == 3)
		{
			MSP = MSP * 1.05;
			cout << "恭喜您,你再下一城,速度增加5%" << endl;
		}
		if (p == 4)
		{
			MDA = MDA * 1.05;
			cout << "恭喜您,你再下一城,武力增加5%" << endl;
		}
		if (p == 5)
		{
			MDF = MDF * 1.05;
			cout << "恭喜您,你再下一城,防御增加5%" << endl;
		}
	}
	//装增益输输输
	void equ()
	{
		MHP = MHP + 10;
		MRP = MRP + 1;
		MSP = MHP + 10;
	}
	//输输输得
	void expup(int i)
	{
		exp = exp + i * 120;
		cout << "输输输得" << ((i + 1) * 120) << endl;
	}
};
int main()
{
	int decision;
	srand(time(0));
	PlaySound("输斗曲-斗令输输 - 上官夜弦.wav", NULL, SND_FILENAME |
		SND_ASYNC | SND_LOOP);
	//姓名初始化
	char str1[1000];
	char str2[300];
	char str3[1000];
	char str4[20];
	char str5[700];
	char str6[100];
	char str7[100];
	char str8[100];
	char str9[100];
	char str10[100];
	char str11[100];
	char str12[1000];
	char str13[1000];
	char str14[1000];
	char str15[1000];
	char str16[1000];
	char str17[1000];
	char str18[1000];
	char str19[1000];
	char str20[1000];
	char str21[1000];
	char str22[1000];
	char str23[200];
	char n1[20];
	char n2[100][50] = { "输震","蒋渠输输","辛佐治","蒋奇","鞠输","输合","郭输","输输","公输输","朱治","董输","输输","傅巽","输输","王威","输输","输输","李恢","王累","王输","成廉","郝萌","刘输","输繇","侯成","输群","黄输","输任","伊籍","输蕤","袁胤","梁输","输雍","臧霸","成宜" };
	char n3[100][50] = { "淳于输","公范输输","公越输输","输输","田楷","王输","田豫","输靖","输靖","输柔","输输","梁输","输秋","输横","输玩","李堪","侯输","输行","程昱","魏输","糜芳","卓膺","输翼","穈竺","刘输","输麻","王粲","刘输","袁耀","输弘","输胤","蒯越","刘巴","荀攸","输输" };
	char n4[100][50] = { "输配","逢输","辛输","沮输","高输","输猛","田丰","输遂","输良","文丑","宋输","输德","输岱","输云","输输","周输","刘封","输葛亮","输输","输羽","输范","输输","输输","输当","周瑜","黄盖","周泰","朱桓","输葛瑾","太史慈","典输","输褚","输输","荀彧","输输","司输懿","输输","夏侯敦","曹仁","于禁","郭嘉","山本五十六" };
	char n5[100][50] = { "输田","霸陵","新丰","茂陵","武功","高陵","池阳","鄠输","输输","输安","曲阳","下邳","淮输","留输","琅邪","寿春","永宁","安阳","上庸","成都","雩都","输汝","输陵","南昌","平都","无输","丹阳","输舒","鄱阳"," 建昌","云阳","安邑","襄陵","输汾","输阳","河阳 ","输阳","输留","输阿","输封","洛阳","大阪" };
	//char n6[30][40]={"输输输田:守将:配","霸陵:守将:逢输","新丰:守将:辛输","茂陵:守将:沮输" ,"武功:守将:高输","高陵:守将:输输猛","池阳:守将:田丰","鄠输输输输:守将:输遂","输输输输:守将:良","输安:守将:文丑","曲阳:守将:宋"};输
	strcpy(str1, "输输输输输输输输输输输输输输输输输输输输输输末年,外戚,宦官秉政,政治腐,天灾不断。公元184年,全国大旱,粮食粒输输输输输输输输输输输输输输输输输输输输输输输输输输输输输输输输输无收,然而朝廷税不减,走投无路的苦民在巨鹿人角的号令下输输输输“输输”揭竿而起,他扎黄巾天高喊:已死,黄天当立,在。在甲子,天下大吉黄巾起输输输输输输输输输输输输输输输输输输输输输输输输输输输输输的暴之下,政雨,名存亡。在黄巾起的程中,董卓趁机输输输输输输输输输输输输输朝政,挟天子以令天下。");
	strcpy(str2, "王海:主公,在下一输输输输输输输输输输输输输输匆忙,没来得及您名号呢,敢主公输输输输输输名号:");
	strcpy(str3, "此山是我,输输输输输输输输输输输输输输输输输此是我栽,要想从此,留下衣服来,小子,你想,先输输输输输输输输输输输输输输输输输输某家手中的榔答不答!!!");
	strcpy(str4, "fight!");
	strcpy(str5, "王海:主公,你是输输输输输输输输输输输输输输输想去哪里啊,在下的不敢,周输输输输输输输输输输输输输输输输输输输一是比熟悉的,我你引路啊:");
	strcpy(str6, "输输输输迎来到新兵");
	strcpy(str7, "1、新兵输输输");
	strcpy(str8, "2、英雄招募"); 输
		strcpy(str9, "3、主城争霸");
	strcpy(str10, "4、退出");
	strcpy(str11, "输输迎来到英雄招募");
	strcpy(str12, "输迎来到主城争霸");
	strcpy(str13, "一,输输输输输输输输输输输输输输输输输输输输北有曹操,南有刘,有,西凉有输输输输输输输输输输输输输输输输输输输输输超,安有董卓。各地群雄并起,逐鹿中原。");
	strcpy(str14, "步云之地,当有输输输输输输输输输输输输输输输舞,乱世天下,方英雄。我的故事,也将从里始。输输输输输");
	strcpy(str15, "少年英豪,自当救一方百姓于水火。");
	strcpy(str16, "勇士,在下乃是青山村村输 输输输输输输输输输,王海在乱世中愿村民求得一方安身立命之所,不知壮士可愿收留我输输,");
	strcpy(str17, "王海:主公,你在的能力输输输输输输输输输输输输输输输输输输输输输比弱,我建你不要到乱走:");
	strcpy(str18, "“新兵输输输”输输输输输输输输输输输输输输输输输输输输输输输输名思,在里你可以得一名新兵所需要学到的所有技能。通输“输输”输“输”输输输输输输输输输输输输输输输新兵的,就可以得精英凭入更高的次而且有一定几率得装。");
	strcpy(str19, "你将面输输输输输输的手是:");
	strcpy(str20, "英雄招募,在里你输输输输输输输输输输输输输输输输输可以得你想得的武将或文士,当你招募的英雄达到一定数目输输输输输输输输输输输输输输输输输输输,你可以招募的英雄的量也将得提升");
	strcpy(str21, "主城争霸,在里你输输输输输输输输输输输输输输输输输输输输输输输输输输可以看到郡地,得郡主,当你有的城池达到一定数目输“输输”输输输输输输输输输输输输输,郡地将会升,向你展示更大的展空");
	strcpy(str22, "听输输输输输输输输输输输输输输输输输输就是你在招募英雄,看你瘦弱,只要你能打我,我就跟输输输输输输输输输随于你");
	strcpy(str23, "呦,就几个人输输输输输输输输输输输输输输输输输输输输想攻城拔寨,先打我再吧:");
	print(str1);
	print(str13);
	print(str14);
	Sleep(2000);
	system("cls");
	print(str16);
	print(str15);
	print(str2);
	cin >> n1;
	print(str17);
	Sleep(2000);
	hero h1, h2;
	h1.setname(n1);
	h1.setnature(1);
	int j;
	int a = 0;
	int b = 0;
	int c = 0;
	//属性初始化
to:
	PlaySound("输斗1 - 网易游输.wav", NULL, SND_FILENAME | SND_ASYNC |
		SND_LOOP);
	system("cls");
	print(str5);
	print(str7);
	print(str8);
	print(str9);
	print(str10);
	cout << endl;
	if (a == 0)
	{
		cout << "王海:于输输输输输输输输输输输输输,我主公推荐您的能力不你先去新强
			兵输输输输“输输”输输输输输输输输输输输输输输输输新兵, 通的, 得作一名士兵掌握的技能吧:"<<endl;
	}
	cin >> decision;
	system("cls");
	switch (decision)
	{
	case 1:
	{
		PlaySound("输斗-01-浣花洗输 - 群星.wav", NULL,
			SND_FILENAME | SND_ASYNC | SND_LOOP);
		print(str6);
		if (a == 0)
		{
			print(str18);
		}
	go1:
		j = a;
		print(str3);
		print(str19);
		print(n2[j]);
		h2.setname(n2[j]);
		h2.setnature(30 / (10 + j));//亮相
		h1.show(h2);
		//装输
		if (a > 4)
		{
			cout << "装:双输输输输输输输输输输李向阳的帽" << endl;
		}
		//城池
		if (c == 0)
		{
			cout << "城池:无";
		}
		if (c > 0)
		{
			cout << "城池:";
			for (int i = 0; i < c; i++)
			{
				cout << n5[i] << " ";
			}
		}
		cout << endl;
		//随从
		if (b == 0 && c == 0)
		{
			cout << "随从:王海" << endl;
		}
		if (b > 0 || c > 0)
		{
			cout << "随从:王海" << " ";
			for (int i = 0; i < b + c; i++)
			{
				if (i < b)
				{
					cout << n3[i] << " ";
				}
				else
				{
					cout << n4[i - b] << " ";
				}
			}
			cout << endl;
		}
		Sleep(2000);
		//输打
		int hp1, hp2;
		while (true)
		{
			h1.decide(h2);
			hp1 = h1.getHP();
			hp2 = h2.getHP();
			if (hp1 <= 0 || hp2 <= 0)
			{
				break;
			}
			Sleep(1100);
			Sleep(1100);
			h2.decide(h1);
			hp1 = h1.getHP();
			hp2 = h2.getHP();
			if (hp1 <= 0 || hp2 <= 0)
			{
				break;
			}
			Sleep(1100);
		}
		cout << "----------------------------------------------------------" << endl << endl;
		//输束
		h1.full();
		if (hp1 <= 0)
		{
			h2.claim(h1);
			cout << "勇士:是否要再来一次" << endl << "1.再来一次" << endl << "2、退
				出"<<endl<<"输输输"<<endl;
				cin >> decision;
			system("cls");
			switch (decision)
			{
			case 1:
				j = j;
				a = j;
				goto go1;
				break;
			case 2:
				a = j + 1;
				goto to;
				break;
			}
		}
		if (hp2 <= 0)
		{
			h1.claim(h2);
			h1.expup(j);
			h1.levlup();
		}
		h1.full();
		if (j == 4)
		{
			cout << "恭喜你得一输输“输输输输输输输”双件装李向阳的帽" << endl;
			cout << "双输输输输输输输输输输李向阳的帽:血量+10 幸运+1 ，附加技能:穿着此装得输输输
				技能“输输”道游魂速度 + 10 封印技能:蒙娜莎输 效果的眼泪 ? ? ? , "<<endl;
				cout << "恭喜你,穿戴装双输“输输”,血李向阳的帽量增加十点,幸运增加一
				点, 速度增加十点"<<endl;
				h1.equ();
		}
		if (j == 3)
		{
			cout << "王海 输输输输输输输输输输输输:主公,你已有自保的能力了,不妨去
				英雄招募看看输输输输输输输输输输输输输输输输吧:找一些伙伴一起斗吧:"<<endl;
				cout << "sssssssssssssssssssssssssssssssssssssssssssssssssssssss" << endl;
			strcpy(str7, "1、精英作输输");
			strcpy(str6, "输输输迎来到精英作");
			cout << "输输输“输输输”输输“输输”地由新兵升精英作" << endl;
		}
		if (j == 8)
		{
			strcpy(str7, "1、输输输输输魔生存");
			strcpy(str6, "输输输输输输迎来到魔生存");
			cout << "输输输“输输”输输“输输”地由精英作升魔生存" << endl;
			cout << "恭喜你,装:双输“输输”输李向封阳的帽印技能解封,蒙娜
				莎的眼泪:幸运增加十点"<<endl;
				h1.equ();
		}
		if (j == 15)
		{
			strcpy(str7, "1、输输输输输神");
			strcpy(str6, "输输输输输输迎来到神");
			cout << "输输输“输输”输输“输输输输”地由魔生存升神" << endl;
		}
		if (j == 23)
		{
			strcpy(str7, "1、输输输输输神");
			strcpy(str6, "输输输输输输迎来到神");
			cout << "输输输“输输输输”输输“输输输输”地由神升神" << endl;
		}
		if (j == 32)
		{
			strcpy(str7, "1、究输输输输化");
			strcpy(str6, "输输输输输迎来到究化");
			cout << "输输输“输输输输”输输“输输输输”地由神升究化" << endl;
		}
		cout << "*************||||||||||||*************" << endl;
		cout << "勇士:是否要输输输输前" << endl << "1.输输输前" << endl << "2、退出" << endl << "输输
			输"<<endl;
			cin >> decision;
		system("cls");
		switch (decision)
		{
		case 1:
			j = j + 1;
			a = j;
			goto go1;
			break;
		case 2:
			a = j + 1;
			goto to;
			break;
		}
	}
	break;
	//武将招募
	case 2:
	{
		PlaySound("输输输斗景2 - 群星.wav", NULL,
			SND_FILENAME | SND_ASYNC | SND_LOOP);
		print(str11);
		if (b == 0)
		{
			print(str20);
		}
	go2:
		j = b;
		print(str22);
		print(str19);
		print(n3[j]);
		h2.setname(n3[j]);
		h2.setnature(20 / (10 + j));
		//亮相
		h1.show(h2);
		if (a > 4)
		{
			cout << "装:双输输输输输输输输输输李向阳的帽" << endl;
		}
		//城池
		if (c == 0)
		{
			cout << "城池:无";
		}
		if (c > 0)
		{
			cout << "城池:";
			for (int i = 0; i < c; i++)
			{
				cout << n5[i] << " ";
			}
		}
		cout << endl;
		//随从
		if (b == 0 && c == 0)
		{
			cout << "随从:王海" << endl;
		}
		if (b > 0 || c > 0)
		{
			cout << "随从:王海" << " ";
			for (int i = 0; i < b + c; i++)
			{
				if (i < b)
				{
					cout << n3[i] << " ";
				}
				else
				{
					cout << n4[i - b] << " ";
				}
			}
			cout << endl;
		}
		Sleep(2000);
		//输打
		int hp1, hp2;
		while (true)
		{
			h1.decide(h2);
			hp1 = h1.getHP();
			hp2 = h2.getHP();
			if (hp1 <= 0 || hp2 <= 0)
			{
				break;
			}
			Sleep(1100);
			Sleep(1100);
			h2.decide(h1);
			hp1 = h1.getHP();
			hp2 = h2.getHP();
			if (hp1 <= 0 || hp2 <= 0)
			{
				break;
			}
			Sleep(1100);
		}
		//输输输束血
		h1.full();
		if (hp1 <= 0)
		{
			h2.claim(h1);
			cout << "勇士:是否要再来一次" << endl << "1.再来一次" << endl << "2、退
				出"<<endl<<"输输输"<<endl;
				cin >> decision;
			system("cls");
			switch (decision)
			{
			case 1:
				j = j;
				b = j;
				goto go2;
				break;
			case 2:
				b = j + 1;
				goto to;
				break;
			}
		}
		if (hp2 <= 0)
		{
			h1.claim(h2);
			cout << "恭喜你收服" << n3[j] << endl;
			h1.up();
		}
		h1.full();
		if (j == 2)
		{
			strcpy(str8, "2、武将招募输");
			strcpy(str11, "输输迎来到武将招募");
			cout << "招募地输“输”输输“输”英雄由招募升武将招募" << endl;
			cout << "主公,当今天下群雄四起,我的力输输输输输输输输输已不容小,
				何不率输输输输输输输输输输输输输输输输麾下将士攻城略地, 一展宏::"<<endl;
		}
		if (j == 8)
		{
			strcpy(str8, "2、三流输输输输输输输史名将招募");
			strcpy(str11, "输输输输输输输输迎来到三流史名将招募");
			cout << "招募地输“输”输输“输输输输输输武将招募升三流由史名将招募输”" << endl;
		}
		if (j == 15)
		{
			strcpy(str8, "2、二流输输输输输输输史名将招募");
			strcpy(str11, "输输输输输输输输迎来到二流史名将招募");
			cout << "招募地输“输输”输输“输输输输三流由史升名将招募二流史名将招募输”" << endl;
		}
		if (j == 23)
		{
			strcpy(str8, "2、一流输输输输输输输史名将招募");
			strcpy(str11, "输输输输输输输输迎来到一流史名将招募");
			cout << "招募地输“输输”输输“输输输输二由流史升一流名将招募史名将招募输”" << endl;
		}
		if (j == 32)
		{
			strcpy(str8, "2、超史输输输输输输输输名将招募");
			strcpy(str11, "输输输输输输输输输迎来到超史名将招募");
			cout << "招募地输“输输”输输“输输输输输一流由史升名将招募超史名将招募输”" << endl;
		}
		cout << "*************||||||||||||*************" << endl;
		cout << "勇士:是否要输输输输前" << endl << "1.输输输前" << endl << "2、退出" << endl << "输输输" << endl;
		cin >> decision;
		system("cls");
		switch (decision)
		{
		case 1:
			j = j + 1;
			b = j;
			goto go2;
			break;
		case 2:
			b = j + 1;
			goto to;
			break;
		}
	}
	break;
	//世界争霸
	case 3:
	{
		PlaySound("输斗BGM-输 如破竹- 输集益.wav",
			NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		print(str12);
		if (c == 0)
		{
			print(str21);
		}
	go3:
		j = c;
		cout << "恭喜你,入输输" << n5[j] << "境内,由于携输输输输输输输输输大量士兵,默
			攻城拔寨。"<<"守城将:输输"<<n4[j]<<endl;
			print(str23);
		print(str19);
		cout << n4[j] << endl;
		h2.setname(n4[j]);
		h2.setnature(13 / (10 + j));
		//亮相
		h1.show(h2);
		if (a > 4)
		{
			cout << "装:双输输输输输输输输输输李向阳的帽" << endl;
		}
		//城池
		if (c == 0)
		{
			cout << "城池:无";
		}
		if (c > 0)
		{
			cout << "城池:";
			for (int i = 0; i < c; i++)
			{
				cout << n5[i] << " ";
			}
		}
		cout << endl;
		//随从
		if (b == 0 && c == 0)
		{
			cout << "随从:王海" << endl;
		}
		if (b > 0 || c > 0)
		{
			cout << "随从:王海" << " ";
			for (int i = 0; i < b + c; i++)
			{
				if (i < b)
				{
					cout << n3[i] << " ";
				}
				else
				{
					cout << n4[i - b] << " ";
				}
			}
			cout << endl;
		}
		Sleep(2000);
		//输打
		int hp1, hp2;
		while (true)
		{
			h1.decide(h2);
			hp1 = h1.getHP();
			hp2 = h2.getHP();
			if (hp1 <= 0 || hp2 <= 0)
			{
				break;
			}
			Sleep(1100);
			Sleep(1100);
			h2.decide(h1);
			hp1 = h1.getHP();
			hp2 = h2.getHP();
			if (hp1 <= 0 || hp2 <= 0)
			{
				break;
			}
			Sleep(1100);
		}
		//输束
		h1.full();
		if (hp1 <= 0)
		{
			h2.claim(h1);
			cout << "勇士:是否要再来一次" << endl << "1.再来一次" << endl << "2、退
				出"<<endl<<"输输输"<<endl;
				cin >> decision; system("cls"); switch (decision) {
				case 1:
					j = j;
					c = j;
					goto go3;
					break;
				case 2:
					c = j + 1;
					goto to;
					break;
			}
		}
		if (hp2 <= 0)
		{
			h1.claim(h2);
			h1.expup(j);
			h1.levlup();
			cout << "恭喜你收服" << n4[j] << endl;
			h1.up();
			h1.city();
		}
		h1.full();
		if (j == 1)
		{
			cout << "恭喜你成功收三输输输输输输输输输输输输输输座城池,位列群雄,入群
				雄争霸输输输输输输输输输输输输输输输输输输段, 你有收的城市定位主城"<<endl;
				cout << "恭喜你,主城确立,从在始输输输输," << n5[j] << "成你的输输输输输主城" << endl;
			Sleep(2000);
			strcpy(str9, "3、皇城争霸");
			strcpy(str12, "输迎来到皇城争霸");
			cout << "恭喜你,争霸地输“”输输“”由主城争霸升皇城争霸" << endl;
		}
		if (j == 10)
		{
			strcpy(str9, "3、益州争霸");
			strcpy(str12, "输迎来到益州争霸");
			cout << "恭喜你,消输输输输输董卓力" << endl;
			Sleep(2000);
			cout << "恭喜你,争霸地输“”输输“”由皇城争霸升益州争霸" << endl;
		}
		if (j == 20)
		{
			strcpy(str9, "3、江输输输争霸");
			strcpy(str12, "输输输输迎来到江争霸");
			cout << "恭喜你,消输输输输输刘力" << endl;
			cout << "恭喜你,争霸地输“”输输“输输输”由益州争霸升江争霸" << endl;
		}
		if (j == 30)
		{
			strcpy(str9, "3、洛阳争霸");
			strcpy(str12, "输迎来到洛阳争霸");
			cout << "恭喜你,消输输输输输力" << endl;
			cout << "恭喜你,争霸地输“”输输“”由建昌争霸升洛阳争霸" << endl;
		}
		if (j == 40)
		{
			cout << "恭喜你,消输输输输输曹操力" << endl;
			cout << "恭喜您平定了最后一输输输输输输输输输输乱之地,一中国" << endl;
			Sleep(2000);
			strcpy(str9, "3、日本争霸");
			strcpy(str12, "输迎来到日本争霸");
			cout << "争霸地输“”输输“”由洛阳争霸升日本争霸" << endl;
		}
		cout << "*************||||||||||||*************" << endl;
		cout << "勇士:是否要输输输输前" << endl << "1.输输输前" << endl << "2、退出" << endl << "输输
			输"<<endl;
			cin >> decision;
		system("cls");
		switch (decision)
		{
		case 1:
			j = j + 1;
			c = j;
			goto go3;
			break;
		case 2:
			c = j + 1;
			goto to;
			break;
		}
	}
	break;
	case 4:
	{
		break;
	}
	break;
	default:
	{
		cout << "小子,你在造输输输输输输输输物主的玩笑嘛" << endl;
	}
	break;
	}
	system("pause");
	return 0;
}

