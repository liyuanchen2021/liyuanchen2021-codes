#include <algorithm>
#include <iostream>
using namespace std;
int n, m, a[1000005];
int find(int l, int r, int k) {
	if (l <= r) {
		int m = (l + r) >> 1;
		if (k == a[m])	return m;
		else if (k < a[m])	return find(l, m - 1, k);
		else	return find(m + 1, r, k);
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> a[i];
	while (m--) {
		int k;
		cin >> k;
		if (find(0, n - 1, k) != -1)	cout << lower_bound(a, a + n, k) - a + 1;
		else	cout << -1;
		if (m > 0)	cout << " ";
	}
	return 0;
}
