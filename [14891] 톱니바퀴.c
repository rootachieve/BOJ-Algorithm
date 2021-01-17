//[14891] 톱니바퀴
//BOJ : https://www.acmicpc.net/problem/14891
#include<stdio.h>

char now[5][9];
int visit[5];
int N;
int ca(int num, int loca) {

	char re[9];
	if (loca == -1) {
		for (int i = 8; i >= 2; i--) {
			re[i - 1] = now[num][i];
		}
		re[8] = now[num][1];
	}
	else {
		for (int i = 1; i <= 7; i++) {
			re[i + 1] = now[num][i];
		}
		re[1] = now[num][8];
	}



	if (num == 2 || num == 3) {
		if (now[num][3] != now[num + 1][7] && visit[num + 1] == 0) {
			visit[num + 1] = 1;
			ca(num + 1, loca * (-1));
		}
		if (now[num][7] != now[num - 1][3] && visit[num - 1] == 0) {
			visit[num - 1] = 1;
			ca(num - 1, loca * (-1));
		}
	}
	else if (num == 4) {
		if (now[num][7] != now[num - 1][3] && visit[num - 1] == 0) {
			visit[num - 1] = 1;
			ca(num - 1, loca * (-1));
		}
	}
	else {
		if (now[num][3] != now[num + 1][7] && visit[num + 1] == 0) {
			visit[num + 1] = 1;
			ca(num + 1, loca * (-1));
		}
	}

	for (int i = 1; i <= 8; i++) {
		now[num][i] = re[i];
	}
}
int main() {
	char d;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			scanf("%c", &now[i][j]);

			
		}
		scanf("%c", &d);
	}
	
	scanf("%d", &N);
	int a, b;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &a, &b);
		visit[a] = 1;
		ca(a, b);
		for (int j = 1; j <= 4; j++) {
			visit[j] = 0;
		}
	}

	printf("%d", (now[1][1]-48)*1 + (now[2][1]-48)*2 + (now[3][1]-48)*4 + (now[4][1]-48)*8);
}