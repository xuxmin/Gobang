#include "generator.h"
#include "evaluate.h"
#include "negaMaxSearch.h"
#include "play.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>

static Cursor C= {7,7};


void gotoxy(int x, int y) /*����Ļ����������ƶ�λ�õ����꺯��*/
{
    COORD c; // COORD��ʾһ���ṹ����ַ��ڿ���̨��Ļ�ϵ�����
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); // ��λ���λ�õĺ��� ������ƶ���ָ��λ�� һ���ض��ı�׼�豸ȡ�þ��
}

void humanPlay(int (*Q)[15], int *startPlayer, int* chessmanX, int* chessmanY)
{
    int done = 0;                 //��¼human�Ƿ��Ѿ�����
    char input;                   //�洢���̵�����
    int color;                    //����human�ߵ�ʱ�򵽵��º�1���ǰ�2
    
   
    gotoxy(2*C.x, C.y);

    if (*startPlayer == HUMAN){
        color = 1;
    }
    else{
        color = 2;
    } 

    while (!done)
    {
        input=getch();                //�ȴ����̰���һ���ַ�
        if (input == 27) //�����ESC���˳�����
        {
            exit(0);
        }
        else if (input == 0x20) //����ǿո���ʼ����
        {
            if (Q[C.x][C.y] == 0)
            {
                Q[C.x][C.y] = color;
                
                if (color == 1){
                    printf("��");
                }
                else
                {
                    printf("��");
                }
                done = 1;
                *chessmanX = C.x ;
                *chessmanY = C.y ;
            }
        }
        else if (input == -32) //������µ��Ƿ������������������룬��һ��Ϊ0xE0��ʾ���µ��ǿ��Ƽ�
        {
            input = getch(); //��õڶ���������Ϣ
            switch (input)   //�жϷ���������ƶ����λ��
            {
            case 0x4B: //��
                C.x--;
                break;
            case 0x48: //��
                C.y--;
                break;
            case 0x4D: //��
                C.x++;
                break;
            case 0x50: //��
                C.y++;
                break;
            }
            if (C.x < 0)
                C.x = MAXIMUS - 1; //������λ��Խ�����ƶ����Բ�
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
    int bestX = 0, bestY = 0;  //�洢����������õ�λ��
	

	/*����Сֵ�����㷨
	maxmin(Q, 3, &bestX, &bestY);
	 */
	//������ֵ�����㷨

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
		printf("��");
		*chessmanX = bestX;
        *chessmanY = bestY;
	}
	else if (*startPlayer == 2) {
		Q[bestX][bestY] = 1;
		gotoxy(2*bestX, bestY);
		printf("��");
		*chessmanX = bestX;
        *chessmanY = bestY;
	}
	else {
		printf("error in *startPlayer!\n");
	}
}

