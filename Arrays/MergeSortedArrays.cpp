//MERGE 2 SORTED ARRAYS WITHOUT EXTRA SPACE

#include<iostream>
#include<vector>
using namespace std;

void displayArray(vector<int> A){
	for(int i = 0; i < A.size(); i++)
		cout<< A[i] << " ";
	cout<<endl;
}

vector<int> mergeSortedArrays(vector<int> &A, vector<int> &B){
	int m = A.size(), n = B.size();
	int last, i ,j;
	for(i = n-1; i >= 0; i--){
		/* Find the smallest element greater than ar2[i]. Move all 
		elements one position ahead till the smallest greater 
		element is not found */
		last = A[m-1];
		for(j = m-2; j >= 0; j--){
			if(A[j] > B[i])
				A[j+1] = A[j];
			else
			break;
		}
		// If there was a greater element
		if(j != m-2 || last > B[i]){
			A[j+1] = B[i];
			B[i] = last;
		}
	}
	
	for(i=0; i<n; i++)
		A.push_back(B[i]);
	
	return A;
}

int main(){
	vector<int> A = {1, 5, 9, 10, 15, 20};
	vector<int> B = {2, 3, 8, 13};
	
	cout<<"ARRAY A IS:"<<endl;
	displayArray(A);
	
	cout<<"ARRAY B IS:"<<endl;
	displayArray(B);
	
	cout<<"MERGED ARRAY IS:"<<endl;
	displayArray(mergeSortedArrays(A, B));
}
