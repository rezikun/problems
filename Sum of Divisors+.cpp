#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;



long long a[10000];
void div(long long n) {
    for (int i = 2; i < 1001 && i <= n; ++i) {
        int count = 0;
        while (n%i == 0 && n > 0) {
            ++count;
            n /= i;
        }
        a[i] = count;
    }
}
