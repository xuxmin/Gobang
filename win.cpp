/*
 *功能：判断当前棋型下是否有一方已经获胜了
 *
 *传入参数：棋盘的数据信息
 *传出参数：获胜方 1为黑方  2为白方   0为当前没有人获胜
 */

#include<string.h>



int win(int(*Q)[15],int chessmanX, int chessmanY)
{
	int i, j;
	int winPlayer = 0; //胜利的玩家
	int upnumber = 0, downnumber = 0, leftnumber = 0, rightnumber = 0;		//记录当前落子的上下左右同色的棋子数量 
	int topleftnumber = 0, toprightnumber = 0, bottomleftnumber = 0, bottomrightnumber = 0;		//记录当前落子的上下左右同色的棋子数量 
	for (i=1; i<5; i++){
		if (Q[chessmanX][chessmanY-i] == Q[chessmanX][chessmanY])
			upnumber++;
		else break;
	}
	for (i=1; i<5; i++){
		if (Q[chessmanX][chessmanY+i] == Q[chessmanX][chessmanY])
			downnumber++;
		else break;
	}
	for (i=1; i<5; i++){
		if (Q[chessmanX-i][chessmanY] == Q[chessmanX][chessmanY])
			leftnumber++;
		else break;
	}
	for (i=1; i<5; i++){
		if (Q[chessmanX+i][chessmanY] == Q[chessmanX][chessmanY])
			rightnumber++;
		else break;
	}
	for (i=1; i<5; i++){
		if (Q[chessmanX-i][chessmanY-i] == Q[chessmanX][chessmanY])
			topleftnumber++;
		else break;
	}
	for (i=1; i<5; i++){
		if (Q[chessmanX+i][chessmanY+i] == Q[chessmanX][chessmanY])
			bottomrightnumber++;
		else break;
	}
	for (i=1; i<5; i++){
		if (Q[chessmanX+i][chessmanY-i] == Q[chessmanX][chessmanY])
			toprightnumber++;
		else break;
	}
	for (i=1; i<5; i++){
		if (Q[chessmanX-i][chessmanY+i] == Q[chessmanX][chessmanY])
			bottomleftnumber++;
		else break;
	}
	if (upnumber+downnumber==4||
		leftnumber+rightnumber==4||
		topleftnumber+bottomrightnumber==4||
		toprightnumber+bottomleftnumber==4)
			winPlayer=1;
	return winPlayer;
}
