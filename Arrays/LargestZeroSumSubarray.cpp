//LARGEST SUBARRAY WITH 0 SUM

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int findSubarray(vector<int> A){
    unordered_map<int, int> preSum;
    int i, sum = 0, maxlen = 0;
    for(i = 0; i < A.size(); i++){
        sum += A[i];

        if(A[i] == 0 && maxlen == 0)
            maxlen = 1;
        if(sum == 0)
            maxlen = i+1;
        if(preSum.find(sum) != preSum.end()){
            maxlen = maxlen > (i - preSum[sum]) ? maxlen : (i - preSum[sum]); 
        }
        else{
            preSum[sum] = i;
        }
    }
    return maxlen;
}

int main(){
    vector<int> A = { 15, -2, 2, -8, 1, 7, 10, 23 };
    cout<<"LENGTH OF LARGEST SUBARRAY WITH 0 SUM = " << findSubarray(A) << endl;
    return 0;
}