#include<stdio.h>
long long n, start, end, M, N;
long long r, b, c;
long long tree[4000002];
long long a[4000002];
long long add(long long s, long long e, long long node) {
	if (s == e) {
		return tree[node] = a[s];
	}
	long long m = (s + e) / 2;
	return tree[node] = add(s, m, node * 2) + add(m + 1, e, node * 2 + 1);
}

long long sum(long long s, long long e, long long node, long long nodel, long long noder) {
	if (e<nodel || s>noder) {
		return 0;
	}
	if (s <= nodel && noder <= e) {
		return tree[node];
	}
	long long m = (noder + nodel) / 2;
	long long a = sum(s, e, node * 2, nodel, m) + sum(s, e, node * 2 + 1, m + 1, noder);
	return a;
}

long long change(long long s, long long e, long long node, long long data, long long set) {
	if (s == e && s == data) {
		long long befnode = tree[node];
		tree[node] = set;
		return set - befnode;
	}
	long long m = (s + e) / 2;
	if (m >= data) {

		long long befnode2 = tree[node];
		tree[node] += change(s, m, node * 2, data, set);
		return tree[node] - befnode2;
	}
	else {
		long long  befnode3 = tree[node];
		tree[node] += change(m + 1, e, node * 2 + 1, data, set);
		return tree[node] - befnode3;
	}
}

int main() {

	scanf("%lli%lli", &n, &M);
	add(1, n, 1);
	while ((M) > 0) {

		scanf("%lli%lli%lli", &r, &b, &c);
		if (r == 1) {
			change(1, n, 1, b, c);
			a[b] = c;
			M--;

		}
		else if (r == 0) {
			if (c > b) {
				printf("%lli\n", sum(b, c, 1, 1, n));
			}
			else {
				printf("%lli\n", sum(c, b, 1, 1, n));
			}
			M--;
		}
	}

}