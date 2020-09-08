//X^N in O(log N)

#include<iostream>
using namespace std;

long long int findPower(int X, int N){
    long long int res = 1;
    if(N == 0)
        return 1;
    res = findPower(X, N/2);
    if(N % 2 == 0)
        return (res * res);
    else 
        return(X * res * res);
}

int main(){
    int X = 5;
    int N = 4;
    cout<< findPower(X, N);
    return 0;
}