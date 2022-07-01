#include "View.h"
#include<algorithm>

View::View(vector<viewblock> tmp, vector<button> tmp2,vector<pair<int,int>>tmp3):v_blocks(tmp),buttons(tmp2),lines(tmp3){
}

View::~View(){
}

void View::paint(){
	for (auto it = v_blocks.begin(); it != v_blocks.end(); it++){
		it->print_out();
	}
	for (auto it = buttons.begin(); it != buttons.end(); it++) {
		it->print_out();
	}
	auto it = lines.begin();
	int now_x = it->first, now_y = it->second;
	it++;
	for (; it != lines.end(); it++) {
		int to_x = it->first, to_y = it->second;
		setlinestyle(PS_SOLID, 4);
		setlinecolor(YELLOW);
		line(now_x,now_y,to_x,to_y);
		now_x = to_x; now_y = to_y;
	}
}


void View::createWindow(){
	initgraph(Window_W, Window_H, EW_SHOWCONSOLE | EW_NOMINIMIZE);
	paint();
	return;
}


