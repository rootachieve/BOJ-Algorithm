#include<stdio.h>
int tree[400000];
int arr[100002];
int N;
int M;

int maketree(int L, int R, int node) {
	if (L == R) {
		tree[node] = arr[L];
		return tree[node];
	}
	else {
		int a, b;
		a = maketree(L, (L + R) / 2, node * 2);
		b = maketree((L + R) / 2 + 1, R, node * 2 + 1);
		if (a < b) {
			tree[node] = a;
		}
		else {
			tree[node] = b;
		}
		return tree[node];
	}
}
int hap(int L, int R, int left, int right, int node) {
	if (L > right || R < left) {
		return 1000000005;
	}
	if (left <= L && right >= R) {
		return tree[node];
	}
	else {
		int a = hap(L, (L + R) / 2, left, right, node * 2);
		int b = hap((L + R) / 2 + 1, R, left, right, node * 2 + 1);
		if (a < b) {
			return a;
		}
		else {
			return b;
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	maketree(1, N, 1);
	int a, b;
	int ans;

	for(int i=1;i<=M;i++){
		scanf("%d%d", &a, &b);
		if (a < b) {
			ans = hap(1, N, a, b, 1);
			printf("%d\n", ans);
		}
		else {
			ans = hap(1, N, b, a, 1);
			printf("%d\n", ans);
		}
	}
}