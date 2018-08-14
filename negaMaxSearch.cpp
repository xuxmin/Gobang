

#include "evaluate.h"
#include"generator.h"

/*
 *负极大值搜索算法
 *将评估函数改了一下，是的每一层都只要搜索分数最大的那个，就是对当前方有利的位置
 *将分数都设置为负的，初始时最好的是-inf，这样才可以找到最大值，想若初始设置为INF，还怎么玩
 */

int negaMaxSearch(int (*Q)[15], int depth, int player,int alpha, int beta)
{
	//int best = -999999; //都是极大值点
	int value = 0; 

	if (depth <= 0) {
		return evaluate(Q, player);
	}
	else {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (generator(Q, i, j)) {
					Q[i][j] = player;
					value = -negaMaxSearch(Q, depth - 1, 3 - player, -beta, -alpha);
					Q[i][j] = 0;
					if (value > alpha) {
						alpha = value;
					}
					if (alpha > beta) {   //在任何一层都只进行beta剪枝
						break;
					}
				}
			}
		}
	}
	return alpha;
}