#include <bits/stdc++.h>

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; ++ i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}

// Author: Blurgy <gy@blurgy.xyz>
// Date:   Aug 16 2020