/*
 *���ܣ��жϵ�ǰ�������Ƿ���һ���Ѿ���ʤ��
 *
 *������������̵�������Ϣ
 *������������ʤ�� 1Ϊ�ڷ�  2Ϊ�׷�   0Ϊ��ǰû���˻�ʤ
 */

#include<string.h>


//�жϵ�ǰ�ַ����Ƿ�ƥ�䵽��������
int check(char *s)
{
	char *p = s;
	int winPlayer = 0;  //��¼��ʤ��

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
	int winPlayer = 0; //ʤ�������
	
	//�ж�ÿһ���Ƿ�����������
	for (i = 0; i < 15; i++) {
		char s[20];   //������ÿһ�е���Ϣת����һ���ַ���
		for (j = 0; j < 15; j++) {
			s[j] = Q[i][j] + '0';
		}
		s[j] = '\0';
		if (winPlayer = check(s))  return winPlayer;
	}

	//�ж�ÿһ���Ƿ�����������
	for (j = 0; j < 15; j++) {
		char s[20];   //������ÿһ�е���Ϣת����һ���ַ���
		for (i = 0; i < 15; i++) {
			s[i] = Q[i][j] + '0';
		}
		s[i] = '\0';

		if (winPlayer = check(s))  return winPlayer;
	}

	//����\�Ƿ�����������
	for (i = 0; i < 11; i++) {
		char s[20];
		for (j = 0; j < 15 - i; j++) {
			s[j] = Q[j][i + j] + '0';
		}
		s[j] = '\0';

		if (winPlayer = check(s))  return winPlayer;
	}

	for (j = 1; j < 11; j++) {     //j��1��ʼ��ֹ���Խ��߱��ظ�����
		char s[20];
		for (i = 0; i < 15 - j; i++) {
			s[i] = Q[i + j][i] + '0';
		}
		s[i] = '\0';

		if (winPlayer = check(s))  return winPlayer;
	}

	//����/�Ƿ�����������
	for (i = 4; i < 15; i++) {
		char s[20];
		for (j = 0; j < i + 1; j++) {
			s[j] = Q[i - j][j] + '0';
		}
		s[j] = '\0';

		if (winPlayer = check(s))  return winPlayer;
	}

	for (j = 1; j < 11; j++) {     //j��1��ʼ��ֹ���Խ��߱��ظ�����
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