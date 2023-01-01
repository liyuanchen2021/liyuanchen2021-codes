#include <cstdio>
int n, m, q, a[1000005];
int *l, *r, *mid;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)	scanf("%d", &a[i]);
	while (m--) {
		scanf("%d", &q);
		l = a + 1, r = a + n;
		while (l < r) {
			mid = a + ((l - a) + (r - a)) / 2;
			if (*mid >= q)	r = mid;
			else	l = mid + 1;
		}
		if (l == r && *l == q)	printf("%d ", l - a);
		else	printf("-1 "); 
	}
	return 0;
}
