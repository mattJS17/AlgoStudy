//
//  main.cpp
//  TILING2
//
//  Created by ShimJaeHoon on 2018. 1. 17..
//  Copyright © 2018년 ShimJaeHoon. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int n;
int dp[101];

int func(int k) {
    if (dp[k] != -1)
        return dp[k];
    
    int& ret = dp[k];
    
    return ret = (func(k - 1) + func(k - 2)) % 1000000007;
}

int main() {
    int freq;
    
    cin >> freq;
    
    while (freq--) {
        cin >> n;
        
        memset(dp, -1, sizeof(dp));
        dp[1] = 1;
        dp[2] = 2;
        
        cout << func(n) << endl;
    }
    
    return 0;
}
