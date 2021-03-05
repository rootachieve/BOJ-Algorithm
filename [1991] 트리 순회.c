#include <stdio.h>
char tree[70000000];
int wher[30];
int N;

int main() {
	scanf("%d", &N);
	char a[5],b[5],c[5];
	int d;
	tree[1] = 'A';
	wher[1] = 1;
	for (int i = 1; i <= N; i++) {
		scanf("%s", &a);
		scanf("%s", &b);
		scanf("%s", &c);

		tree[(wher[(int)a[0] - 64]) * 2] = b[0];
		if(b[0]!='.') wher[(int)b[0] - 64] = wher[(int)a[0] - 64] * 2;

		tree[(wher[(int)a[0] - 64]) * 2 + 1] = c[0];
		if (c[0] != '.')wher[(int)c[0] - 64] = wher[(int)a[0] - 64] * 2 + 1;
	}

	Ftree(1);
	printf("\n");
	Mtree(1);
	printf("\n");
	Btree(1);
}

int Ftree(int now) {
	if (tree[now] == '.') {
		return;
	}

	printf("%c", tree[now]);
	Ftree(now * 2);
	Ftree(now * 2 + 1);
}

int Mtree(int now) {
	if (tree[now] == '.') {
		return;
	}
	Mtree(now * 2);
	printf("%c", tree[now]);
	Mtree(now * 2 + 1);
	
}

int Btree(int now) {
	if (tree[now] == '.') {
		return;
	}
	Btree(now * 2);
	Btree(now * 2 + 1);
	printf("%c", tree[now]);
}