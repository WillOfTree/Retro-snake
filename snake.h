#pragma once

#ifndef __SNAKE__
#define __SNAKE__
#include<iostream>
#include "wall.h"
#include "food.h"

class Snake
{
private:
	struct Point{
		int x;
		int y;
		Point* next;
	};
	
public:
	enum {
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT = 'd'
	};

	Wall& wall; //引用类型的 wall
	Food& food;
	Point* snake_body; //蛇的身体节点，这种定义方法在C语言中会报错
	Snake(Wall& wall, Food& food);
	void init();
	void draw();
	void drop();
	void add_point(int x,int y);
	void drop_lost();
	bool move(char);
};


#endif