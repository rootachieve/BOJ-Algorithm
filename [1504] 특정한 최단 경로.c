#include <stdio.h>
#define MAX_ll 987654321

long long map[820][820];
int N;
int E;
int v1;
int v2;
int main() {

	scanf("%d%d", &N, &E);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				map[i][j] = MAX_ll;
			}
		}
	}

	for (int i = 1; i <= E; i++) {
		int a;
		int b;
		int c;
		scanf("%d%d%d", &a, &b, &c);
		map[a][b] = c;
		map[b][a] = c;
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
	scanf("%d%d", &v1, &v2);
	long long k = map[1][v1] + map[v1][v2] + map[v2][N];
	long long h = map[1][v2] + map[v2][v1] + map[v1][N];
	
	if (k<h) {
		if (k >= MAX_ll) {
			printf("-1");
		}
		else {
			printf("%lld", k);
		}
	}
	else {
		if (k >= MAX_ll) {
			printf("-1");
		}
		else {
			printf("%lld", h);
		}
	}
}
