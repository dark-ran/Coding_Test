#include <iostream>
using namespace std;

int main() {
    int A, B, C, X, Reword;
    
    cin >> A >> B >> C;
    
    if(A == B && B == C)
        Reword = 10000 + A * 1000;
    else if(A == B || A == C)
        Reword = 1000 + A * 100;
    else if(B == C)
        Reword = 1000 + B * 100;
    else {
        if(A > B) X = A;
        else X = B;
        if(X < C) X = C;
        Reword = X * 100;
    }
    cout << Reword;
}