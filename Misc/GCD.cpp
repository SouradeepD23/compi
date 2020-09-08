// FIND GCD OF N IN O(log N)
// EUCLID's ALGORITHM
// LCM * HCF = A * B

#include<iostream>
#include<cmath>

using namespace std;

int findGCD(int A, int B){
    if(B == 0)
        return A;
    return findGCD(B, A % B);
    
}

int main(){
    int A = 875, B = 700;
    cout << findGCD(A, B);
    return 0;
}