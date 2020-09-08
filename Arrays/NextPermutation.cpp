//FIND REPEATING AND MISSING NUMBER IN AN ARRAY
// 1 < A[i] < N

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void displayArray(vector<int> A){
	for(int i = 0; i < A.size(); i++)
		cout<< A[i] << " ";
	cout<<endl;
}

vector<int> nextPermutation( vector<int> &A){
    int n = A.size();
    int i, j, t;

    for(i = n-1; i > 0; i--){
        if(A[i] > A[i-1]){
            break;
        }
    }
    i--;
    if(i == -1){
        reverse(A.begin(), A.end());
        return A;
    }

    for(j = n-1; j > i; j--){
        if(A[j] > A[i]){
            t = A[i];
            A[i] = A[j];
            A[j] = t;
            break;
        }
    }

    reverse(A.begin() + i + 1, A.end());
    return A;       
}

int main(){
    vector<int> A = {1,2,7,9,8,4,1};
    cout<< "ARRAY IS:" <<endl;
    displayArray(A);
    displayArray(nextPermutation(A));
    return 0;
}

