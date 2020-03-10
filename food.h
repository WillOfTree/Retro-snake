#pragma once
#ifndef __FOOD__
#define __FOOD__
#include "wall.h"

class Food
{
private:
	Wall& wall;
public:
	Food(Wall& wall);
	void set_food();
};

#endif