//
//  main.cpp
//  QUADTREE
//
//  Created by ShimJaeHoon on 2017. 7. 27..
//  Copyright © 2017년 ShimJaeHoon. All rights reserved.
//

#include <iostream>
using namespace std;

string func(string::iterator& it) {
    char h = *it;
    it++;
    
    if (h != 'x')
        return string(1, h);
    
    string first = func(it);
    string second = func(it);
    string third = func(it);
    string forth = func(it);
    
    return string("x")+third+forth+first+second;
}

int main(int argc, const char * argv[]) {
    string quad;
    int n;
    
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> quad;
        string::iterator it = quad.begin();
        string a = func(it);
        cout << a << endl;
    }
    
    return 0;
}

