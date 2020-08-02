//MAX SUM CONTIGUOUS SUB-ARRAY
//KADANE'S ALGO

#include<iostream>
#include<vector>
#include<climits>           // for INT_MIN
using namespace std;

int Kadane(vector<int> A){
    int meh = 0;            // meh : max ending here
    int msf = INT_MIN;      // msf : max so far
    for(int i = 0; i < A.size(); i++){
        meh = meh + A[i];
        if(meh < A[i])
            meh = A[i];
        if(msf < meh)
            msf = meh;
    }
    return msf;
}

int main(){
    vector<int> A = {-2,3,2,-1};
    cout<< Kadane(A);
    return 0;
}