//
//  main.cpp
//  LIS
//
//  Created by ShimJaeHoon on 2018. 1. 15..
//  Copyright © 2018년 ShimJaeHoon. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int arr[500];
int dp[500];

void func(int x) {
    int& ret = dp[x];
    
    if (x == -1)
        return;
    
    for (int i = x+1; i<n; i++) {
        if (arr[x] < arr[i]) {
            if (ret < dp[i])
                ret = dp[i];
        }
    }
    ret += 1;

    func(x-1);
}

int main(int argc, const char * argv[]) {
    int freq;
    
    cin >> freq;
    
    while (freq--) {
        cin >> n;
        
        memset(arr, 0, sizeof(arr));
        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i<n; i++)
            cin >> arr[i];
        
        func(n-1);

        cout << (*max_element(dp, dp+n))+1 << endl;
    }
    return 0;
}
