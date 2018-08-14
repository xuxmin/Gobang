/*
 *针对整个棋盘白方形式的评估函数
 *--------------------------------
 *传入参数为整个棋盘的信息  0表示没有棋子  1表示黑方  2表示白方
 *返回值越大对白方越有利，越小对黑方越有利
 *---------------------------
 *棋型与对应的分数如下：
 *成五，100000
 *活四, 10000
 *活三 1000
 *活二 100
 *活一 10
 *死四, 1000
 *死三 100
 *死二 10
 */

#include "evaluate.h"
#include <string.h>
#include <stdio.h>

//#define DEBUG
/*
 *用strstr
 *传入参数为获得的字符串，以及指向分数的指针
 */
void match_white(char * s, int *score)
{
	char *p = s;
	int count = 0;
	int length = strlen(s);

	while ((p = strstr(p,"22222")) != NULL) {
		count++;
		p++;
	}
	*score += 100000 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("white: the number of continuos_five is %d\n", count);
	}
#endif

	count = 0;
	p = s;
	while ((p = strstr(p, "022220")) != NULL) {
		count++;
		p++;
	}
	*score += 10000 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("white: the number of live_four is %d\n", count);
	}
#endif

	count = 0;
	p = s;
	while ((p = strstr(p, "02220")) != NULL) {
		count++;
		p++;
	}
	*score += 1000 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("white: the number of live_three is %d\n", count);
	}
#endif
	
	count = 0;
	p = s;
	while ((p = strstr(p, "0220")) != NULL) {
		count++;
		p++;
	}
	*score += 100 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("white: the number of live_two is %d\n", count);
	}
#endif


	count = 0;
	p = s;
	while ((p = strstr(p, "020")) != NULL) {
		count++;
		p++;
	}
	*score += 10 * count;


    count = 0;
	p = s;

	if (s[0] == '2' && s[1] == '2' && s[2] == '2' && s[3] == '2' && s[4] == '0') {
		count++;
		p = s + 5;
	}
	if (s[length-5] == '0' && s[length-4] == '2' && s[length-3 ] == '2' && s[length - 2] == '2' && s[length - 1] == '2') {
		count++;
	}

	while ((p = strstr(p, "122220")) != NULL) {
		count++;
		p++;
	}
	p = s;
	while ((p = strstr(p, "022221")) != NULL) {
		count++;
		p++;
	}
	
	*score += 1000 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("white: the number of blocked_four is %d\n", count);
	}
#endif



	count = 0;
	p = s;
	if (s[0] == '2' && s[1] == '2' && s[2] == '2' && s[3] == '0') {
		count++;
	}
	if (s[length-4] == '0' && s[length-3] == '2' && s[length-2] == '2' && s[length-1] == '2') {
		count++;
	}

	while ((p = strstr(p, "12220")) != NULL) {
		count++;
		p++;
	}
	p = s;
	while ((p = strstr(p, "02221")) != NULL) {
		count++;
		p++;
	}
	*score += 100 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("white: the number of blocked_three is %d\n", count);
	}
#endif

	count = 0;
	p = s;
	if (s[0] == '2' && s[1] == '2' && s[2] == '0') {
		count++;
	}
	if (s[length - 3] == '0' && s[length - 2] == '2' && s[length - 1] == '2') {
		count++;
	}
	while ((p = strstr(p, "1220")) != NULL) {
		count++;
		p++;
	}
	p = s;
	while ((p = strstr(p, "0221")) != NULL) {
		count++;
		p++;
	}
	*score += 10 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("white: the number of blocked_two is %d\n", count);
	}
#endif

}

void match_black(char * s, int *score)
{
	char *p = s;
	int count = 0;
	int length = strlen(s);

	while ((p = strstr(p, "11111")) != NULL) {
		count++;
		p++;
	}
	*score += 100000 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("black: the number of continuos_five is %d\n", count);
	}
#endif

	count = 0;
	p = s;
	while ((p = strstr(p, "011110")) != NULL) {
		count++;
		p++;
	}
	*score += 10000 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("black: the number of live_four is %d\n", count);
	}
#endif

	count = 0;
	p = s;
	while ((p = strstr(p, "01110")) != NULL) {
		count++;
		p++;
	}
	*score += 1000 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("black: the number of live_three is %d\n", count);
	}
#endif

	count = 0;
	p = s;
	while ((p = strstr(p, "0110")) != NULL) {
		count++;
		p++;
	}
	*score += 100 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("black: the number of live_two is %d\n", count);
	}
#endif


	count = 0;
	p = s;
	while ((p = strstr(p, "010")) != NULL) {
		count++;
		p++;
	}
	*score += 10 * count;



	count = 0;
	p = s;

	if (s[0] == '1' && s[1] == '1' && s[2] == '1' && s[3] == '1' && s[4] == '0') {
		count++;
		p = s + 5;
	}
	if (s[length - 5] == '0' && s[length - 4] == '1' && s[length - 3] == '1' && s[length - 2] == '1' && s[length - 1] == '1') {
		count++;
	}

	while ((p = strstr(p, "211110")) != NULL) {
		count++;
		p++;
	}
	p = s;
	while ((p = strstr(p, "011112")) != NULL) {
		count++;
		p++;
	}

	*score += 1000 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("black: the number of blocked_four is %d\n", count);
	}
#endif



	count = 0;
	p = s;
	if (s[0] == '1' && s[1] == '1' && s[2] == '1' && s[3] == '0') {
		count++;
	}
	if (s[length - 4] == '0' && s[length - 3] == '1' && s[length - 2] == '1' && s[length - 1] == '1') {
		count++;
	}

	while ((p = strstr(p, "21110")) != NULL) {
		count++;
		p++;
	}
	p = s;
	while ((p = strstr(p, "01112")) != NULL) {
		count++;
		p++;
	}
	*score += 100 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("black: the number of blocked_three is %d\n", count);
	}
#endif

	count = 0;
	p = s;
	if (s[0] == '1' && s[1] == '1' && s[2] == '0') {
		count++;
	}
	if (s[length - 3] == '0' && s[length - 2] == '1' && s[length - 1] == '1') {
		count++;
	}
	while ((p = strstr(p, "2110")) != NULL) {
		count++;
		p++;
	}
	p = s;
	while ((p = strstr(p, "0112")) != NULL) {
		count++;
		p++;
	}
	*score += 10 * count;

#ifdef DEBUG
	if (count != 0) {
		printf("black: the number of blocked_two is %d\n", count);
	}
#endif

}


int evaluate(int(*Q)[15], int player)
{
	int i, j;
	int white_score = 0;     //白方的棋势评估分数
	int black_score = 0;     //黑方的棋势评估分数

	
	//每一行棋局估值
	for (i = 0; i < 15; i++) {
		char s[20];   //将棋盘每一行的信息转化成一个字符串
		for (j = 0; j < 15; j++) {
			s[j] = Q[i][j] + '0';
		}
		s[j] = '\0';

		match_white(s, &white_score);
		match_black(s, &black_score);
	}

	//每一列棋局估值
	for (j = 0; j < 15; j++) {
		char s[20];   //将棋盘每一行的信息转化成一个字符串
		for (i = 0; i < 15; i++) {
			s[i] = Q[i][j] + '0';
		}
		s[i] = '\0';

		match_white(s, &white_score);
		match_black(s, &black_score);
	}

	//方向\棋型估值
	for (i = 0; i < 11; i++) {
		char s[20];
		for (j = 0; j < 15-i; j++) {
			s[j] = Q[j][i+j] + '0';
		}
		s[j] = '\0';

		match_white(s, &white_score);
		match_black(s, &black_score);
	}

	for (j = 1; j < 11; j++) {     //j从1开始防止主对角线被重复计算
		char s[20];
		for (i = 0; i < 15 - j; i++) {   
			s[i] = Q[i+j][i] + '0';
		}
		s[i] = '\0';

		match_white(s, &white_score);
		match_black(s, &black_score);
	}

	//方向/棋型估值
	for (i = 4; i < 15; i++) {
		char s[20];
		for (j = 0; j < i + 1; j++) {
			s[j] = Q[i-j][j] + '0';
		}
		s[j] = '\0';

		match_white(s, &white_score);
		match_black(s, &black_score);
	}

	for (j = 1; j < 11; j++) {     //j从1开始防止主对角线被重复计算
		char s[20];
		int p = 0;
		for (i = 14 ; i >= j; i--) {
			s[p++] = Q[i][j+14-i] + '0';
		}
		s[p] = '\0';

		match_white(s, &white_score);
		match_black(s, &black_score);
	}
	if (player == 2) {
		return white_score - black_score;
	}
	else if (player == 1) {
		return black_score - white_score;
	}
}



