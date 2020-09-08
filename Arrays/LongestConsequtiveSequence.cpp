/*

Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Examples:

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4   ---> Array {1,2,3,4}

*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findSequece (vector<int> A){
    unordered_set<int> S;
    int i, j, ans = 0;
    for(i = 0; i < A.size(); i++)
        S.insert(A[i]);
    for(i = 0; i < A.size(); i++){
        if(S.find(A[i] - 1) == S.end()){
            j = A[i];
            while(S.find(j) != S.end())
                j++;
            ans = (ans < j-A[i]) ? (j-A[i]) : ans;
        }
    }
    return ans;
}

int main(){
    vector<int> A = {1, 9, 3, 10, 4, 20, 2};
    cout<< "Longest Consequtive Sequence is of length: " << findSequece(A);
    return 0;
}