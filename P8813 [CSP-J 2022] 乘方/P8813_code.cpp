#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ll ans = pow(a, b);
    if (ans <= 0 || ans > 1000000000)   puts("-1");
    else    printf("%lld\n", ans);
    return 0;
}
