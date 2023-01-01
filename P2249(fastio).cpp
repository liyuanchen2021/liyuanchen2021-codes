#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, a[1000005], q;
inline int read() {
	int x = 0;
	bool flag = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')   flag = 0;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x<<1) + (x<<3) + c - '0';
		c = getchar();
	}
	return (flag ? x : ~(x-1));
}
int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)    a[i] = read();
    while (m--) {
        q = read();
        if (!binary_search(a + 1, a + n + 1, q)) printf("-1 ");
        else    printf("%d ", lower_bound(a + 1, a + n + 1, q) - a);
    }
    return 0;
}
