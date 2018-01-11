//
//  main.cpp
//  JUMPGAME
//
//  Created by ShimJaeHoon on 2018. 1. 11..
//  Copyright © 2018년 ShimJaeHoon. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int grid[100][100];
int dp[100][100];
int n;

int func(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= n) // out of bounds
        return 0;
    
    if (grid[y][x] == 0) // reached the end
        return 1;
    
    int& ret = dp[y][x];
    
    if (ret != -1)
        return ret;
    
    return ret = (func(y+grid[y][x], x) || func(y, x+grid[y][x]));
}

int main(int argc, const char * argv[]) {
    int freq;
    
    cin >> freq;
    
    while (freq>0) {
        cin>>n;
        
        memset(grid, -1, sizeof(grid));
        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++)
                cin>>grid[i][j];
        }
        if (func(0, 0)>=1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        freq--;
    }
    
    return 0;
}
