#include <iostream>
#include <cstring>
using namespace std;
int T, n, k, gn, hn;
char s[100010], t[100010];
bool fg[100010], fh[100010];
int main() {
	cin >> T;
	while (T--) {
		memset(t, '.', sizeof(t));
		memset(fg, true, sizeof(fg));
		memset(fh, true, sizeof(fh));
		cin >> n >> k;
		cin >> s;
		if (!k) {
			cout << n << '\n' << s << '\n';
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == 'G')	gn++, fg[i] = false;
			else	hn++, fh[i] = false;
		}
		int len = k * 2 + 1, ans = 0;
		for (int i = 0; i < n && gn; i++) {
			if (s[i] == 'G' && !fg[i]) {
				int l = i, r = min(i + len, n), mid = min(i + k, n - 1);
				t[mid] = 'G', ans++;
				for (int j = l; j < r; j++) {
					if (!fg[j])	gn--;
					fg[j] = true;
				}
			}
		}
		for (int i = 0; i < n && hn; i++) {
			if (s[i] == 'H' && !fh[i]) {
				int l = i, r = min(i + len, n), mid = min(i + k, n - 1), mcnt = 0;
				int _mid = mid;
				while (mid < 0 || mid >= n || t[mid] == 'G') {
					if (mcnt == 0)	mcnt++;
					else if (mcnt > 0)	mcnt = -mcnt;
					else	mcnt = (-mcnt) + 1;
					if (mcnt == k + 1) {
						l = i, r = min(i + len, n), mid = _mid;
						break;
					}
					mid = _mid + mcnt;
					l = max(mid - k, 0), r = min(mid + k, n);
				}
				t[mid] = 'H', ans++;
				for (int j = l; j < r; j++) {
					if (!fh[j])	hn--;
					fh[j] = true;
				}
			}
		}
		cout << ans << '\n'; 
		for (int i = 0; i < n; i++)	cout << t[i];
		cout << '\n';
	}
	return 0;
}
