

void humanPlay(int (*Q)[15], int *startPlayer, int*, int*);
void computerPlay(int (*Q)[15], int *startPlayer, int*, int*);
void gotoxy(int x, int y); /*（屏幕）建立光标移动位置的坐标函数*/

typedef struct coordinate
{
    int x;
    int y;
} Cursor;   //记录当前光标所在的位置

#define HUMAN 1
#define COMPUTER 2
#define MAXIMUS 15
