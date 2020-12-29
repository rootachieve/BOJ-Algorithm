#include<stdio.h>
int N;
int F[1000003];
char arr[1000003];
char find[1000003];

int findL[1000003];
int L;
int main() {
	do {
		scanf("%c", &find[L]);
		L++;
	} while (find[L - 1] != 10);

	do {
		scanf("%c", &arr[N]);
		N++;
	} while (arr[N - 1] != 10);
	N--;
	L--;

	int i = -1;
	int j = 0;
	F[j] = i;
	while (j <= N) {
		if (i == -1 || (i >= 0) && arr[i] == arr[j]) {
			j++;
			i++;
			F[j] = i;
		}
		else {
			i = F[i];
		}
	}
	int du=0;
	int findnum=0;
	for (int i = 0; i < L;) {
		for (int j = du; j < N; j++) {
			if (find[i + j] != arr[j]) {
				if (j != 0) {
					i += (j - F[j]);
					du = F[j];
					break;
				}
				else {
					i++;
					break;
				}
			}
			else if (j == N-1) {
				findnum++;
				findL[findnum] = i + 1;
				i += (j+1 - F[j+1]);
				du = F[j];
			}
			else if (i + j > L) {
				break;
			}
		}
	}

	printf("%d\n", findnum);
	for (int i = 1; findL[i] != 0; i++) {
		printf("%d ", findL[i]);
	}
}