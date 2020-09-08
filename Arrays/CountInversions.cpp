//COUNT NO. OF INVERSIONS IN AN ARRAY (MERGE SORT TECHNIQUE)
//INVERSION CONDITION : (a[i] > a[j]) && (i < j)

#include<iostream>
#include<vector>
using namespace std;


void displayArray(vector<int> A){
	for(int i = 0; i < A.size(); i++)
		cout<< A[i] << " ";
	cout<<endl;
}

int merge(vector<int> &A, int l, int m, int h){

    int invCount = 0;
    if(A.size() < 2)
        return 0;

    vector<int> L(m - l + 1);
    vector<int> R(h - m);

    int i, j, k;

    for(i=0; i < L.size(); i++)
        L[i] = A[l + i];

    // cout<< "L: ";
    // displayArray(L);

    for(j = 0; j < R.size(); j++)
        R[j] = A[m + 1 + j];
    
    // cout<< "R: ";
    // displayArray(R);

    i = 0;
    j = 0;
    k = l;

    while(i < L.size() && j < R.size()){
        if(L[i] > R[j])
            invCount += m - i + 1;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
            //inversionCount += m - i + 1;
        }
        k++;
    }

    while(i < L.size())
        A[k++] = L[i++];
    
    while(j < R.size())
        A[k++] = R[j++];
    
    // cout<< "A: ";
    // displayArray(A);

    return invCount;
}

int mergeSort(vector<int> &A, int l, int h){
    int invCount = 0;
    if(l < h){
        int m = l + (h-l)/2;
        invCount += mergeSort(A, l, m);
        invCount += mergeSort(A, m + 1, h);
        invCount += merge(A, l, m , h);
    }
    return invCount;
}

int main(){
    int invCount;
    vector<int> A =  { 1, 20, 6, 4, 5 };
    //vector<int> A =  {1, 20, 6, 7, 5, 8, 11, 13};
    cout<<"Original Array is:" <<endl;
    displayArray(A);
    invCount = mergeSort(A, 0, A.size()-1);
    cout<<"Sorted Array is:" <<endl;
    displayArray(A);
    cout<< "INVERSION COUNT = "<< invCount;
}