/*
 *���ܣ��жϵ�ǰ�������Ƿ���һ���Ѿ���ʤ��
 *
 *������������̵�������Ϣ
 *������������ʤ�� 1Ϊ�ڷ�  2Ϊ�׷�   0Ϊ��ǰû���˻�ʤ
 */

#include<string.h>



int win(int(*Q)[15],int chessmanX, int chessmanY)
{
	int i, j;
	int winPlayer = 0; //ʤ�������
	int upnumber = 0, downnumber = 0, leftnumber = 0, rightnumber = 0;		//��¼��ǰ���ӵ���������ͬɫ���������� 
	int topleftnumber = 0, toprightnumber = 0, bottomleftnumber = 0, bottomrightnumber = 0;		//��¼��ǰ���ӵ���������ͬɫ���������� 
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
