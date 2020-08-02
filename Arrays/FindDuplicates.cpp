//FIND DUPLICATES IN AN ARRAY IN O(N) TIME AND O(1) SPACE
//ASSUMPTION : { 0 < A[i] < A.size() }

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

void findDuplicates(vector<int> A){
    int i;
    for (i=0; i < A.size() ; i++)
    {
        if(A[abs(A[i])] > 0)
            A[abs(A[i])] = -A[abs(A[i])];
        else
        {
            cout<< abs(A[i]) <<" ";
        }
        
    }
    
}

int main(){
    vector<int> A = {1,2,3,1,3,6,6};
    findDuplicates(A);
    return 0;
}