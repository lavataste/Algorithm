#include <stdio.h>
#define S(n) (((long long)(n))*((n)+1)/2)

long long Ans;
int T, N, K;

int main() {
    scanf("%d", &T); for(int t_i = 1; t_i <= T; printf("Case #%d\n%lld\n", t_i, Ans), t_i++) {
        int y = 0, x = 0; Ans = 1;
        scanf("%d%d", &N, &K); for(char str; K && scanf(" %c", &str); K--) {
            if('U' == str) y--; if('R' == str) x++; if('D' == str) y++; if('L' == str) x--;
            Ans += ((y+x < N) ? (S(y+x+1) - (((y+x)%2) ? x : y)) : ((long long)N*N - S(2*N-y-x-2) - N + 1 + (((y+x)%2) ? y : x)));
        }
    }
    return 0;
}
