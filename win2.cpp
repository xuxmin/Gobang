/*
 *功能：判断当前棋型下是否有一方已经获胜了
 *
 *传入参数：棋盘的数据信息
 *传出参数：获胜方 1为黑方  2为白方   0为当前没有人获胜
 */

#include<string.h>


//判断当前字符串是否匹配到五子连珠
int check(char *s)
{
	char *p = s;
	int winPlayer = 0;  //记录获胜方

	if (strstr(p, "22222") != NULL) {
		winPlayer = 2;
	}
	if (strstr(p, "11111") != NULL) {
		winPlayer = 1;
	}
	return winPlayer;
}




int win(int(*Q)[15])
{
	int i, j;
	int winPlayer = 0; //胜利的玩家
	
	//判断每一行是否有五子连珠
	for (i = 0; i < 15; i++) {
		char s[20];   //将棋盘每一行的信息转化成一个字符串
		for (j = 0; j < 15; j++) {
			s[j] = Q[i][j] + '0';
		}
		s[j] = '\0';
		if (winPlayer = check(s))  return winPlayer;
	}

	//判断每一列是否有五子连珠
	for (j = 0; j < 15; j++) {
		char s[20];   //将棋盘每一行的信息转化成一个字符串
		for (i = 0; i < 15; i++) {
			s[i] = Q[i][j] + '0';
		}
		s[i] = '\0';

		if (winPlayer = check(s))  return winPlayer;
	}

	//方向\是否有五子连珠
	for (i = 0; i < 11; i++) {
		char s[20];
		for (j = 0; j < 15 - i; j++) {
			s[j] = Q[j][i + j] + '0';
		}
		s[j] = '\0';

		if (winPlayer = check(s))  return winPlayer;
	}

	for (j = 1; j < 11; j++) {     //j从1开始防止主对角线被重复计算
		char s[20];
		for (i = 0; i < 15 - j; i++) {
			s[i] = Q[i + j][i] + '0';
		}
		s[i] = '\0';

		if (winPlayer = check(s))  return winPlayer;
	}

	//方向/是否有五子连珠
	for (i = 4; i < 15; i++) {
		char s[20];
		for (j = 0; j < i + 1; j++) {
			s[j] = Q[i - j][j] + '0';
		}
		s[j] = '\0';

		if (winPlayer = check(s))  return winPlayer;
	}

	for (j = 1; j < 11; j++) {     //j从1开始防止主对角线被重复计算
		char s[20];
		int p = 0;
		for (i = 14; i >= j; i--) {
			s[p++] = Q[i][j + 14 - i] + '0';
		}
		s[p] = '\0';

		if (winPlayer = check(s))  return winPlayer;
	}


	return winPlayer;
}