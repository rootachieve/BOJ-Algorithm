#define MAX 202
#include<stdio.h>
#include<stdlib.h>
int A[MAX];
int B[MAX];
int map[MAX][MAX];
int visi[MAX];
int ans;
int N, M;
int dfs(int num) {
	visi[num] = 1;
	for (int i = 1; i <= M; i++) {
		if (map[num][i] == 1) {
			if (B[i] == 0 || (visi[B[i]] == 0 && dfs(B[i]))) {
				A[num] = i;
				B[i] = num;
				return 1;
			}
		}
	}
	return 0;
}
int main() {

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int a;
			scanf("%d", &a);
			map[i][a] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (A[i] == 0) {
			for (int j = 1; j <= MAX; j++) {
				visi[j] = 0;
			}
			int v=dfs(i);
			if (v == 1) {
				ans++;
			}
		}
	}
	printf("%d", ans);
}