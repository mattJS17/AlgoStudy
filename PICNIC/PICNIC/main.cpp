//
//  main.cpp
//  PICNIC
//
//  Created by ShimJaeHoon on 2018. 1. 8..
//  Copyright © 2018년 ShimJaeHoon. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

bool f[10][10] = {false,};
bool made[10] = {false,};
int n, m;

int func() {
    int first = -1;
    
    for (int i = 0; i<n; i++) {
        if (!made[i]) {
            first = i;
            break;
        }
    }
    
    if (first == -1) // 짝맺기 끝
        return 1;
    
    int sum = 0;
    
    for (int i = first+1; i<n; i++) {
        if (f[first][i] && !made[i]) {
            made[i] = made[first] = true;
            sum += func();
            made[i] = made[first] = false;
        }
    }
    
    return sum;
}

int main(int argc, const char * argv[]) {
    int freq;
    
    cin>>freq;
    
    while (freq>0) {
        memset(f, false, sizeof(f));
        memset(made, false, sizeof(made));
        
        int x, y;
        cin>>n>>m;
        
        for (int i = 0; i<m; i++) {
            cin>>x>>y;
            f[x][y]=f[y][x]=true;
        } // 친구 정보 입력받기
        
        cout<<func()<<endl;
        
        freq--;
    }
    
    return 0;
}
