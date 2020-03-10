#include "food.h"

Food::Food(Wall& tempwall) :wall(tempwall)
{

}

void Food::set_food()
{
	int x;
	int y;
	while (true)
	{
		x = (rand() % (this->wall.ROW - 2)) + 1;
		y = (rand() % (this->wall.COL - 2)) + 1;

		if (this->wall.get_wall(x, y) == ' ')
		{
			this->wall.set_wall(x, y, '#');
			break;
		}
	}
}