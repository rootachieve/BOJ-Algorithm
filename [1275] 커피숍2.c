#include<stdio.h>
long long tree[400000];
long long arr[100002];
int N;
int Q;
long long maketree(int L, int R, int node) {
	if (L == R) {
		tree[node] = arr[L];
		return tree[node];
	}
	else {
		long long a, b;
		a = maketree(L, (L + R) / 2, node * 2);
		b = maketree((L + R) / 2 + 1, R, node * 2 + 1);
		tree[node] = a + b;
		return tree[node];
	}
}

long long changetree(int L, int R, int target, int num, int node) {
	if (L > target || R < target) {
		return tree[node];
	}
	else if (L == target && R == target) {
		tree[node] = num;
		return tree[node];
	}
	else if (L <= target && (L + R) / 2 >= target) {
		long long a;
		a = changetree(L, (L + R) / 2, target, num, node * 2);
		tree[node] = a + tree[node * 2 + 1];
		return tree[node];
	}
	else if ((L + R) / 2+1 <= target&& R >= target) {
		long long a;
		a = changetree((L + R) / 2+1,R, target, num, node * 2+1);
		tree[node] = a + tree[node * 2];
		return tree[node];
	}
}

long long hap(int L, int R, int left, int right, int node) {
	if (L > right || R < left) {
		return 0;
	}
	if (left<=L && right>=R) {
		return tree[node];
	}
	else {
		return hap(L, (L + R) / 2, left, right, node * 2) + hap((L + R) / 2 + 1, R, left, right, node * 2 + 1);
	}
}
int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%lli", &arr[i]);
	}
	maketree(1, N, 1);
	printf("");
	int n, m, p, q;
	long long ans;
	for (int i = 1; i <= Q; i++) {
		scanf("%d%d%d%d",&n,&m,&q,&p);
		if (m > n) {
			ans = hap(1, N, n, m, 1);
		}
		else {
			ans = hap(1, N, m, n, 1);
		}
		printf("%lli\n", ans);
		changetree(1, N, q, p, 1);
	}
}