#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
typedef long long ll;

ll n, l, c;

int main() {
    scanf("%lld %lld %lld", &n, &l, &c);
    ll ans = INF;
    for (ll k = (c + 1) / (l + 1); k > 0; k--) {
        if (k % 13 == 0) continue;
        ll r = n % k;
        if (r > 0) {
            if (r % 13 == 0 && r + 1 == k) r = 2;
            else r = 1;
        }
        ll temp = n / k + r;
        if (temp < ans) ans = temp;
    }
    printf("%lld\n", ans);
    return 0;
}