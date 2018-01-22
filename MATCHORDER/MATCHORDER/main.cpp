//
//  main.cpp
//  MATCHORDER
//
//  Created by ShimJaeHoon on 2018. 1. 22..
//  Copyright © 2018년 ShimJaeHoon. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> kor;
vector<int> rus;
int n;

int func() {
    multiset<int> rate(kor.begin(), kor.end());
    int cnt = 0;
    
    for (int i = 0; i<n; i++) {
        if (*(rate.rbegin()) < rus[i]) { // 최대값이 현재 rus비교 점수보다 작을 때 -> 노답
            rate.erase(rate.begin()); // 최소값 현재 rus와 매치시켜서 버림
        }
        else {
            rate.erase(rate.lower_bound(rus[i]));
            cnt++;
        }
    }
    
    return cnt;
}

int main(int argc, const char * argv[]) {
    int freq;
    
    cin >> freq;
    
    while(freq--) {
        cin >> n;
        kor.assign(n, 0);
        rus.assign(n, 0);
        for (int i = 0; i<n; i++)
            scanf("%d", &rus[i]);
        for (int i = 0; i<n; i++)
            scanf("%d", &kor[i]);
        cout << func() << endl;
    }
    
    return 0;
}
