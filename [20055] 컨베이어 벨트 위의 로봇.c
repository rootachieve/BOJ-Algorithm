//[20055] 컨베이어 벨트 위의 로봇
//BOJ : https://www.acmicpc.net/problem/20055
#include<stdio.h>

int up=1;
int down;
int con[220];
int lobo[110];
int N;
int K;
int level;
int count;

int uplobo() {
	if (con[up] > 0) {
		lobo[1] = 1;
		con[up]--;
		if (con[up] < 1) {
			count++;
		}
	}
}
int conmove() {
	up--;
	down--;
	if (up == 0) {
		up = 2*N;
	}
	if (down == 0) {
		down = 2 * N;
	}
}
int conlobomove() {
	
	for (int i = N; i > 1; i--) {
		if (lobo[i - 1] == 1 && lobo[i] == 0) {
			lobo[i] = lobo[i - 1];
			lobo[i-1]--;
		}
	}
	lobo[N] = 0;
}
int lobomove() {
	int k = down;
	for (int i = N; i > 1; i--) {
		if (lobo[i - 1] == 1 && lobo[i] == 0&&con[k]>0) {
			lobo[i] = lobo[i - 1];
			lobo[i - 1] = 0;
			con[k]--;
			if (con[k] == 0) {
				count++;
			}
		}
		k--;
		if (k < 1) {
			k = 2 * N;
		}
	}
	lobo[N] = 0;
}

int main() {
	scanf("%d%d", &N,&K);
	down = N;
	for (int i = 1; i <= 2 * N; i++) {
		scanf("%d", &con[i]);
		if (con[i] == 0) count++;
	}
	while (count < K) {
		level++;
		conmove();
		conlobomove();
		lobomove();
		uplobo();
	}
	printf("%d", level);
}