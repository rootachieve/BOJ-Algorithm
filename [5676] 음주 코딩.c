#include<stdio.h>
int tree[400000];
int arr[100002];
int ansarr[100002];
int N;
int M;
int K;

int maketree(int L, int R, int node) {
	if (L == R) {

			tree[node] = arr[L];
			return tree[node];
		
	}
	else {
		int a, b;
		a = maketree(L, (L + R) / 2, node * 2);
		b = maketree((L + R) / 2 + 1, R, node * 2 + 1);
		tree[node] = (a * b);
		return tree[node];
	}
}

int changetree(int L, int R, int target, int num, int node) {
	if (L > target || R < target) {
		return tree[node];
	}
	else if (L == target && R == target) {
		tree[node] = num;
		return tree[node];
	}
	else if (L <= target && (L + R) / 2 >= target) {
		int a;
		a = changetree(L, (L + R) / 2, target, num, node * 2);
		tree[node] = (a * tree[node * 2 + 1]);
		return tree[node];
	}
	else if ((L + R) / 2 + 1 <= target && R >= target) {
		int a;
		a = changetree((L + R) / 2 + 1, R, target, num, node * 2 + 1);
		tree[node] = (a * tree[node * 2]);
		return tree[node];
	}
}
int hap(int L, int R, int left, int right, int node) {
	if (L > right || R < left) {
		return 1;
	}
	if (left <= L && right >= R) {
		return tree[node];
	}
	else {
		return (hap(L, (L + R) / 2, left, right, node * 2) * hap((L + R) / 2 + 1, R, left, right, node * 2 + 1));
	}
}
int main() {
	while(scanf("%d%d", &N, &M)!=EOF) {
		K = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] > 0) {
				arr[i] = 1;
			}
			else if (arr[i] < 0) {
				arr[i] = -1;
			}
			else {
				arr[i] = 0;
			}
		}
		maketree(1, N, 1);
		char a[2];
		int b, c;
		int ans;
		for (int i = 1; i <= M; i++) {
			scanf("%s%d%d", &a, &b, &c);
			if (a[0] == 'C') {
				if (c > 0) {
					changetree(1, N, b, 1, 1);
				}
				else if (c < 0) {
					changetree(1, N, b, -1, 1);
				}
				else {
					changetree(1, N, b, 0, 1);
				}
				
			}
			else {
				ans = hap(1, N, b, c, 1);
				ansarr[K] = ans;
				K++;
			}

		}
		for (int i = 0; i < K; i++) {
			if (ansarr[i] > 0) {
				printf("+");
			}
			else if (ansarr[i] < 0) {
				printf("-");
			}
			else {
				printf("0");
			}
		}
		printf("\n");
	}
}