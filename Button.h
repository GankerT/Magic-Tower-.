#pragma once
#include <easyx.h>
//������Ϣ�ṹ�����
ExMessage msg = { 0 };
//�����ĳ��������ж����� inArea(�������Ͻ�x����,�������Ͻ�y����,���x����,���y����,������,����߶�)
bool inArea(int x, int y, int mx, int my, int w, int h) {
	if (mx > x && mx<(x + w) && my>y && my < (y + h)) {
		return true;
	}
	return false;
}
//��ť�Ĵ������� button(��ť���Ͻ�x����,��ť���Ͻ�y����,��ť���,��ť�߶�,��ť���ı�)
bool button(int x, int y, int w, int h, const char* text) {
	//����ڰ�ť����һ����ɫ
	if (inArea(x, y, msg.x, msg.y, w, h)) {
		setfillcolor(RGB(255, 191, 107));
	}

	else {//���ھ�����һ��
		setfillcolor(RGB(0, 0, 0));
	}

	//��һ�����ΰ�ť
	fillroundrect(x, y, x + w, y + h, 55, 55);
	settextcolor(RED);
	//setbkmode(TRANSPARENT);//�ı�����ģʽ��͸��
	settextstyle(35, 0, "΢���ź�");
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	outtextxy(x + hSpace, y + vSpace, text);
	if (msg.message == WM_LBUTTONDOWN && inArea(x, y, msg.x, msg.y, w, h)) {
		return true;
	}
	return false;
}