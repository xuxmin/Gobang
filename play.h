

void humanPlay(int (*Q)[15], int *startPlayer, int*, int*);
void computerPlay(int (*Q)[15], int *startPlayer, int*, int*);
void gotoxy(int x, int y); /*����Ļ����������ƶ�λ�õ����꺯��*/

typedef struct coordinate
{
    int x;
    int y;
} Cursor;   //��¼��ǰ������ڵ�λ��

#define HUMAN 1
#define COMPUTER 2
#define MAXIMUS 15
