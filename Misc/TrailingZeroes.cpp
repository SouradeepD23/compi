//TRAILING 0s IN FACTORIAL OF A NUMBER

#include<iostream>
#include<cmath>

using namespace std;

int findZeroes(int N){
    int p = 5, res = 0;
    while((N/p) > 0){
        res += N/p;
        p *= 5;
    }
    return res;
}

int main(){
    int N = 100;
    cout<< findZeroes(N) << endl;
    return 0;
}