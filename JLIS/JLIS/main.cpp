//
//  main.cpp
//  JLIS
//
//  Created by ShimJaeHoon on 2018. 1. 18..
//  Copyright © 2018년 ShimJaeHoon. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int n, m;
int a[101], b[101];
int dp[101][101];

int solve(int aPos, int bPos, int last) {
    if (aPos == n && bPos == m)
        return 0;
    
    int& ret = dp[aPos][bPos];
    if (ret != -1)
        return ret;
    
    for (int i = aPos; i<n; i++) {
        if (last < a[i])
            ret = max(ret, 1 + solve(i + 1, bPos, a[i]));
    }
    
    for (int i = bPos; i<m; i++) {
        if (last < b[i])
            ret = max(ret, 1 + solve(aPos, i + 1, b[i]));
    }
    
    return ret;
}

int main() {
    int C;
    
    cin >> C;
    
    while (C--) {
        cin >> n >> m;
        
        for (int i = 0; i<n; i++)
            cin >> a[i];
        for (int i = 0; i<m; i++)
            cin >> b[i];
        
        memset(dp, -1, sizeof(dp));
        
        printf("%d\n", solve(0, 0, INT_MIN));
    }
}
