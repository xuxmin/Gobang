
#include"MiniMax.h"
#include"evaluate.h"
#include"win.h"
#include<stdio.h>
#include"generator.h"

//#define DEBUG

#ifdef DEBUG
    struct {
	    int white;
	    int black;
    }score[15][15];
#endif // DEBUG





/*在max 函数中如果发现一个子节点的值大于 alpha，则不再计算后序节点，此为 Alpha 剪枝。
 *alpha 存的应该是当前MIN层 的 前面几个节点尝试后 产生的最小 评估分数
 *在 min 函数中如果发现一个子节点的值小于 beta，则不再计算后序节点，此为 Beta剪枝。
 *
 *但注意第一次的深入是必须的回溯的时候才会有剪枝
 */

int Max(int (*Q)[15], int deep, int alpha, int beta);

//寻找当前局面下，评估出来的最小的分数
int Min(int (*Q)[15], int deep, int alpha, int beta)    //有利于human的落子     
{
	int best = 400000;
	int v;


	//判断当前是否已经五子连珠 或者到达搜索深度
	if (deep <= 0 || win(Q)) {    
		return evaluate(Q,1);
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (generator(Q, i, j)) {

				Q[i][j] = 1;

				v = Max(Q, deep - 1, alpha, best < beta ? best : beta);
				Q[i][j] = 0;
				if (v < best) {
					best = v;   //这里会更新alpha 的值  表示前面的节点找到的最小alpha
				}

				/*
				if (v < alpha) {  //AB剪枝
					//ABcut++;
					break;//break其实并没有整个跳出，然后ab剪枝应该配合启发式搜索函数来做，要对节点进行排序更加快
				}
				*/
				
			}
		}
	}
	return best;
}

//寻找当前局面下，评估出来的最大的分数
int Max(int (*Q)[15], int deep, int alpha, int beta)
{
	int best = -400000;
	int v;


	if (deep <= 0 || win(Q)) {    
		return evaluate(Q,1);
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (generator(Q, i, j)) {

				Q[i][j] = 2;

				v = Min(Q, deep - 1, best > alpha ? best : alpha, beta);

				Q[i][j] = 0;
				if (v > best) {
					best = v;
				}
				/*
				if (v > beta) { //AB 剪枝
					//ABcut++;
					break;    //v如果大于前面节点找到的最小的alpha 就无需继续了  
				}
				*/
				
			}
		}
	}
	return best;
}

//极大极小值搜索算法，返回最佳落子位置

void maxmin(int (*Q)[15], int deep, int *bestX, int *bestY)
{
	int best = -400000;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (generator(Q, i, j)) {    //这个位置有搜索价值

				Q[i][j] = 2;//电脑尝试下一个棋子


				//由于下一步是玩家落子，寻找的是使评估分数越小的位置，而对于电脑的每一种落子方法，要找其返回的最大值
				int v = Min(Q, deep - 1, -400000, 400000);   

				//找出分数最大的落点位置
				if (v == best) {
					*bestX = i;
					*bestY = j;
				}

				if (v > best) {
					best = v;
					*bestX = i;
					*bestY = j;
				}
				Q[i][j] = 0;
			}
		}
	}
#ifdef DEBUG
	printf("best: %d\n", best);
#endif // DEBUG
}
