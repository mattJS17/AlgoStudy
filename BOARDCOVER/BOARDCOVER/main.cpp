//
//  main.cpp
//  BOARDCOVER
//
//  Created by ShimJaeHoon on 2018. 1. 10..
//  Copyright © 2018년 ShimJaeHoon. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int grid[20][20] = { 1, }; // 1 = full, 0 = empty
int h, w;

int block[4][3][2] = {
    { { 0, 0 },{ 0, 1 },{ 1, 0 } },
    { { 0, 0 },{ 0, 1 },{ 1, 1 } },
    { { 0, 0 },{ 1, 0 },{ 1, 1 } },
    { { 0, 0 },{ 1, 0 },{ 1, -1 } }
};

bool func2(int x, int y, int t, int c) {
    bool flag = true;
    
    for (int i = 0; i < 3; i++) { // 3 points in the block
        int xx = x + block[t][i][1];
        int yy = y + block[t][i][0];
        
        if (yy < 0 || yy >= h || xx < 0 || xx >= w) // out of bounds
            flag = false;
        if ((grid[yy][xx] += c) > 1) // already full
            flag = false;
    }
    
    return flag;
}

int func() {
    int x = -1;
    int y = -1;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!grid[i][j]) {
                y = i;
                x = j;
                goto Next;
            }
        }
    }
Next:
    if (y == -1)
        return 1;
    
    int ret = 0;
    
    for (int i = 0; i < 4; i++) { // 4 types of block
        if (func2(x, y, i, 1)) { // place block possible
            ret += func();
        }
        func2(x, y, i, -1);
    }
    
    return ret;
}

int main() {
    int freq;
    char temp;
    
    cin >> freq;
    
    for (; freq > 0; freq--) {
        cin >> h >> w;
        int cnt = 0;
        memset(grid, 1, sizeof(grid));
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> temp;
                if (temp == '#')
                    grid[i][j] = 1;
                else {
                    grid[i][j] = 0;
                    cnt++;
                }
            }
        }
        if (cnt % 3 != 0) {
            cout << 0 << endl;
        }
        else
            printf("%d\n", func());
    }
    
    return 0;
}
