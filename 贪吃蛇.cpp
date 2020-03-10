// 贪吃蛇.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main()
{
    srand((unsigned int)time(NULL));

    bool isDeath = false; //判断是否死亡的选项
    char preKey = NULL;//记录上一次按键

    Wall w;
    w.init_wall(); //初始化

    Food fd(w);
    fd.set_food();

    Snake sk(w, fd);
    sk.init();

    w.draw_wall(); //在控制之前，就画一个蛇

    while (!isDeath)
    {
        char c = _getch();
        
        if (preKey == NULL && c == 'a')
        {
            continue;
        }
        

        do {
            if (c == sk.LEFT || c == sk.DOWN || c == sk.UP || c == sk.RIGHT)
            {
                //解决按键冲突
                if ((c == sk.LEFT && preKey == sk.RIGHT) ||
                    (c == sk.RIGHT && preKey == sk.LEFT) ||
                    (c == sk.UP && preKey == sk.DOWN) ||
                    (c == sk.DOWN && preKey == sk.UP)
                    )
                {
                    c = preKey;
                }
                else {
                    preKey = c;
                }

                if (sk.move(c) == true)
                {
                    system("cls"); //清理屏幕
                    w.draw_wall(); //画墙
                    Sleep(300);
                }
                else {
                    isDeath = true;
                    break;
                }
            }
            else {
                c = preKey;
            }
            
        } while (!_kbhit()); //持续更新输入的值
       
    }
    
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
