//
//  main.cpp
//  FENCE
//
//  Created by ShimJaeHoon on 2018. 2. 12..
//  Copyright © 2018년 ShimJaeHoon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> grid;

int func() {
    int max = -1;
    
    for (int i = 0; i<n; i++) {
        int cnt = 0;
        for (int j = i; j >=0; j--) {
            if (grid[j] >= grid[i]) {
                cnt++;
            }
            else
                break;
        }
        for (int k = i+1; k<n; k++) {
            if (grid[k] >= grid[i]) {
                cnt++;
            }
            else
                break;
        }
        cnt *= grid[i];
        if (max < cnt)
            max = cnt;
    }
    
    return max;
}

int main(int argc, const char * argv[]) {
    int C;
    
    cin >> C;
    
    while (C--) {
        cin >> n;
        
        grid.assign(n, 0);
        
        for (int i = 0; i<n; i++)
            scanf("%d", &grid[i]);
        
        cout << func() << endl;
    }
    
    return 0;
}
