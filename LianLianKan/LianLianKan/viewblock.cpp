#include "viewblock.h"

viewblock::viewblock(string ad, int x, int y,int w,int h) :p_addr(ad), p_x(x), p_y(y),w(w),h(h){
	deleted = false;
	choosed = false;
}

string viewblock::get_addr(){
	return p_addr;
}

pair<int, int> viewblock::get_pos(){
	return make_pair(p_x,p_y);
}

bool viewblock::inbox(MOUSEMSG m){
	int x1 = this->p_x, y1 = this->p_y;
	int x2 = x1 + view_block_W;
	int y2 = y1 + view_block_H;
	if (m.x > x1 && m.x<x2 && m.y>y1 && m.y < y2) {
		return true;
	}
	return false;
}

void viewblock::set_choosed()
{
	choosed = true;
	return;
}

void viewblock::set_unchoosed()
{
	choosed = false;
}

void viewblock::print_out()
{
	if (deleted) return;
	IMAGE img;
	loadimage(&img, (LPCTSTR)(p_addr.c_str()), w, h);
	putimage(p_x,p_y,&img);
	if (choosed) {
		setlinestyle(PS_SOLID, 4);
		setlinecolor(RED);
		rectangle(p_x, p_y, p_x + w, p_y + h);
	}
}

viewblock::~viewblock(){
}

button::button(string ad, int x, int y,button_type tp):viewblock(ad,x,y),type(tp){
}

button::~button(){
}

View button::act(){
	if (type == BEGIN) {
		//VM BEIGN  接口
	}
	else if (type == EXIT){
		exit(0);
	}
	else if (type == TIP) {
		//VM TIP 接口
	}
}

