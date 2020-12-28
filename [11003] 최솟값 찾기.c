#include<stdio.h>
int deque[2][5000001];
int number[5000001];
int z = -1;
int front;
int L;
int N;
int Fout() {
	if (z > -1) {
		z--;
		front++;
	}
}

int Bout() {
	if (z > -1) {
		z--;
	}
}

int Bin(int num,int i) {
	z++;
	deque[0][z + front] = num;
	deque[1][z + front] = i;
}
int main() {
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &number[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (z != -1) {
			while (z!=-1&&deque[0][z + front] > number[i]) {
				Bout();
			}
		}
		if (z!=-1&&deque[1][front] < i - L + 1) {
			Fout();
		}
		Bin(number[i], i);
		printf("%d ", deque[0][front]);
	}
}