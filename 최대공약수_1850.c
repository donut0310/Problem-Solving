#include<stdio.h>

int func(long long a, long long b) {
	return (a % b == 0 ? b : func(b, a % b));
}

int main() {
	long long A, B;
	scanf("%lld%lld", &A, &B);

	for (int i = 0; i < func(A, B); ++i) {
		printf("1");
	}
}