#include "snake.h"

Snake::Snake(Wall& tempwall, Food& tempfood):wall(tempwall), food(tempfood) //将wall对象放到wall类型中
{
	//this->wall = wall; //维护
	this->snake_body = NULL; //初始化身体节点为空
}

void Snake::draw()
{

}

void Snake::init()
{
	this->drop();
	this->add_point(5, 3);
	this->add_point(5, 4);
	this->add_point(5, 5);
}

void Snake::add_point(int x, int y)
{
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = this->snake_body;

	//将节点头部的@ 改为=
	if (this->snake_body != NULL)
	{
		//这里要设置以前节点本来是@的位置
		wall.set_wall(this->snake_body->x, this->snake_body->y, '=');
	}
	//更新头部
	this->snake_body = newPoint;
	wall.set_wall(newPoint->x, newPoint->y, '@');
}

//销毁
void Snake::drop()
{
	Point* pcur = this->snake_body; //将指针指向 蛇的头部
	
	while (this->snake_body != NULL)
	{
		pcur = this->snake_body->next;
		delete this->snake_body;
		this->snake_body = pcur;
	}
}

/*
蛇移动时，删除尾节点
*/
void Snake::drop_lost()
{
	Point* cur = this->snake_body;
	Point* pnext = this->snake_body->next;

	while (true)
	{
		if (pnext->next == NULL)
		{
			this->wall.set_wall(pnext->x, pnext->y, ' ');
			delete pnext;
			pnext = NULL;
			cur->next = NULL;
			break;
		}

		cur = cur->next;
		pnext = pnext->next;
	}
}

/*
移动蛇的头部
*/
bool Snake::move(char key)
{
	int x = this->snake_body->x;
	int y = this->snake_body->y;

	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	}

	//判断是否撞墙
	if (this->wall.get_wall(x, y) == '*' || this->wall.get_wall(x, y) == '=')
	{
		cout << "GAME OVER";
		return false;
	}

	//判断是否吃到食物
	if (this->wall.get_wall(x, y) == '#')
	{
		this->add_point(x, y);
		this->food.set_food();
	}
	else {
		this->add_point(x, y);
		this->drop_lost();
	}
	return true;
}