
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





/*��max �������������һ���ӽڵ��ֵ���� alpha�����ټ������ڵ㣬��Ϊ Alpha ��֦��
 *alpha ���Ӧ���ǵ�ǰMIN�� �� ǰ�漸���ڵ㳢�Ժ� ��������С ��������
 *�� min �������������һ���ӽڵ��ֵС�� beta�����ټ������ڵ㣬��Ϊ Beta��֦��
 *
 *��ע���һ�ε������Ǳ���Ļ��ݵ�ʱ��Ż��м�֦
 */

int Max(int (*Q)[15], int deep, int alpha, int beta);

//Ѱ�ҵ�ǰ�����£�������������С�ķ���
int Min(int (*Q)[15], int deep, int alpha, int beta)    //������human������     
{
	int best = 400000;
	int v;


	//�жϵ�ǰ�Ƿ��Ѿ��������� ���ߵ����������
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
					best = v;   //��������alpha ��ֵ  ��ʾǰ��Ľڵ��ҵ�����Сalpha
				}

				/*
				if (v < alpha) {  //AB��֦
					//ABcut++;
					break;//break��ʵ��û������������Ȼ��ab��֦Ӧ���������ʽ��������������Ҫ�Խڵ����������ӿ�
				}
				*/
				
			}
		}
	}
	return best;
}

//Ѱ�ҵ�ǰ�����£��������������ķ���
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
				if (v > beta) { //AB ��֦
					//ABcut++;
					break;    //v�������ǰ��ڵ��ҵ�����С��alpha �����������  
				}
				*/
				
			}
		}
	}
	return best;
}

//����Сֵ�����㷨�������������λ��

void maxmin(int (*Q)[15], int deep, int *bestX, int *bestY)
{
	int best = -400000;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (generator(Q, i, j)) {    //���λ����������ֵ

				Q[i][j] = 2;//���Գ�����һ������


				//������һ����������ӣ�Ѱ�ҵ���ʹ��������ԽС��λ�ã������ڵ��Ե�ÿһ�����ӷ�����Ҫ���䷵�ص����ֵ
				int v = Min(Q, deep - 1, -400000, 400000);   

				//�ҳ������������λ��
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
