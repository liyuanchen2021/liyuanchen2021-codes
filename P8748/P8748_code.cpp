#include <cstdio>
int main() {
	long long n;
	scanf("%lld", &n);
	n /= 1000;	//忽略不足1秒的毫秒数 
	printf("%02lld:%02lld:%02lld\n", n % 86400 / 3600, n % 3600 / 60, n % 60);
	return 0;
}
