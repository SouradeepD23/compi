//FIND REPEATING AND MISSING NUMBER IN AN ARRAY
// 1 < A[i] < N

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void displayArray(vector<int> A){
	for(int i = 0; i < A.size(); i++)
		cout<< A[i] << " ";
	cout<<endl;
}

void findRepeatingAndMissing( vector<int> &A){
    int n = A.size();
    int i;

    for(i = 0; i < n; i++){
        if(A[abs(A[i])-1] > 0)
            A[abs(A[i])-1] = -A[abs(A[i])-1];
        else
            cout<< "Repeating = "<< abs(A[i]) <<endl;
    }
    
    for(i=0; i < n; i++)
        if(A[i] > 0){
            cout<< "Missing = "<< i+1 <<endl;
            break;
        }
            
}

int main(){
    vector<int> A = {4,1,2,3,6,3};
    cout<< "ARRAY IS:" <<endl;
    displayArray(A);
    findRepeatingAndMissing(A);
    return 0;
}

