#define _CRT_SECURE_NO_WARNINGS		
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>		
#include <conio.h>	
#include<time.h>
#include<iostream>
#include <windows.h>
#include<string>
#include<fstream>
#include"解析.h"
#include"Button.h"
using namespace std;


HWND hwnd;
int count = 400;
int flag = 0;
int level = 0;

int playeratt = 0, monatt = 0;
string weapon = "铁剑";
int map[4][13][13]; 

void shopView();
void Welcome();
void cundangmap();
void gameoverView();
void Gameinit();
void loadResource();
void loseView();
void monsterBook();
void PK(const TCHAR*);
void Pick(const TCHAR*);
void readmap();
void readuser();


int maps[4][13][13] =
{
	//第一层
	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 16, 4, 9, 9, 9, 1, 1, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
	0, 6, 1, 1, 2, 1, 0, 0, 4, 4, 2, 4, 0,
	0, 1, 11, 1, 0, 1, 0, 0, 13, 11, 0, 1, 0,
	0, 0, 2, 0, 0, 4, 2, 10, 18, 10, 0, 1, 0,
	0, 4, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0,
	0, 1, 11, 1, 0, 1, 0, 0, 0, 0, 0, 13, 0,
	0, 0, 2, 0, 0, 1, 1, 0, 0, 0, 0, 6, 0,
	0, 6, 1, 1, 0, 0, 2, 0, 0, 0, 0, 11, 0,
	0, 6, 1, 4, 0, 1, 10, 4, 0, 1, 1, 1, 0,
	0, 1, 1, 4, 0, 9, 7, 1, 0, 1, 1, 15, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	},

	//第二层
	{
	21, 9, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	5, 4, 1, 0, 9, 9, 1, 1, 1, 1, 10, 1, 0,
	9, 9, 11, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
	11, 11, 11, 2, 1, 1, 0, 0, 4, 1, 0, 13, 0,
	0, 3, 0, 0, 0, 1, 1, 1, 13, 0, 0, 9, 0,
	1, 1, 1, 0, 0, 4, 1, 1, 4, 0, 0, 9, 0,
	0, 0, 1, 1, 9, 1, 1, 1, 5, 0, 0, 1, 0,
	4, 0, 11, 1, 0, 0, 0, 3, 0, 0, 0, 6, 0,
	9, 0, 2, 0, 0, 0, 9, 1, 9, 0, 0, 5, 0,
	9, 0, 1, 1, 0, 0, 6, 9, 7, 0, 0, 1, 0,
	1, 1, 1, 1, 0, 0, 4, 13,5,1, 0, 15, 0,
	0, 0, 0, 10, 0, 9, 7, 0, 0, 0, 0, 19, 0,
	0, 16, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0
	},

	//第三层
	{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 13, 11, 7, 0, 11, 13, 13, 13, 13, 0,
	0, 1, 0, 5, 0, 0, 5, 0, 1, 1, 11, 0, 0,
	0, 1, 0, 5, 0, 7, 5, 0, 0, 0, 3, 0, 0,
	0, 1, 0, 2, 0, 3, 0, 0, 0, 1, 1, 1, 0,
	0, 1, 3, 18, 1, 1, 1, 1, 1, 1, 0, 1, 0,
	0, 1, 0, 2, 0, 2, 0, 0, 0, 2, 0, 1, 0,
	0, 1, 0, 18, 0, 1, 0, 0, 0, 11, 0, 13, 0,
	0, 1, 0, 7, 18, 7, 0, 0, 6, 7, 0, 6, 0,
	0, 1, 0, 0, 2, 0, 2, 0, 13, 6, 0, 7, 0,
	0, 15, 0, 4, 7, 9, 10, 0, 0, 0, 0, 18, 0,
	0, 19, 0, 4, 7, 9, 7, 0, 0, 16, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	},

	{
	0, 0, 0, 0, 1, 22, 1, 0, 0, 1, 9, 1, 0,
	0,0, 0, 0, 1, 20, 1, 0, 0, 3, 0, 3, 0,
	0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 1, 0,
	0, 0, 23, 0, 18, 18, 18, 0, 4, 11, 0, 1, 0,
	0, 0, 6, 0, 9, 9, 9, 0, 6, 0, 0, 5, 0,
	0, 0, 6, 0, 11, 10, 11, 0, 6, 0, 0, 10, 0,
	0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 10, 0,
	0, 0, 1, 0, 11, 18, 11, 0, 1, 0, 0, 9, 0,
	0,0, 1, 0, 14, 11, 14, 0, 1, 0, 0, 1, 0,
	0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 1, 0,
	0, 0, 1, 0, 4, 1, 4, 0, 1, 1, 0, 15, 0,
	0, 0, 1, 9, 1, 1, 1, 9, 1, 1, 0, 19, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	},


};



//游戏各角色单位信息：

struct gameRole
{
	int hp;//生命
	int att;//攻击力
	int def;//防御力
	int rank;//等级
	int exp;//经验
	int ykey;//黄钥匙
	int bkey;//蓝钥匙
	int money;//金币数
}player;//勇士坤


struct monster
{
	int hp;
	int att;
	int def;
	int exp; //删咯
	int img;
};
struct monster shilaimu= { 50, 30, 10, 450,9 };//史莱姆
struct monster wizard = { 50, 100, 10, 750,18 };//大法师
struct monster bat = { 30, 50, 10, 600,10};//蝙蝠
struct monster skull = { 20,100,10,500,11 };//骷髅兵
struct monster boss = { 100,900,200,100,20 };//boss


IMAGE img[25],roleInfo;
IMAGE loseimg;
IMAGE shop;
IMAGE over;
IMAGE PKimg;



//加载资源:批量加载
void loadResource()
{
	loadimage(&PKimg,"./PK.jpg");
	//loadimage(&roleInfo, "info.jpg");
	for (int i = 0; i < 24; i++)
	{
		char fileName[20] = "";
		sprintf(fileName, "%d.jpg", i);
		loadimage(img + i, fileName, 60, 60);
	}
}




//游戏失败页面
void loseView() {
	cleardevice();
	initgraph(1024, 768);
	loadimage(&loseimg, "./lose.jpg");
	putimage(0, 0, &loseimg);

	settextstyle(150, 0, "楷体");
	settextcolor(RED);
	outtextxy(250, 100, "你已死亡！！！");

	while (true) {//点击判断
		if (peekmessage(&msg, EX_MOUSE)) {}//获取鼠标消息
		
		BeginBatchDraw();

		if (button(390, 690, 200, 60, "返回菜单"))
		{
			Welcome();
		}

		EndBatchDraw();
		//将绘图过程放在两个函数之间
		msg.message = 0;
	}//循环结束后全局变量msg归零
}

//怪物手册 窗口句柄
void monsterBook() {
	
	hwnd = GetHWnd();    //弹窗前置
	
	MessageBox(hwnd, "            怪物手册    \n\
\n\
怪物名字  生命  攻击  防御  金钱\n\
史莱姆	50    30    10       10\n\
法师        100    150    10       50\n\
蝙蝠        30    38           30\n\
骷髅人       20    42    6       60\n\
深渊魔男	 100  52   12   100", "", MB_OK); 

}


void Gameinit() {
	player.hp=300;//生命
	player.att=20;//攻击力
	player.def=10;//防御力
	player.rank=1;//等级
	player.exp=0;//经验
	player.ykey=0;//黄钥匙
	player.bkey=0;//蓝钥匙
	player.money=0;//金钱

	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 13; j++) {
				map[k][i][j] = maps[k][i][j];
			}
		}
	}

}
void drawMap()
{
	BeginBatchDraw();
	
	int i, j;
	int x, y;
	//地图上所有单位显示
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			x = 60 * j;
			y = 60 * i;
			putimage(x, y, &img[map[level][i][j]]);
		}
	}



	//右边的属性框 道具栏等


	settextstyle(65, 0, "MicroSoft YaHei");
	settextcolor(RED);
	//setbkmode(TRANSPARENT);
	outtextxy(790, 10, "魔塔");


	//生命值
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	//setbkmode(TRANSPARENT);
	outtextxy(790, 100, ("生命值:" + to_string(player.hp)).data());

	//攻击力
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 150, ("攻击力:" + to_string(player.att)).data());

	//防御力
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 200, ("防御力:" + to_string(player.def)).data());

	//蓝钥匙数
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(BLUE);
	outtextxy(790, 350, ("蓝钥匙:" + to_string(player.bkey)).data());



	//黄钥匙数
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(790, 400, ("黄钥匙:" + to_string(player.ykey)).data());

	//当前的楼层
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(790, 450, ("当前楼层:" + to_string(level+1)).data());


	//等级
	
	/*
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 250, ("等级:" + to_string(player.rank)).data());
	

	//经验值
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 300, ("经验值:" + to_string(player.exp)).data());
	*/


	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 250, ("金币:" + to_string(player.money)).data());
	
	//string weapon = "铁剑";
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(790, 500, "当前武器:");

	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(790, 530, weapon.data());

	settextstyle(20, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 580, "按G键存档");

	settextstyle(20, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 610, "按E键打开商城");

	settextstyle(20, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(778, 640, "按R键打开怪物手册");

	settextstyle(20, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 670, "按Q键退出游戏");


	EndBatchDraw();

}

int PKdraw(struct monster mon) {
	
		
		
	
	return 1;
}

int PK(struct monster mon)//打怪的过程   过程略 
{
	
	if (player.def < mon.att)
		monatt = mon.att - player.def;
	else monatt = 0;

	if (mon.def < player.att)
		playeratt = player.att - mon.def;
	else playeratt = 0;

	while (player.hp > 0 && mon.hp > 0) {
		player.hp -= monatt;
		mon.hp -= playeratt;
		
		putimage(150, 200, &PKimg);
		putimage(180, 250, &img[mon.img]);
		putimage(620, 250, &img[15]);

		settextstyle(50, 0, "MicroSoft YaHei");
		settextcolor(YELLOW);
		outtextxy(660, 320, to_string(player.hp).data());

		
		settextstyle(50, 0, "MicroSoft YaHei");
		settextcolor(YELLOW);
		outtextxy(660, 370, to_string(player.att).data());

		
		settextstyle(50, 0, "MicroSoft YaHei");
		settextcolor(YELLOW);
		outtextxy(660, 420, to_string(player.def).data());

		
		settextstyle(50, 0, "MicroSoft YaHei");
		settextcolor(YELLOW);
		outtextxy(250, 320, to_string(mon.hp).data());

		
		settextstyle(50, 0, "MicroSoft YaHei");
		settextcolor(YELLOW);
		outtextxy(250, 370, to_string(mon.att).data());

		
		settextstyle(50, 0, "MicroSoft YaHei");
		settextcolor(YELLOW);
		outtextxy(250, 420, to_string(mon.def).data());

		Sleep(1000);

	}
	if (player.hp <= 0)
		return 0;
	else
	{
		//player.exp += mon.exp;
		return 1;
	}
}



//碰撞的文字显示
void Pick(const TCHAR* message) {

	
	settextcolor(YELLOW);
	settextstyle(45, 0, "MicroSoft YaHei");
	outtextxy(320, 145, message);

	clock_t start_time = clock();

	while ((clock() - start_time) * 1000 / CLOCKS_PER_SEC  < 500) {
	}
	
	setcolor(getbkcolor());
	outtextxy(250, 250, message);
}

void gameoverView() {
	
	
	initgraph(700, 490);
	cleardevice();
	loadimage(&over,"./over.jpg");
	putimage(0, 0, &over);

	settextstyle(60, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(280, 90, "恭喜你！");

	settextstyle(60, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(280, 150, "你成功救出了公主！");

	while (true) {
		if (peekmessage(&msg, EX_MOUSE)) {}
	
		BeginBatchDraw();

		if (button(260, 330, 200, 60, "返回菜单"))
		{
			Welcome();
		}

		EndBatchDraw();

		msg.message = 0;
	}

}

//人物移动和碰撞游戏单位
void playerMove()
{

	int i = 0, j = 0;

	//墙
	for (i = 0; i < 13; i++)
	{

		for (j = 0; j < 13; j++)

			if (map[level][i][j] == 15)
				break;	

		if (map[level][i][j] == 15)
			break;	

	}


	

	char userkey = _getch();
	switch (userkey) {
	case'a':
	case'A':
		//当要去的地方是空地 1 表示能走 
		if (map[level][i][j - 1] == 1)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
		}

		//换楼层
		else if (map[level][i][j - 1] == 16)
		{
			map[level][i][j] = 15;
			level++;
			Pick(("你已到达下一层"));
		}
		else if (map[level][i][j - 1] == 5)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			player.ykey++;//捡到黄钥匙
			Pick(("你捡到了黄钥匙"));
		}
		else if (map[level][i][j - 1] == 3 && player.ykey > 0)
		{
			player.ykey--;//用黄钥匙
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			Pick(("门已打开"));
		}

		else if (map[level][i][j - 1] == 4)
		{

			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			player.bkey++;//捡到了蓝钥匙
			Pick(("你捡到了蓝钥匙"));

		}
		else if (map[level][i][j - 1] == 2 && player.bkey > 0)
		{
			player.bkey--;//用蓝钥匙
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			Pick(("门已打开"));
		}

		else if (map[level][i][j - 1] == 13)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			player.def += 10;//捡到了宝石
			Pick(("你捡到了宝石 防御值+10"));
		}
		else if (map[level][i][j - 1] == 7)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			player.hp += 100;//捡到了蓝药水
			Pick(("你捡到了蓝药水 生命值+100"));
		}
		else if (map[level][i][j - 1] == 6)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			player.hp += 300;//捡到了红药水
			Pick(("你捡到了红药水 生命值+300"));
		}
		else if (map[level][i][j - 1] == 10)
		{
			if (PK(bat)) {


				map[level][i][j] = 1;
				map[level][i][j - 1] = 15;
				player.money += 50;
				Pick(("你已击杀蝙蝠 获得50金币"));
			}

		}
		else if (map[level][i][j - 1] == 18)
		{
			if (PK(wizard)) {


				map[level][i][j] = 1;
				map[level][i][j - 1] = 15;
				player.money += 100;
				Pick(("你已击杀大法师 获得100金币"));
			}

		}
		else if (map[level][i][j - 1] == 9)
		{
			if (PK(shilaimu)) {


				map[level][i][j] = 1;
				map[level][i][j - 1] = 15;
				player.money += 20;
				Pick(("你已击杀史莱姆 获得20金币"));
			}

		}

		else if (map[level][i][j - 1] == 11)
		{
			if (PK(skull)) {


				map[level][i][j] = 1;
				map[level][i][j - 1] = 15;
				player.money += 500;
				Pick(("你已击杀骷髅王 获得500金币"));
			}
			
		}
		else if (map[level][i][j - 1] == 21)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			weapon = "勇者双剑";
			player.att = 100;
			Pick(("你捡到了武器：勇者双剑"));
			}
		break;




		//右
	case'd':
	case'D':
		if (map[level][i][j + 1] == 1)
		{
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
		}
		else if (map[level][i][j + 1] == 5)
		{
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			player.ykey++;//捡到黄钥匙
			Pick(("你捡到了黄钥匙"));
		}
		else if (map[level][i][j + 1] == 3 && player.ykey > 0)
		{
			player.ykey--;//用黄钥匙
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			Pick(("门已打开"));
		}

		else if (map[level][i][j + 1] == 4)
		{
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			player.bkey++;//捡到了蓝钥匙
			Pick(("你捡到了蓝钥匙"));
		}
		else if (map[level][i][j + 1] == 2 && player.bkey > 0)
		{
			player.bkey--;//用蓝钥匙
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			Pick(("门已打开"));
		}
		else if (map[level][i][j + 1] == 13)
		{
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			player.def += 10;//捡到了宝石
			Pick(("你捡到了宝石 防御力+10！"));
		}
		else if (map[level][i][j + 1] == 7)
		{
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			player.hp += 100;//捡到了蓝药水
			Pick(("你捡到了蓝药水 生命值+100"));
		}
		else if (map[level][i][j + 1] == 6)
		{
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			player.hp += 300;//捡到了红药水
			Pick(("你捡到了红药水 生命值+300"));
		}
		else if (map[level][i][j + 1] == 10)
		{
			if (PK(bat)) {


				map[level][i][j] = 1;
				map[level][i][j + 1] = 15;
				player.money += 50;
				Pick(("你已击杀蝙蝠 获得50金币"));
			}

		}
		else if (map[level][i][j + 1] == 18)
		{
			if (PK(wizard)) {


				map[level][i][j] = 1;
				map[level][i][j + 1] = 15;
				player.money += 100;
				Pick(("你已击杀大法师 获得100金币"));
			}

		}
		else if (map[level][i][j + 1] == 9)
		{
			if (PK(shilaimu)) {


				map[level][i][j] = 1;
				map[level][i][j + 1] = 15;
				player.money += 20;
				Pick(("你已击杀史莱姆 获得20金币"));
			}

		}
		else if (map[level][i][j + 1] == 11)
		{
			if (PK(skull)) {


				map[level][i][j] = 1;
				map[level][i][j + 1] = 15;
				player.money += 500;
				Pick(("你已击杀骷髅王 获得500金币"));
			}

		}

		break;


		//上.
	case'W':
	case'w':
		if (map[level][i - 1][j] == 1)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
		}
		else if (map[level][i - 1][j] == 5)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			player.ykey++;//捡到黄钥匙
			Pick(("你捡到了黄钥匙"));
		}
		else if (map[level][i - 1][j] == 3 && player.ykey > 0)
		{
			player.ykey--;//用黄钥匙
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			Pick(("门已打开"));
		}

		else if (map[level][i - 1][j] == 4)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			player.bkey++;//捡到了蓝钥匙
			Pick(("你捡到了蓝钥匙"));
		}
		else if (map[level][i - 1][j] == 2 && player.bkey > 0)
		{
			player.bkey--;//用蓝钥匙
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			Pick(("门已打开"));
		}

		else if (map[level][i - 1][j] == 13)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			player.def += 10;//捡到了宝石
			Pick(("你捡到了宝石 防御值+10"));
		}
		else if (map[level][i - 1][j] == 7)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			player.hp += 100;//捡到了蓝药水
			Pick(("你捡到了蓝药水 生命值+100"));
		}
		else if (map[level][i - 1][j] == 6)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			player.hp += 300;//捡到了红药水
			Pick(("你捡到了红药水 生命值+300"));
		}
		else if (map[level][i - 1][j] == 10)
		{
			if (PK(bat)) {
				map[level][i][j] = 1;
				map[level][i - 1][j] = 15;
				player.money += 50;
				Pick(("你已击杀蝙蝠 获得50金币"));
			}

		}
		else if (map[level][i - 1][j] == 18)
		{
			if (PK(wizard)) {


				map[level][i][j] = 1;
				map[level][i - 1][j] = 15;
				player.money += 100;
				Pick(("你已击杀大法师 获得100金币"));
			}

		}
		else if (map[level][i - 1][j] == 9)
		{
			if (PK(shilaimu)) {


				map[level][i][j] = 1;
				map[level][i - 1][j] = 15;
				player.money += 20;
				Pick(("你已击杀史莱姆"));
			}

		}
		else if (map[level][i - 1][j] == 11)
		{
			
			if (PK(skull)) {

				
				map[level][i][j] = 1;
				map[level][i - 1][j] = 15;
				player.money += 500;
				Pick(("你已击杀骷髅王 获得500金币"));
			}

		}
		else if (map[level][i-1][j ] == 21)
		{
			map[level][i][j] = 1;
			map[level][i-1][j] = 15;
			weapon = "勇者双剑";
			player.att = 100;
			Pick(("你捡到了武器：勇者双剑"));
			}
		else if (map[level][i - 1][j] == 23)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			weapon = "幽兰圣剑";
			player.att = 300;
			Pick(("你捡到了武器：幽兰圣剑"));
			}
		else if (map[level][i - 1][j] ==20)
		{
			if (PK(boss)) {
				map[level][i][j] = 1;
				map[level][i - 1][j] = 15;
				Pick(("你已击杀深渊魔男！去迎接公主吧！"));
			}
		}
		else if (map[level][i - 1][j] == 22)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			gameoverView();
			}

		break;



		//下

	case'S':
	case's':
		if (map[level][i + 1][j] == 1)
		{
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
		}
		else if (map[level][i + 1][j] == 5)
		{
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			player.ykey++;//捡到黄钥匙
			Pick(("你捡到了黄钥匙"));
		}
		else if (map[level][i + 1][j] == 3 && player.ykey > 0)
		{
			player.ykey--;//用黄钥匙
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			Pick(("门已打开"));
		}

		else if (map[level][i + 1][j] == 4)
		{
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			player.bkey++;//捡到了蓝钥匙
			Pick(("你捡到了蓝钥匙"));
		}
		else if (map[level][i + 1][j] == 2 && player.bkey > 0)
		{
			player.bkey--;//用蓝钥匙
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			Pick(("门已打开"));
		}
		else if (map[level][i + 1][j] == 13)
		{
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			player.def += 10;//捡到了宝石
			Pick(("你捡到了宝石 防御值+10"));
		}
		else if (map[level][i + 1][j] == 7)
		{
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			player.hp += 100;//捡到了蓝药水
			Pick(("你捡到了蓝药水 生命值+100"));
		}
		else if (map[level][i + 1][j] == 6)
		{
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			player.hp += 300;//捡到了红药水
			Pick(("你捡到了红药水 生命值+300"));
		}
		else if (map[level][i + 1][j] == 10)
		{
			if (PK(bat)) {


				map[level][i][j] = 1;
				map[level][i + 1][j] = 15;
				player.money += 50;
				Pick(("你已击杀蝙蝠"));
			}

		}
		else if (map[level][i + 1][j] == 18)
		{
			if (PK(wizard)) {
				map[level][i][j] = 1;
				map[level][i + 1][j] = 15;
				player.money += 100;
				Pick(("你已击杀大法师 获得100金币"));
			}

		}
		else if (map[level][i + 1][j] == 9)
		{
			if (PK(shilaimu)) {

				map[level][i][j] = 1;
				map[level][i + 1][j] = 15;
				player.money += 20;
				Pick(("你已击杀史莱姆 获得20金币"));
			}

		}


		else if (map[level][i + 1][j] == 11)
		{
			if (PK(skull)) {


				map[level][i][j] = 1;
				map[level][i + 1][j] = 15;
				player.money += 500;
				Pick(("你已击杀骷髅王"));
			}

		}
		else if (map[level][i + 1][j] == 19)
		{
			map[level][i][j] = 15;
			level--;
			Pick(("你已回到上一层"));

		}
		break;

		case'E':
		case'e':
			shopView();
			break;

		case'R':
		case'r':
			monsterBook();
			break;

		case'Q':
		case'q':
			exit(0);
			break;
			
	}

}






//写入玩家数值
void cundanguser() {
	ofstream fout;
	string filename1 = "./user.txt";

	fout.open(filename1, ios::trunc);
	fout << player.hp <<' ';
	fout << player.att <<' ';
	fout << player.def<<' ';
	fout << player.money <<' ';
	fout << player.bkey <<' ';
	fout << player.ykey <<' ';
	fout << level ;

	fout.close();
}

//写入地图
void cundangmap() {

	ofstream fout;

	string filename2 = "./map.txt";
	fout.open(filename2, ios::trunc);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			for (int k = 0; k < 13; ++k) {
				fout << map[i][j][k] << ' ';
			}
			fout << '\n';
		}
		//fout << '\n';
	}
	fout.close();
}


/*

void judge() {
	fstream rduser;
	rduser.open("user.txt", ios::in);
	//FILE* fpuser = fopen("user.txt", "r");
	//FILE* fpmap = fopen("map.txt", "r");
	if (rduser.eof()) {
		hwnd = GetHWnd();    //弹窗前置
		flag = 1;
	MessageBox(hwnd, " 未找到存档\n\
", "", MB_OK); 
	}
	else {
		readmap();
		readuser();
	}
}
*/

////读入玩家信息
void readuser() {
	
	FILE* fp = fopen("user.txt", "r");

	char buffer[256];
	if (fp) {
		fgets(buffer,256,fp);
		sscanf(buffer, "%d %d %d %d %d %d", &player.hp, &player.att, &player.def, &player.bkey, &player.ykey,&level);
		fclose(fp);
	}
	
}

void readmap() {
	// 读地图数据
	FILE* fp = fopen("map.txt", "r");
	char buffer[150];
	if (fp) {
		//while(fgets(buffer,256,fp))
		for (int k = 0; k < 4; ++k) {
				for (int i = 0; i < 13; ++i) {
					fgets(buffer, 150, fp);
					sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d %d %d %d ", &map[k][i][0], &map[k][i][1], & map[k][i][2] ,& map[k][i][3] ,& map[k][i][4], & map[k][i][5], & map[k][i][6], & map[k][i][7], & map[k][i][8], & map[k][i][9], & map[k][i][10], & map[k][i][11], & map[k][i][12]);
				}
				//printf("\n");
			}
			//fgetc(fp);
			
		}
		fclose(fp);
	}






void shopView() {
	initgraph(60 * 15, 60 * 13);
	loadimage(&shop, "./shop.jpg", 60 * 15, 60 * 13);
	while (1) {
		putimage(0, 0, &shop);

		while (true) {   
			if (peekmessage(&msg, EX_MOUSE)) {}
			BeginBatchDraw();

			settextstyle(100, 0, "楷体");
			settextcolor(RED);
			outtextxy(220, 10, "游戏商城");
			settextstyle(50, 0, "MicroSoft YaHei");
			settextcolor(RED);
			outtextxy(120, 280, "防御力+10   所需金币：120");
		
			settextstyle(50, 0, "MicroSoft YaHei");
			settextcolor(RED);
			outtextxy(120, 350, "攻击力+10   所需金币：100");


			if (button(650, 350, 60, 60, "购买") && player.money >= 100) {
				player.money -= 100;
				player.att += 10;
				Pick("购买成功！ 攻击力+10");

			}
			else if (button(650, 350, 60, 60, "购买") && player.money < 100)Pick("金币不足！");



			if (button(650, 280, 60, 60, "购买") &&player.money>=120) {
				player.money -= 20;
				player.def += 10;
				Pick("购买成功！ 防御力+10");
				
			}
			else if (button(650, 280, 60, 60, "购买") && player.money < 120)Pick("金币不足！");


			if (button(700, 650, 60, 60, "返回游戏")) {
				return;
			}

			settextstyle(45, 0, "MicroSoft YaHei");
			settextcolor(RED);
			outtextxy(290, 225, ("你所持有的金币数:" + to_string(player.money)).data());
		
			EndBatchDraw();
			msg.message = 0;

		}

	}
}




void ctrlFps(int start_time) //控制帧率
{
	clock_t running_time = clock() - start_time;
		Sleep(13 - running_time);

	int FPS = 1000 / (clock() - start_time);

	
}


void playgame() {

	cleardevice();
	initgraph(60 * 15, 60 * 13);
	
	
	while (1)
	{
		if (GetAsyncKeyState('G')) { 
			cundangmap();
			cundanguser();
			Pick("存档成功！");
		}


		
		//expup();
		if (player.hp <= 0)loseView();

		
		
		drawMap();
		playerMove();
		
		int start_time = clock();
		ctrlFps(start_time);
	}
	
}






void Welcome()
{

	initgraph(830, 680);

	//标题
	settextstyle(150, 150, "楷体");
	settextcolor(YELLOW);
	outtextxy(120, 100, "魔塔");

	//作者
	settextstyle(32, 16, "华文琥珀");
	outtextxy(300, 630, "制作人: 22计科01刘 涛 ");


	while (true)
	{
		if(peekmessage(&msg, EX_MOUSE)){}
		
		BeginBatchDraw();
		if (button(350,  400, 200, 60, "开始游戏"))
		{
			
			loadResource();
			Gameinit();
			playgame();

		}
		if (button(350, 480, 200, 60, "继续游戏"))
		{
			loadResource();
			//judge();
			readmap();
			readuser();
			playgame();
			
		}
		EndBatchDraw();
		msg.message = 0;
	}

}
	

int main()
{
	//parsefile(". / maps.txt");
	Welcome();
	//system("pause");
	return 0;

}
