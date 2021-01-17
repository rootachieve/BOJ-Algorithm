//[14889] 스타트와 링크
//BOJ : https://www.acmicpc.net/problem/14889
#include <stdio.h>
int visit[22];
int N;
int map[22][22];
int min = 2000000000;
int back(int now, int i) {
	if (i == 0) {
		int start = 0;
		int link = 0;
		for (int j = 1; j <= N; j++) {
			if (visit[j] == 1) {
				for (int k = 1; k <= N; k++) {
					if (visit[k] == 1) {
						start += map[j][k];
					}
				}
			}
			else {
				for (int k = 1; k <= N; k++) {
					if (visit[k] == 0) {
						link += map[j][k];
					}
				}
			}
		}
		int diff = start - link;
		if (diff < 0) diff *= -1;
		if (diff < min) {
			min = diff;
		}
	}
	else {
		for (int j = now+1; j + i - 1 <= N; j++) {
			visit[j] = 1;
			back(j, i - 1);
			visit[j] = 0;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	back(0, N/2);
	printf("%d", min);
}