



//Ϊ�˻�ã�x��y������ָ������ͷ�Χ������һ������
int getLine(int(*Q)[15], int x, int y, int direction, int distance)  //8������
{
	switch (direction)
	{
	case 1:y = y + distance; break;
	case 2:x = x - distance; y = y + distance; break;
	case 3:x = x - distance; break;
	case 4:x = x - distance; y = y - distance; break;
	case 5:y = y - distance; break;
	case 6:x = x + distance; y = y - distance; break;
	case 7:x = x + distance; break;
	case 8:x = x + distance; y = y + distance; break;
	}
	if (x > 14 || x < 0 || y>14 || y < 0) {
		return -1;   //���Խ���˱߽磬��ô����-1
	}
	else {
		return Q[x][y];  //û��Խ�磬����λ���ϵ�ֵ��
	}
}



//�ж����꣨x��y�����Ƿ�ֵ�����ӣ�������Ϊ�������ӵط����������뷶Χ����ֵ�����ӵ�
int generator(int(*Q)[15], int x, int y)
{
	if (Q[x][y] != 0) {   //��ǰλ�������Ӿͷ���0,������������Ͳ�������   
		return 0;
	}
	else {
		for (int k = 1; k <= 8; k++) {   //��ʾ8������
			if (getLine(Q, x, y, k, 1) == 1 || getLine(Q, x, y, k, 1) == 2) {
				return 1;
			}
			if (getLine(Q, x, y, k, 2) == 1 || getLine(Q, x, y, k, 2) == 2) {
				return 1;
			}
		}
	}
	return 0;//0��˵�������ӣ�����һ��λ�õ�distance2���������ӵĻ����ͷ���1��ʾ��Ҫ���ӳ���
}