//
//  main.cpp
//  TRIANGLEPATH
//
//  Created by ShimJaeHoon on 2018. 1. 11..
//  Copyright © 2018년 ShimJaeHoon. All rights reserved.
//

#include <iostream>
#include <string.h>

int n;
int grid[100][100];
int dp[100][100];

using namespace std;

int func(int y, int x) {
    if (y == n-1)
        return grid[y][x];

    int& ret = dp[y][x];
    
    if (ret != -1) {
        return ret;
    }
    
    if (y <= n) {
        int a = grid[y][x] + func(y+1, x);
        int b = grid[y][x] + func(y+1, x+1);
        
        if (a>b)
            ret = a;
        else
            ret = b;
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    int freq;
    
    cin>>freq;
    
    while(freq>0) {
        cin>>n;
        
        memset(grid, 0, sizeof(grid));
        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<=i; j++) {
                cin>>grid[i][j];
            }
        }
        
        cout<<func(0, 0)<<endl;
        
        freq--;
    }
    
    return 0;
}
