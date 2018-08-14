

#include <stdio.h>
#include<time.h> 

#include <conio.h>
#include <windows.h>
#include "win.h" 
#include "play.h"

int chessmanX, chessmanY;


/*
 *建立棋盘,同时对Q中的棋盘数据初始化 
 */
void drawboard(int (*Q)[15]) 
{
    system("cls");
    gotoxy(0, 0);

    int i, j;
    for (i = 0; i < MAXIMUS; i++)
    {
        for (j = 0; j < MAXIMUS; j++)
        {
        	Q[i][j] = 0; 
            printf("十");
        }
        printf("%2d\n", i+1);
    }
    printf(" A B C D E F G H I J K L M N O\n");
}


void endGame(int *gameState)
{   
	gotoxy(0,16);
	printf("\n"); 
	printf("Enter the number to continue:\n");
	printf("1.play again\n");
	printf("2.exit\n");
	int n;
	scanf("%d", &n);
	if (n == 1){
		*gameState = 0;
	}else if (n == 2){
		exit(0);
	}
}

//暂且将胜利者返回吧
int runGame(int (*Q)[15], int *gameState, int *startPlayer)
{
    int winner = 0;
    int count = 0;  //记录所进行的回合数  
    drawboard(Q);
    

    gotoxy(7, 7);

    if (*startPlayer == 1)
    {
        while (!winner)
        {
            humanPlay(Q, startPlayer, &chessmanX, &chessmanY); //human 落子
            winner = win(Q,chessmanX, chessmanY);
            if (winner)   //判断是否已经产生winner
            {       
				gotoxy(35, 9);
				printf("You win!");
                *gameState = 2; //结束游戏
                break;
            }
            
            
            clock_t start, finish; 
            double Total_time; 
            
            gotoxy(35, 7); 
            printf( "电脑正在思考...                  \n", Total_time); 
            
			start = clock(); 
            computerPlay(Q, startPlayer, &chessmanX, &chessmanY); //电脑落子
            finish = clock(); 
            Total_time = (double)(finish-start) / CLOCKS_PER_SEC; 
            
            gotoxy(35, 7); 
            printf( "电脑思考时间：%f seconds\n", Total_time); 
	        
            winner = win(Q,chessmanX, chessmanY);
            if (winner)   //判断是否已经产生winner
            {      
		     	gotoxy(35, 9);   
			    printf("Computer win!");          
                *gameState = 2; //结束游戏
                break;
            }
            
            count++;
            if (count == 15*15/2){
            	gotoxy(35, 9);   
			    printf("Drawing\n");    
            	*gameState = 2;
			}
            
        }
    }
    else if (*startPlayer == 2)
    {
        Q[7][7] = 1; //电脑先落一子
        gotoxy(7*2, 7);
        printf("●");
        
        while (!winner)
        {
            humanPlay(Q, startPlayer, &chessmanX, &chessmanY); //human 落子
            winner = win(Q,chessmanX, chessmanY);
            if (winner)//判断是否已经产生winner
            {          
		    	gotoxy(35, 9);
				printf("You win!");         
                *gameState = 2; //结束游戏
                break;
            }

            clock_t start, finish; 
            double Total_time; 
            gotoxy(35, 7); 
            printf( "电脑正在思考...                 \n", Total_time); 
            
			start = clock(); 
            computerPlay(Q, startPlayer, &chessmanX, &chessmanY); //电脑落子
            finish = clock(); 
            Total_time = (double)(finish-start) / CLOCKS_PER_SEC; 
            
            gotoxy(35, 7); 
            printf( "电脑思考时间：%f seconds\n", Total_time); 
       
	   
	    
            winner = win(Q,chessmanX, chessmanY);
            if (winner)  //判断是否已经产生winner
            {                   
                gotoxy(35, 9);   
			    printf("Computer win!");  
                *gameState = 2; //结束游戏
                break;
            }
        }
        
        count++;
        if (count == 15*15/2){
            gotoxy(35, 9);   
			printf("Drawing\n");    
            *gameState = 2;
		}
    }
    return winner;
}

void showMenu(int *gameState, int *startPlayer)
{
	printf("--------------------------五子棋小游戏----------------------\n");
	printf("  基本游戏说明：\n");
	printf("●只有人机对弈\n");
	printf("●使用方向键，控制光标的移动\n");
	printf("●按空格键，在光标所处的位置落子\n");
	printf("●按Esc键，退出游戏\n");
	printf("\n");
	printf("下面请选择先手方进入游戏:\n"); 
	printf("1.玩家先手  2.电脑先手\n");
    int x;

    scanf("%d", &x);

    if (x == 1)
    {
        *startPlayer = HUMAN;
        *gameState = 1;
    }
    else if (x == 2)
    {
        *startPlayer = COMPUTER;
        *gameState = 1;
    }
    
}

int main()
{
    //定义数组以记录落子情况  0为没有子 1为黑子  2为白子
    int Q[15][15] = {0};
    int gameState = 0;   //当前游戏状态  0为游戏菜单界面  1 为游戏中  2为游戏结束界面
    int startPlayer = 0; //先手方  1 为玩家先行即玩家执黑   2 为电脑先行即电脑执黑

	system("COLOR 2f"); /*COLOR为变化控制台颜色 2为背景颜色 f为前景颜色*/
	system ( "mode con cols=75 lines=32" ); //设置窗口大小
    
    /*
    //读入上一次的游戏数据 
    int x;
    printf("是否继续上一次的游戏？\n  1.是  2.否\n");
	scanf("%d", &x); 
	if (x == 1){
		fscanf("%d %d", &startPlayer, &gameState);
		
		FILE *fp;
        fp = fopen("data.txt","w");
        for (int i = 0; i < 15; i++){
        	for (int j = 0; j < 15; j++){
        		fscanf("%d", &Q[i][j]);
			}
		}
	}
	
	fclose(fp);
    */
    
    while (1)
    {
        if (gameState == 0)
        {
            showMenu(&gameState, &startPlayer);
        }
        else if (gameState == 1)
        {
            runGame(Q, &gameState, &startPlayer);
        }
        else if (gameState == 2)
        {
            endGame(&gameState);
        }
    }

    return 0;
}
