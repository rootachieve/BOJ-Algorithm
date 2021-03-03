#include <stdio.h>
#define MAX_INT 100000000;
int map[1020][1020];
int N;
int X;//스타트
int M;//도로갯수
int max;
int dis[1020];
int main() {
	scanf("%d%d%d", &N, &M,&X);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				map[i][j] = MAX_INT;
			}
		}
	}
	int s;
	int e;
	int w;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &s, &e, &w);
		map[s][e] = w;
	}

	for (int m = 1; m <= N; m++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (map[s][e] > map[s][m] + map[m][e]) {
					map[s][e] = map[s][m] + map[m][e];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		dis[i] = map[X][i] + map[i][X];
		if (max < dis[i]) {
			max = dis[i];
		}
	}

	printf("%d", max);
}

