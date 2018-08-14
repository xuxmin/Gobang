

#include "evaluate.h"
#include"generator.h"

/*
 *������ֵ�����㷨
 *��������������һ�£��ǵ�ÿһ�㶼ֻҪ�������������Ǹ������ǶԵ�ǰ��������λ��
 *������������Ϊ���ģ���ʼʱ��õ���-inf�������ſ����ҵ����ֵ��������ʼ����ΪINF������ô��
 */

int negaMaxSearch(int (*Q)[15], int depth, int player,int alpha, int beta)
{
	//int best = -999999; //���Ǽ���ֵ��
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
					if (alpha > beta) {   //���κ�һ�㶼ֻ����beta��֦
						break;
					}
				}
			}
		}
	}
	return alpha;
}