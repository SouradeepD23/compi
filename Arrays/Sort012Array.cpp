//SORT AN ARRAY OF 0s, 1s AND 2s

#include<iostream>
#include<vector>
using namespace std;

void displayArray(vector<int> A){
	for(int i = 0; i < A.size(); i++)
		cout<< A[i] << " ";
	cout<<endl;
}

void swap(int x, int y, vector<int> &A){
    int t;
    t = A[x];
    A[x] = A[y];
    A[y] = t;
}

vector<int> sort012Arr( vector<int> &A){
    int l = 0, m = 0, h = A.size()-1;
    while (m <= h)
    {
        if(A[m] == 0){
            swap(l, m, A);
            l++;
            m++;
        }
        else if(A[m] == 1)
            m++;
        else if(A[m] == 2){
            swap(m, h, A);
            h--;
        }
    }
    return A;
}

int main(){
    vector<int> A = {0,1,2,0,1,2};
    cout<< "ARRAY IS:" <<endl;
    displayArray(A);
    cout<< "SORTED ARRAY IS:" <<endl;
    displayArray(sort012Arr(A));
    return 0;
}

