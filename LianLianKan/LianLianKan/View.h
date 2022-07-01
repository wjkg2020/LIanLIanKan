#pragma once

#ifndef _VIEW_H_
#define _VIEW_H_

#include<iostream>

#include<vector>
#include"viewblock.h"
using namespace std;

class View
{
private:
	vector<viewblock>v_blocks;
	vector<button>buttons;
	vector<pair<int, int>>lines;
public:
	View(vector<viewblock>tmp,vector<button>tmp2,vector<pair<int,int>>tmp3);
	~View();
	void paint();
	void createWindow();
};

#endif 
