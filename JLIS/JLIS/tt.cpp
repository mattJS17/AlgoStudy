#include <stdio.h>
#include <string.h>

int C,N;
int cache[101];

int solution(int x) {
    if (cache[x] != -1)
        return cache[x];
    
    return cache[x] = (solution(x - 1) + solution(x - 2)) % 1000000007;
}
int main() {
    
    scanf("%d", &C);
    
    while (C--) {
        memset(cache, -1, sizeof(cache));
        scanf("%d", &N);
        
        cache[1] = 1;
        cache[2] = 2;
        
        printf("%d\n", solution(N));
    }
    
    return 0;
}
