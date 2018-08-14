#include "generator.h"
#include "evaluate.h"
#include "negaMaxSearch.h"
#include "play.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>

static Cursor C= {7,7};


void gotoxy(int x, int y) /*（屏幕）建立光标移动位置的坐标函数*/
{
    COORD c; // COORD表示一个结构体的字符在控制台屏幕上的坐标
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); // 定位光标位置的函数 将光标移动到指定位置 一个特定的标准设备取得句柄
}

void humanPlay(int (*Q)[15], int *startPlayer, int* chessmanX, int* chessmanY)
{
    int done = 0;                 //记录human是否已经落子
    char input;                   //存储键盘的输入
    int color;                    //看看human走的时候到底下黑1还是白2
    
   
    gotoxy(2*C.x, C.y);

    if (*startPlayer == HUMAN){
        color = 1;
    }
    else{
        color = 2;
    } 

    while (!done)
    {
        input=getch();                //等待键盘按下一个字符
        if (input == 27) //如果是ESC则退出程序
        {
            exit(0);
        }
        else if (input == 0x20) //如果是空格则开始落子
        {
            if (Q[C.x][C.y] == 0)
            {
                Q[C.x][C.y] = color;
                
                if (color == 1){
                    printf("●");
                }
                else
                {
                    printf("○");
                }
                done = 1;
                *chessmanX = C.x ;
                *chessmanY = C.y ;
            }
        }
        else if (input == -32) //如果按下的是方向键，会填充两次输入，第一次为0xE0表示按下的是控制键
        {
            input = getch(); //获得第二次输入信息
            switch (input)   //判断方向键方向并移动光标位置
            {
            case 0x4B: //左
                C.x--;
                break;
            case 0x48: //下
                C.y--;
                break;
            case 0x4D: //右
                C.x++;
                break;
            case 0x50: //上
                C.y++;
                break;
            }
            if (C.x < 0)
                C.x = MAXIMUS - 1; //如果光标位置越界则移动到对侧
            if (C.y < 0)
                C.y = MAXIMUS - 1;
            if (C.x > MAXIMUS - 1)
                C.x = 0;
            if (C.y > MAXIMUS - 1)
                C.y = 0;
            gotoxy(2*C.x, C.y);
        }
    }
}


void computerPlay(int (*Q)[15], int *startPlayer, int* chessmanX, int* chessmanY)
{
    int bestX = 0, bestY = 0;  //存储搜索到的最好的位置
	

	/*极大极小值搜索算法
	maxmin(Q, 3, &bestX, &bestY);
	 */
	//负极大值搜索算法

	if (*startPlayer == 1) {
		int best = -999999;
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (generator(Q, i, j)) {
					Q[i][j] = 2;
					int value = -negaMaxSearch(Q, 1, 1, -999999, 999999);
					Q[i][j] = 0;
					if (best < value) {
						best = value;
						//printf("%d", best);
						bestX = i;
						bestY = j;
					}
				}
			}
		}
	}
	else {
		int best = -999999;
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (generator(Q, i, j)) {
					Q[i][j] = 1;
					int value = -negaMaxSearch(Q, 1, 2, -999999, 999999);
					Q[i][j] = 0;
					if (best < value) {
						best = value;
						//printf("%d", best);
						bestX = i;
						bestY = j;
					}
				}
			}
		}
	}
	

	if (*startPlayer == 1) {
		Q[bestX][bestY] = 2;
		gotoxy(2*bestX, bestY);
		printf("○");
		*chessmanX = bestX;
        *chessmanY = bestY;
	}
	else if (*startPlayer == 2) {
		Q[bestX][bestY] = 1;
		gotoxy(2*bestX, bestY);
		printf("●");
		*chessmanX = bestX;
        *chessmanY = bestY;
	}
	else {
		printf("error in *startPlayer!\n");
	}
}

