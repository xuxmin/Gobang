



//为了获得（x，y）附近指定方向和范围的任意一个坐标
int getLine(int(*Q)[15], int x, int y, int direction, int distance)  //8个方向
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
		return -1;   //如果越过了边界，那么返回-1
	}
	else {
		return Q[x][y];  //没有越界，返回位置上的值。
	}
}



//判断坐标（x，y）处是否值得落子，我们认为在有棋子地方的两个距离范围内是值得落子的
int generator(int(*Q)[15], int x, int y)
{
	if (Q[x][y] != 0) {   //当前位置有棋子就返回0,有棋子在哪里就不能落子   
		return 0;
	}
	else {
		for (int k = 1; k <= 8; k++) {   //表示8个方向
			if (getLine(Q, x, y, k, 1) == 1 || getLine(Q, x, y, k, 1) == 2) {
				return 1;
			}
			if (getLine(Q, x, y, k, 2) == 1 || getLine(Q, x, y, k, 2) == 2) {
				return 1;
			}
		}
	}
	return 0;//0是说不必落子，遍历一个位置的distance2以内有棋子的话，就返回1表示需要落子尝试
}