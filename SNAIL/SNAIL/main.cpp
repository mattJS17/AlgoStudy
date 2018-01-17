//
//  main.cpp
//  SNAIL
//
//  Created by ShimJaeHoon on 2018. 1. 17..
//  Copyright © 2018년 ShimJaeHoon. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int m, n;
double dp[1000][2001];

double func(int d, int c) {
    if (d == m) { // period end
        if (c >= n)
            return 1.0;
        else
            return 0.0;
    }
    
    double& ret = dp[d][c];
    if (ret != -1.0)
        return ret;
    
    return ret = ((0.25*func(d + 1, c + 1)) + (0.75*func(d + 1, c + 2)));
}

int main() {
    int freq;
    
    cin >> freq;
    
    while (freq--) {
        cin >> n >> m;
        
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 2001; j++) {
                dp[i][j] = -1.0;
            }
        }
        
        printf("%0.10lf\n", func(0, 0));
    }
    return 0;
}
