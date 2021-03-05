#include <stdio.h>
int count;
unsigned long long mod(unsigned long long a, unsigned long long b, unsigned long long c) {
	if (b == 1) {
		return a % c;
	}
	count++;

	if (b % 2 == 0) {
		unsigned long long h = mod(a, b / 2, c);
		return (h*h) % c;
	}
	else {
		return (mod(a, b - 1, c) * mod(a, 1, c)) % c;
	}
}

int main() {
	unsigned long long a, b, c;
	scanf("%llu%llu%llu", &a, &b, &c);
	unsigned long long d = mod(a, b, c);
	printf("%llu", d);
}

