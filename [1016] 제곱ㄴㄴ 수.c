#include <stdio.h>

long long min;
long long max;
int arr[1000010];
int arr2[1000010];
int main() {
	scanf("%lld%lld", &min, &max);
	for (long long i = 2; (i * i) <= max; i++) {

		if (arr2[i] == 0) {
			long long k = min;
			if (k % (i * i) != 0) {
				k += (i * i) - (k % (i * i));
				
			}
			k -= min;
			
			
			for (long long j = i * i; ;) {
				if (k<= 1000001) {
					arr[k] = 1;
				}
				k += i * i;
				if (j <= max - min) {
					arr2[j] = 1;
					j += i * i;
				}

				if (k > 1000001 && j > max - min) {
					break;
				}
			}
		}
	}
	int count=0;
	for (int i = 0; i <= max - min; i++) {
		if (arr[i] == 0) {
			count++;
		}
	}
	printf("%d",count);
}