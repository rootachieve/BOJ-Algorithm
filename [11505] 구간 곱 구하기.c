#include<stdio.h>
long long tree[4000000];
long long arr[1000002];
int N;
int M;
int K;
long long maketree(int L, int R, int node) {
	if (L == R) {
		tree[node] = arr[L];
		return tree[node];
	}
	else {
		long long a, b;
		a = maketree(L, (L + R) / 2, node * 2);
		b = maketree((L + R) / 2 + 1, R, node * 2 + 1);
		tree[node] = (a * b)% 1000000007;
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
		tree[node] = (a * tree[node * 2 + 1]) % 1000000007;
		return tree[node];
	}
	else if ((L + R) / 2 + 1 <= target && R >= target) {
		long long a;
		a = changetree((L + R) / 2 + 1, R, target, num, node * 2 + 1);
		tree[node] = (a * tree[node * 2]) % 1000000007;
		return tree[node];
	}
}

long long hap(int L, int R, int left, int right, int node) {
	if (L > right || R < left) {
		return 1;
	}
	if (left <= L && right >= R) {
		return tree[node];
	}
	else {
		return (hap(L, (L + R) / 2, left, right, node * 2) * hap((L + R) / 2 + 1, R, left, right, node * 2 + 1)) % 1000000007;
	}
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%lli", &arr[i]);
	}
	maketree(1, N, 1);
	int a,b,c;
	long long ans;
	for (int i = 1; i <= M+K; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a==1) {
			changetree(1, N, b, c, 1);
		}
		else {
			if (b > c) {
				ans = hap(1, N, c, b, 1);
				printf("%lli\n", ans);
			}
			else {
				ans = hap(1, N, b, c, 1);
				printf("%lli\n", ans);
			}
		}
		
	}
}