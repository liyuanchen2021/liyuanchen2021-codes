#include <cstdio>
int T, n, maxn = 2, f[1000005];
int main() {
	scanf("%d", &T);
	f[1] = 1, f[2] = 2;	//初始化
	while (T--) {
		scanf("%d", &n);
		if (n > maxn) {
			for (int i = maxn + 1; i <= n; i++)	f[i] = (f[i - 1] + f[i - 2] + 1) % 9;	//递推
			maxn = n;	//更新 maxn 的值
		}
		printf("%d\n", f[n]);
	}
	return 0;
}
