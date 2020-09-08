#include<iostream>
#include<vector>
using namespace std;

void displayArray(vector<int> A){
	for(int i = 0; i < A.size(); i++)
		cout<< A[i] << " ";
	cout<<endl;
}

void merge(vector<int> &A, int l, int m, int h){

    if(A.size() < 2)
        return;

    vector<int> L(m - l + 1);
    vector<int> R(h - m);

    int i, j, k;

    for(i=0; i < L.size(); i++)
        L[i] = A[l + i];

    cout<< "L: ";
    displayArray(L);

    for(j = 0; j < R.size(); j++)
        R[j] = A[m + 1 + j];
    
    cout<< "R: ";
    displayArray(R);

    i = 0;
    j = 0;
    k = l;

    while(i < L.size() && j < R.size()){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < L.size())
        A[k++] = L[i++];
    
    while(j < R.size())
        A[k++] = R[j++];
    
    cout<< "A: ";
    displayArray(A);
}

void mergeSort(vector<int> &A, int l, int h){
    if(l < h){
        int m = l + (h-l)/2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, h);
        merge(A, l, m , h);
    }
}

int main(){
    vector<int> A = {2,1};//{1, 20, 6, 7, 5, 8, 11, 13, 3, 2, 2};//{12, 11, 13, 6, 5, 7, 1};
    cout<<"Original Array is:" <<endl;
    displayArray(A);
    mergeSort(A, 0, A.size()-1);
    cout<<"Sorted Array is:" <<endl;
    displayArray(A);
}