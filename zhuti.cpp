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
#include"����.h"
#include"Button.h"
using namespace std;


HWND hwnd;
int count = 400;
int flag = 0;
int level = 0;

int playeratt = 0, monatt = 0;
string weapon = "����";
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
	//��һ��
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

	//�ڶ���
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

	//������
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



//��Ϸ����ɫ��λ��Ϣ��

struct gameRole
{
	int hp;//����
	int att;//������
	int def;//������
	int rank;//�ȼ�
	int exp;//����
	int ykey;//��Կ��
	int bkey;//��Կ��
	int money;//�����
}player;//��ʿ��


struct monster
{
	int hp;
	int att;
	int def;
	int exp; //ɾ��
	int img;
};
struct monster shilaimu= { 50, 30, 10, 450,9 };//ʷ��ķ
struct monster wizard = { 50, 100, 10, 750,18 };//��ʦ
struct monster bat = { 30, 50, 10, 600,10};//����
struct monster skull = { 20,100,10,500,11 };//���ñ�
struct monster boss = { 100,900,200,100,20 };//boss


IMAGE img[25],roleInfo;
IMAGE loseimg;
IMAGE shop;
IMAGE over;
IMAGE PKimg;



//������Դ:��������
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




//��Ϸʧ��ҳ��
void loseView() {
	cleardevice();
	initgraph(1024, 768);
	loadimage(&loseimg, "./lose.jpg");
	putimage(0, 0, &loseimg);

	settextstyle(150, 0, "����");
	settextcolor(RED);
	outtextxy(250, 100, "��������������");

	while (true) {//����ж�
		if (peekmessage(&msg, EX_MOUSE)) {}//��ȡ�����Ϣ
		
		BeginBatchDraw();

		if (button(390, 690, 200, 60, "���ز˵�"))
		{
			Welcome();
		}

		EndBatchDraw();
		//����ͼ���̷�����������֮��
		msg.message = 0;
	}//ѭ��������ȫ�ֱ���msg����
}

//�����ֲ� ���ھ��
void monsterBook() {
	
	hwnd = GetHWnd();    //����ǰ��
	
	MessageBox(hwnd, "            �����ֲ�    \n\
\n\
��������  ����  ����  ����  ��Ǯ\n\
ʷ��ķ	50    30    10       10\n\
��ʦ        100    150    10       50\n\
����        30    38           30\n\
������       20    42    6       60\n\
��Ԩħ��	 100  52   12   100", "", MB_OK); 

}


void Gameinit() {
	player.hp=300;//����
	player.att=20;//������
	player.def=10;//������
	player.rank=1;//�ȼ�
	player.exp=0;//����
	player.ykey=0;//��Կ��
	player.bkey=0;//��Կ��
	player.money=0;//��Ǯ

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
	//��ͼ�����е�λ��ʾ
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			x = 60 * j;
			y = 60 * i;
			putimage(x, y, &img[map[level][i][j]]);
		}
	}



	//�ұߵ����Կ� ��������


	settextstyle(65, 0, "MicroSoft YaHei");
	settextcolor(RED);
	//setbkmode(TRANSPARENT);
	outtextxy(790, 10, "ħ��");


	//����ֵ
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	//setbkmode(TRANSPARENT);
	outtextxy(790, 100, ("����ֵ:" + to_string(player.hp)).data());

	//������
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 150, ("������:" + to_string(player.att)).data());

	//������
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 200, ("������:" + to_string(player.def)).data());

	//��Կ����
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(BLUE);
	outtextxy(790, 350, ("��Կ��:" + to_string(player.bkey)).data());



	//��Կ����
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(790, 400, ("��Կ��:" + to_string(player.ykey)).data());

	//��ǰ��¥��
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(790, 450, ("��ǰ¥��:" + to_string(level+1)).data());


	//�ȼ�
	
	/*
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 250, ("�ȼ�:" + to_string(player.rank)).data());
	

	//����ֵ
	
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 300, ("����ֵ:" + to_string(player.exp)).data());
	*/


	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 250, ("���:" + to_string(player.money)).data());
	
	//string weapon = "����";
	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(790, 500, "��ǰ����:");

	settextstyle(25, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(790, 530, weapon.data());

	settextstyle(20, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 580, "��G���浵");

	settextstyle(20, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 610, "��E�����̳�");

	settextstyle(20, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(778, 640, "��R���򿪹����ֲ�");

	settextstyle(20, 0, "MicroSoft YaHei");
	settextcolor(RED);
	outtextxy(790, 670, "��Q���˳���Ϸ");


	EndBatchDraw();

}

int PKdraw(struct monster mon) {
	
		
		
	
	return 1;
}

int PK(struct monster mon)//��ֵĹ���   ������ 
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



//��ײ��������ʾ
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
	outtextxy(280, 90, "��ϲ�㣡");

	settextstyle(60, 0, "MicroSoft YaHei");
	settextcolor(YELLOW);
	outtextxy(280, 150, "��ɹ��ȳ��˹�����");

	while (true) {
		if (peekmessage(&msg, EX_MOUSE)) {}
	
		BeginBatchDraw();

		if (button(260, 330, 200, 60, "���ز˵�"))
		{
			Welcome();
		}

		EndBatchDraw();

		msg.message = 0;
	}

}

//�����ƶ�����ײ��Ϸ��λ
void playerMove()
{

	int i = 0, j = 0;

	//ǽ
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
		//��Ҫȥ�ĵط��ǿյ� 1 ��ʾ���� 
		if (map[level][i][j - 1] == 1)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
		}

		//��¥��
		else if (map[level][i][j - 1] == 16)
		{
			map[level][i][j] = 15;
			level++;
			Pick(("���ѵ�����һ��"));
		}
		else if (map[level][i][j - 1] == 5)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			player.ykey++;//�񵽻�Կ��
			Pick(("����˻�Կ��"));
		}
		else if (map[level][i][j - 1] == 3 && player.ykey > 0)
		{
			player.ykey--;//�û�Կ��
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			Pick(("���Ѵ�"));
		}

		else if (map[level][i][j - 1] == 4)
		{

			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			player.bkey++;//������Կ��
			Pick(("�������Կ��"));

		}
		else if (map[level][i][j - 1] == 2 && player.bkey > 0)
		{
			player.bkey--;//����Կ��
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			Pick(("���Ѵ�"));
		}

		else if (map[level][i][j - 1] == 13)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			player.def += 10;//���˱�ʯ
			Pick(("����˱�ʯ ����ֵ+10"));
		}
		else if (map[level][i][j - 1] == 7)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			player.hp += 100;//������ҩˮ
			Pick(("�������ҩˮ ����ֵ+100"));
		}
		else if (map[level][i][j - 1] == 6)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			player.hp += 300;//���˺�ҩˮ
			Pick(("����˺�ҩˮ ����ֵ+300"));
		}
		else if (map[level][i][j - 1] == 10)
		{
			if (PK(bat)) {


				map[level][i][j] = 1;
				map[level][i][j - 1] = 15;
				player.money += 50;
				Pick(("���ѻ�ɱ���� ���50���"));
			}

		}
		else if (map[level][i][j - 1] == 18)
		{
			if (PK(wizard)) {


				map[level][i][j] = 1;
				map[level][i][j - 1] = 15;
				player.money += 100;
				Pick(("���ѻ�ɱ��ʦ ���100���"));
			}

		}
		else if (map[level][i][j - 1] == 9)
		{
			if (PK(shilaimu)) {


				map[level][i][j] = 1;
				map[level][i][j - 1] = 15;
				player.money += 20;
				Pick(("���ѻ�ɱʷ��ķ ���20���"));
			}

		}

		else if (map[level][i][j - 1] == 11)
		{
			if (PK(skull)) {


				map[level][i][j] = 1;
				map[level][i][j - 1] = 15;
				player.money += 500;
				Pick(("���ѻ�ɱ������ ���500���"));
			}
			
		}
		else if (map[level][i][j - 1] == 21)
		{
			map[level][i][j] = 1;
			map[level][i][j - 1] = 15;
			weapon = "����˫��";
			player.att = 100;
			Pick(("���������������˫��"));
			}
		break;




		//��
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
			player.ykey++;//�񵽻�Կ��
			Pick(("����˻�Կ��"));
		}
		else if (map[level][i][j + 1] == 3 && player.ykey > 0)
		{
			player.ykey--;//�û�Կ��
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			Pick(("���Ѵ�"));
		}

		else if (map[level][i][j + 1] == 4)
		{
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			player.bkey++;//������Կ��
			Pick(("�������Կ��"));
		}
		else if (map[level][i][j + 1] == 2 && player.bkey > 0)
		{
			player.bkey--;//����Կ��
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			Pick(("���Ѵ�"));
		}
		else if (map[level][i][j + 1] == 13)
		{
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			player.def += 10;//���˱�ʯ
			Pick(("����˱�ʯ ������+10��"));
		}
		else if (map[level][i][j + 1] == 7)
		{
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			player.hp += 100;//������ҩˮ
			Pick(("�������ҩˮ ����ֵ+100"));
		}
		else if (map[level][i][j + 1] == 6)
		{
			map[level][i][j] = 1;
			map[level][i][j + 1] = 15;
			player.hp += 300;//���˺�ҩˮ
			Pick(("����˺�ҩˮ ����ֵ+300"));
		}
		else if (map[level][i][j + 1] == 10)
		{
			if (PK(bat)) {


				map[level][i][j] = 1;
				map[level][i][j + 1] = 15;
				player.money += 50;
				Pick(("���ѻ�ɱ���� ���50���"));
			}

		}
		else if (map[level][i][j + 1] == 18)
		{
			if (PK(wizard)) {


				map[level][i][j] = 1;
				map[level][i][j + 1] = 15;
				player.money += 100;
				Pick(("���ѻ�ɱ��ʦ ���100���"));
			}

		}
		else if (map[level][i][j + 1] == 9)
		{
			if (PK(shilaimu)) {


				map[level][i][j] = 1;
				map[level][i][j + 1] = 15;
				player.money += 20;
				Pick(("���ѻ�ɱʷ��ķ ���20���"));
			}

		}
		else if (map[level][i][j + 1] == 11)
		{
			if (PK(skull)) {


				map[level][i][j] = 1;
				map[level][i][j + 1] = 15;
				player.money += 500;
				Pick(("���ѻ�ɱ������ ���500���"));
			}

		}

		break;


		//��.
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
			player.ykey++;//�񵽻�Կ��
			Pick(("����˻�Կ��"));
		}
		else if (map[level][i - 1][j] == 3 && player.ykey > 0)
		{
			player.ykey--;//�û�Կ��
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			Pick(("���Ѵ�"));
		}

		else if (map[level][i - 1][j] == 4)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			player.bkey++;//������Կ��
			Pick(("�������Կ��"));
		}
		else if (map[level][i - 1][j] == 2 && player.bkey > 0)
		{
			player.bkey--;//����Կ��
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			Pick(("���Ѵ�"));
		}

		else if (map[level][i - 1][j] == 13)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			player.def += 10;//���˱�ʯ
			Pick(("����˱�ʯ ����ֵ+10"));
		}
		else if (map[level][i - 1][j] == 7)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			player.hp += 100;//������ҩˮ
			Pick(("�������ҩˮ ����ֵ+100"));
		}
		else if (map[level][i - 1][j] == 6)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			player.hp += 300;//���˺�ҩˮ
			Pick(("����˺�ҩˮ ����ֵ+300"));
		}
		else if (map[level][i - 1][j] == 10)
		{
			if (PK(bat)) {
				map[level][i][j] = 1;
				map[level][i - 1][j] = 15;
				player.money += 50;
				Pick(("���ѻ�ɱ���� ���50���"));
			}

		}
		else if (map[level][i - 1][j] == 18)
		{
			if (PK(wizard)) {


				map[level][i][j] = 1;
				map[level][i - 1][j] = 15;
				player.money += 100;
				Pick(("���ѻ�ɱ��ʦ ���100���"));
			}

		}
		else if (map[level][i - 1][j] == 9)
		{
			if (PK(shilaimu)) {


				map[level][i][j] = 1;
				map[level][i - 1][j] = 15;
				player.money += 20;
				Pick(("���ѻ�ɱʷ��ķ"));
			}

		}
		else if (map[level][i - 1][j] == 11)
		{
			
			if (PK(skull)) {

				
				map[level][i][j] = 1;
				map[level][i - 1][j] = 15;
				player.money += 500;
				Pick(("���ѻ�ɱ������ ���500���"));
			}

		}
		else if (map[level][i-1][j ] == 21)
		{
			map[level][i][j] = 1;
			map[level][i-1][j] = 15;
			weapon = "����˫��";
			player.att = 100;
			Pick(("���������������˫��"));
			}
		else if (map[level][i - 1][j] == 23)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			weapon = "����ʥ��";
			player.att = 300;
			Pick(("���������������ʥ��"));
			}
		else if (map[level][i - 1][j] ==20)
		{
			if (PK(boss)) {
				map[level][i][j] = 1;
				map[level][i - 1][j] = 15;
				Pick(("���ѻ�ɱ��Ԩħ�У�ȥӭ�ӹ����ɣ�"));
			}
		}
		else if (map[level][i - 1][j] == 22)
		{
			map[level][i][j] = 1;
			map[level][i - 1][j] = 15;
			gameoverView();
			}

		break;



		//��

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
			player.ykey++;//�񵽻�Կ��
			Pick(("����˻�Կ��"));
		}
		else if (map[level][i + 1][j] == 3 && player.ykey > 0)
		{
			player.ykey--;//�û�Կ��
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			Pick(("���Ѵ�"));
		}

		else if (map[level][i + 1][j] == 4)
		{
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			player.bkey++;//������Կ��
			Pick(("�������Կ��"));
		}
		else if (map[level][i + 1][j] == 2 && player.bkey > 0)
		{
			player.bkey--;//����Կ��
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			Pick(("���Ѵ�"));
		}
		else if (map[level][i + 1][j] == 13)
		{
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			player.def += 10;//���˱�ʯ
			Pick(("����˱�ʯ ����ֵ+10"));
		}
		else if (map[level][i + 1][j] == 7)
		{
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			player.hp += 100;//������ҩˮ
			Pick(("�������ҩˮ ����ֵ+100"));
		}
		else if (map[level][i + 1][j] == 6)
		{
			map[level][i][j] = 1;
			map[level][i + 1][j] = 15;
			player.hp += 300;//���˺�ҩˮ
			Pick(("����˺�ҩˮ ����ֵ+300"));
		}
		else if (map[level][i + 1][j] == 10)
		{
			if (PK(bat)) {


				map[level][i][j] = 1;
				map[level][i + 1][j] = 15;
				player.money += 50;
				Pick(("���ѻ�ɱ����"));
			}

		}
		else if (map[level][i + 1][j] == 18)
		{
			if (PK(wizard)) {
				map[level][i][j] = 1;
				map[level][i + 1][j] = 15;
				player.money += 100;
				Pick(("���ѻ�ɱ��ʦ ���100���"));
			}

		}
		else if (map[level][i + 1][j] == 9)
		{
			if (PK(shilaimu)) {

				map[level][i][j] = 1;
				map[level][i + 1][j] = 15;
				player.money += 20;
				Pick(("���ѻ�ɱʷ��ķ ���20���"));
			}

		}


		else if (map[level][i + 1][j] == 11)
		{
			if (PK(skull)) {


				map[level][i][j] = 1;
				map[level][i + 1][j] = 15;
				player.money += 500;
				Pick(("���ѻ�ɱ������"));
			}

		}
		else if (map[level][i + 1][j] == 19)
		{
			map[level][i][j] = 15;
			level--;
			Pick(("���ѻص���һ��"));

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






//д�������ֵ
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

//д���ͼ
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
		hwnd = GetHWnd();    //����ǰ��
		flag = 1;
	MessageBox(hwnd, " δ�ҵ��浵\n\
", "", MB_OK); 
	}
	else {
		readmap();
		readuser();
	}
}
*/

////���������Ϣ
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
	// ����ͼ����
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

			settextstyle(100, 0, "����");
			settextcolor(RED);
			outtextxy(220, 10, "��Ϸ�̳�");
			settextstyle(50, 0, "MicroSoft YaHei");
			settextcolor(RED);
			outtextxy(120, 280, "������+10   �����ң�120");
		
			settextstyle(50, 0, "MicroSoft YaHei");
			settextcolor(RED);
			outtextxy(120, 350, "������+10   �����ң�100");


			if (button(650, 350, 60, 60, "����") && player.money >= 100) {
				player.money -= 100;
				player.att += 10;
				Pick("����ɹ��� ������+10");

			}
			else if (button(650, 350, 60, 60, "����") && player.money < 100)Pick("��Ҳ��㣡");



			if (button(650, 280, 60, 60, "����") &&player.money>=120) {
				player.money -= 20;
				player.def += 10;
				Pick("����ɹ��� ������+10");
				
			}
			else if (button(650, 280, 60, 60, "����") && player.money < 120)Pick("��Ҳ��㣡");


			if (button(700, 650, 60, 60, "������Ϸ")) {
				return;
			}

			settextstyle(45, 0, "MicroSoft YaHei");
			settextcolor(RED);
			outtextxy(290, 225, ("�������еĽ����:" + to_string(player.money)).data());
		
			EndBatchDraw();
			msg.message = 0;

		}

	}
}




void ctrlFps(int start_time) //����֡��
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
			Pick("�浵�ɹ���");
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

	//����
	settextstyle(150, 150, "����");
	settextcolor(YELLOW);
	outtextxy(120, 100, "ħ��");

	//����
	settextstyle(32, 16, "��������");
	outtextxy(300, 630, "������: 22�ƿ�01�� �� ");


	while (true)
	{
		if(peekmessage(&msg, EX_MOUSE)){}
		
		BeginBatchDraw();
		if (button(350,  400, 200, 60, "��ʼ��Ϸ"))
		{
			
			loadResource();
			Gameinit();
			playgame();

		}
		if (button(350, 480, 200, 60, "������Ϸ"))
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
