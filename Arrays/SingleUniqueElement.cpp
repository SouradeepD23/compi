//FIND SINGLE UNIQUE ELEMENT IN SORTED ARRAY WHERE ALL OTHER ELEMENTS OCCUR TWICE

#include<iostream>
#include<vector>

using namespace std;

int findUniqueElement(vector<int> A){
    int low = 0, mid, high = A.size()-1;
    //boundary checks
    if(high == 0)
        return A[0];
    if(A[0] != A[1])
        return A[0];
    if(A[high] != A[high-1])
        return A[high];

    while(low <= high){
        mid = low + (high - low)/2;

        //unique property
        if(A[mid] != A[mid+1] && A[mid] != A[mid-1])
            return A[mid];
        
        //pair index property and partition
        if((mid % 2 == 0 && A[mid] == A[mid+1]) || (mid % 2 == 1 && A[mid] == A[mid-1]))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> A = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout<< findUniqueElement(A);
    return 0;
}
