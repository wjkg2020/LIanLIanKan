#pragma once
#ifndef   _VIEWBLOCK_H_
#define _VIEWBLLOCK_H_

#include <utility>
#include<iostream>
#include<graphics.h>
#include"common.h"
#include"View.h"
using namespace std;

class viewblock {
private:
	string p_addr;
	int p_x, p_y;
	int w, h;
	bool deleted;
	bool choosed;
public:
	viewblock(string ad = "", int x = 0, int y = 0,int w=0,int h=0);
	string get_addr();
	pair<int, int> get_pos();
	bool inbox(MOUSEMSG m);
	void set_choosed();
	void set_unchoosed();
	void print_out();
	~viewblock();
};

class button :public viewblock {
private:
	button_type type;
public:
	button(string ad = "", int x = 0, int y = 0,button_type tp= BEGIN);
	~button();
	View act();
};
#endif // !  