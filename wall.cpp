#include "wall.h"

/*
	初始化墙
*/
void Wall::init_wall()
{
	for (int i = 0; i < ROW; i++)// 行
	{
		for (int j = 0; j < COL; j++)//列
		{
			if (i == 0 || j == 0 || i == ROW-1 || j == COL-1)
			{
				this->wallarray[i][j] = '*';
			}
			else
			{
				this->wallarray[i][j] = ' ';
			}
		}
		
	}
}


/*
	画墙
*/
void Wall::draw_wall()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << this->wallarray[i][j];
		}
		//cout << i << endl;
		this->write_info(i);
		cout << endl;
	}
}

void Wall::set_wall(int x, int y, char a)
{
	this->wallarray[x][y] = a;
}

char Wall::get_wall(int x, int y)
{
	return this->wallarray[x][y];
}

void Wall::write_info(int y)
{
	if (y == 5)
	{
		cout << "  create by WillOfTree";
	}
	if (y == 6)
	{
		cout << "  *******";
	}
}