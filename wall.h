#pragma once

#ifndef __WALL_HEAD__
#define __WALL_HEAD__

#include<iostream>
using namespace std;
class Wall 
{
public:
	enum { //Ïàµ±ÓÚ#define ROW 20, #define COL 60
		ROW = 20,
		COL = 60
	};

	void init_wall();
	void draw_wall();
	void set_wall(int, int, char);
	char get_wall(int, int);
	void write_info(int);
private:
	char wallarray[ROW][COL];
};


#endif