//ROTATE MATRIX 90 DEGREE CLOCKWISE

#include<iostream>
#include<vector>
using namespace std;

void displayMatrix(vector< vector <int>> M){
	int i, j;
	int R = M.size();
	int C = M[0].size();
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			cout<<M[i][j]<<"	";
		}
		cout<<endl;
	}
}

void setMatrixZeroes(vector< vector <int>> &A){
	bool frow = false, fcol = false;
    int M = A.size(), N = A[0].size();
    int i, j;
    //Check 0 for 1st row
    for(i = 0; i < N; i++)
        if(A[0][i] == 0){
            frow = true;
            break;
        }
    
    //check 0 for 1st column
    for(i = 0; i < M; i++)
        if(A[i][0] == 0){
            fcol = true;
            break;
        }
    
    //Check for remaining entries and set in 1st row and 1st col
    for(i = 1; i < M; i++){
        for (j = 1; j < N; j++)
        {
            if(A[i][j] == 0){
                A[i][0] = 0;
                A[j][0] = 0;
            }
        }
    }

    //Set 0s for  all entries other than 1st row and 1st column
    for(i = 1; i < M; i++){
        for (j = 1; j < N; j++)
        {
            if(A[i][0] == 0 || A[0][j] == 0){
                A[i][j] = 0;
            }
        }
    }

    //Set 0 for 1st row
    if(frow == true){
        for(j = 0; j < N; j++){
            A[0][j] = 0;
        }
    }

    //Set 0 for 1st column
    if(fcol == true){
        for(i = 0; i < N; i++){
            A[i][0] = 0;
        }
    }
	
	cout<<"NEW MATRIX:"<<endl;
	displayMatrix(A);
	
}

int main(){
	vector< vector<int>> M = {
        {1,0,1},
        {0,1,1},
        {1,1,1}
    };
	cout<<"ORIGINAL MATRIX:"<<endl;
	displayMatrix(M);
	setMatrixZeroes(M);
	return 0;
}
