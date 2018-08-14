

#include <stdio.h>
#include<time.h> 

#include <conio.h>
#include <windows.h>
#include "win.h" 
#include "play.h"

int chessmanX, chessmanY;


/*
 *��������,ͬʱ��Q�е��������ݳ�ʼ�� 
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
            printf("ʮ");
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

//���ҽ�ʤ���߷��ذ�
int runGame(int (*Q)[15], int *gameState, int *startPlayer)
{
    int winner = 0;
    int count = 0;  //��¼�����еĻغ���  
    drawboard(Q);
    

    gotoxy(7, 7);

    if (*startPlayer == 1)
    {
        while (!winner)
        {
            humanPlay(Q, startPlayer, &chessmanX, &chessmanY); //human ����
            winner = win(Q,chessmanX, chessmanY);
            if (winner)   //�ж��Ƿ��Ѿ�����winner
            {       
				gotoxy(35, 9);
				printf("You win!");
                *gameState = 2; //������Ϸ
                break;
            }
            
            
            clock_t start, finish; 
            double Total_time; 
            
            gotoxy(35, 7); 
            printf( "��������˼��...                  \n", Total_time); 
            
			start = clock(); 
            computerPlay(Q, startPlayer, &chessmanX, &chessmanY); //��������
            finish = clock(); 
            Total_time = (double)(finish-start) / CLOCKS_PER_SEC; 
            
            gotoxy(35, 7); 
            printf( "����˼��ʱ�䣺%f seconds\n", Total_time); 
	        
            winner = win(Q,chessmanX, chessmanY);
            if (winner)   //�ж��Ƿ��Ѿ�����winner
            {      
		     	gotoxy(35, 9);   
			    printf("Computer win!");          
                *gameState = 2; //������Ϸ
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
        Q[7][7] = 1; //��������һ��
        gotoxy(7*2, 7);
        printf("��");
        
        while (!winner)
        {
            humanPlay(Q, startPlayer, &chessmanX, &chessmanY); //human ����
            winner = win(Q,chessmanX, chessmanY);
            if (winner)//�ж��Ƿ��Ѿ�����winner
            {          
		    	gotoxy(35, 9);
				printf("You win!");         
                *gameState = 2; //������Ϸ
                break;
            }

            clock_t start, finish; 
            double Total_time; 
            gotoxy(35, 7); 
            printf( "��������˼��...                 \n", Total_time); 
            
			start = clock(); 
            computerPlay(Q, startPlayer, &chessmanX, &chessmanY); //��������
            finish = clock(); 
            Total_time = (double)(finish-start) / CLOCKS_PER_SEC; 
            
            gotoxy(35, 7); 
            printf( "����˼��ʱ�䣺%f seconds\n", Total_time); 
       
	   
	    
            winner = win(Q,chessmanX, chessmanY);
            if (winner)  //�ж��Ƿ��Ѿ�����winner
            {                   
                gotoxy(35, 9);   
			    printf("Computer win!");  
                *gameState = 2; //������Ϸ
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
	printf("--------------------------������С��Ϸ----------------------\n");
	printf("  ������Ϸ˵����\n");
	printf("��ֻ���˻�����\n");
	printf("��ʹ�÷���������ƹ����ƶ�\n");
	printf("�񰴿ո�����ڹ��������λ������\n");
	printf("��Esc�����˳���Ϸ\n");
	printf("\n");
	printf("������ѡ�����ַ�������Ϸ:\n"); 
	printf("1.�������  2.��������\n");
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
    //���������Լ�¼�������  0Ϊû���� 1Ϊ����  2Ϊ����
    int Q[15][15] = {0};
    int gameState = 0;   //��ǰ��Ϸ״̬  0Ϊ��Ϸ�˵�����  1 Ϊ��Ϸ��  2Ϊ��Ϸ��������
    int startPlayer = 0; //���ַ�  1 Ϊ������м����ִ��   2 Ϊ�������м�����ִ��

	system("COLOR 2f"); /*COLORΪ�仯����̨��ɫ 2Ϊ������ɫ fΪǰ����ɫ*/
	system ( "mode con cols=75 lines=32" ); //���ô��ڴ�С
    
    /*
    //������һ�ε���Ϸ���� 
    int x;
    printf("�Ƿ������һ�ε���Ϸ��\n  1.��  2.��\n");
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
