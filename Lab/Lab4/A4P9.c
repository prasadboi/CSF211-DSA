#include <stdio.h>
#define N 1000
const long long int MOD = 1e9 + 7;

long long fact[N] = {1LL};
long long inv[N]  = {1LL};

int binPow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = (1LL * res * a);
        a = (1LL * a * a);
 
        n >>= 1;
    }
    return res;
}

int C(int n, int k) {
    if (k > n) return 0;

    int product = (1ll * fact[n] * inv[k]);
    product = (1LL * product * inv[n - k]);
    return product;
}

void binarySearch(int n, int pos, int *numBig, int *numSmol) {
    int l = 0, r = n, mid;

    while (l < r) {
        mid = (l + r) * 0.5f;

        if (pos >= mid) {
            if (pos != mid) (*numSmol)++;
            l = mid + 1;
        } else {
            (*numBig)++;
            r = mid;
        }
    }
}

int main() {
    int n, x, pos;
    scanf("%d %d %d", &n, &x, &pos);

    for (int i = 1; i <= n; ++i) {
        fact[i] = (1LL * fact[i - 1] * i);
        inv[i]  = binPow(fact[i], MOD - 2);
    }

    int Big = 0, Small = 0;

    binarySearch(n, pos, &Big, &Small);

    int other = (n - Big - Small - 1);
    int bigRange = n - x, smolRange = x - 1;

    int countBig  = (1LL * C(bigRange, Big) * fact[Big]);
    int countSmol = (1LL * C(smolRange, Small) * fact[Small]);

    int result = (1LL * countBig * countSmol);
    result = (1LL * result * fact[other]);

    long long  ans = 0;
    ans = (ans + result);

    printf("%lld", ans);

    return 0;
}